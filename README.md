# 🚀 Betaflight Custom SPRF3 Edition

[![Betaflight](docs/assets/images/bf_logo.png)](https://betaflight.com/)

---

### 🏁 F3 Flight Controller - Reborn!

Official Betaflight development dropped support for F3 flight controllers. **This optimized, custom version brings them back to life!**

We have equipped classic F3 flight controllers (such as the **SPRacingF3**) with cutting-edge features that were originally reserved for F4/F7 boards, pushing the limits of the STM32F3 hardware.

---

## 🔥 Key Features

| Feature | Status | Benefit |
| :--- | :---: | :--- |
| **Bidirectional DShot** | ✅ | Real-time motor feedback |
| **RPM Filtering** | ✅ | Ultra-smooth flight performance |
| **Dynamic Notch Filter** | ✅ | Resonant noise elimination |
| **Overclocking** | ⚡ | More CPU power for F3 |

---

## 🛠️ High-Performance Technical Optimizations

We have optimized this firmware down to the byte level to achieve maximum performance within the tight constraints of the STM32F3 memory:

### ⚙️ RAM & Flash Memory Management
- **Aggressive Feature Cuts:** Removed unnecessary drivers (Barometer, Magnetometer, GPS-Rescue, OSD, etc.) to free up space.
- **Memory-optimized Filters:** Implemented specialized **`biquadDF2_t`** structures for static filters to save RAM, complementing the standard `biquadDF1_t` for dynamic applications.
- **Stability:** Successfully reduced critical RAM utilization from **99.9%** to a stable **~84%**.

### ⚡ Overclocking & Stability
- **Dynamic Overclocking:** Enabled (`USE_OVERCLOCK`) to push the STM32F3 clock frequency beyond standard limits for better PID loop performance.
- **Dynamic Flash Latency:** Implemented dynamic adjustment of Flash access times (**Wait States**) based on the overclocking level to prevent crashes and ensure system stability.

### 🔌 Hardware Fixes
- **Functional SPI Bus:** Implemented F3-specific SPI clock calculations and resolved DMA channel mappings to ensure robust communication with modern sensors.

---

## 🚀 Building for SPRacingF3 (SPRF3)

```bash
# Build firmware
make TARGET=SPRF3

# Clean
make clean TARGET=SPRF3
```

---
*Disclaimer: This firmware is a highly specialized version. Use at your own risk!*
