import pandas as pd
import numpy as np

# Read a chunk of the file for analysis
# The CSV has gyroADC[0,1,2]
try:
    df = pd.read_csv('flight_logs/BTFL_BLACKBOX_LOG_RoboCat270_20260715_193632.01.csv', 
                     usecols=['time (us)', 'gyroADC[0]', 'gyroADC[1]', 'gyroADC[2]'],
                     nrows=100000)
except ValueError as e:
    print(f"Error reading CSV: {e}")
    exit(1)

# Calculate sampling rate
# The Blackbox log indicates variable loop times, so take the mean
dt = np.mean(np.diff(df['time (us)'])) / 1e6
fs = 1 / dt
print(f"Estimated Sampling Rate: {fs:.2f} Hz")

# Perform FFT
for axis in ['gyroADC[0]', 'gyroADC[1]', 'gyroADC[2]']:
    data = df[axis].values
    
    # Detrend and window
    data = data - np.mean(data)
    window = np.hanning(len(data))
    data = data * window
    
    # RFFT
    fft_data = np.fft.rfft(data)
    freqs = np.fft.rfftfreq(len(data), d=dt)
    
    # Filter for > 20Hz
    mask = freqs > 20
    fft_data = fft_data[mask]
    freqs = freqs[mask]
    
    # Magnitude
    magnitudes = np.abs(fft_data)
    
    # Find significant peaks
    # We are looking for peaks well above the noise floor
    threshold = np.mean(magnitudes) * 5
    
    peaks = []
    for i in range(1, len(magnitudes) - 1):
        if magnitudes[i] > magnitudes[i-1] and magnitudes[i] > magnitudes[i+1] and magnitudes[i] > threshold:
            peaks.append((freqs[i], magnitudes[i]))
    
    # Sort by magnitude
    peaks.sort(key=lambda x: x[1], reverse=True)
    
    print(f"\nTop 5 peaks for {axis}:")
    for p in peaks[:5]:
        print(f"  {p[0]:.2f} Hz (Mag: {p[1]:.2f})")
