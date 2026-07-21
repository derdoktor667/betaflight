
![Betaflight](docs/assets/images/bf_logo.png)

[![Build Status](https://travis-ci.com/betaflight/betaflight.svg?branch=master)](https://travis-ci.com/betaflight/betaflight)

Betaflight is flight controller software (firmware) used to fly multi-rotor craft and fixed wing craft.

This fork differs from Baseflight and Cleanflight in that it focuses on flight performance, leading-edge feature additions, and wide target support.

###  Special F3 Edition: RPM Filtering Support on STM32F3!

Unlike the official Betaflight releases starting from version 4.1 which dropped support for F3 flight controllers, **this customized version of Betaflight supports bidirectional DShot and RPM Filtering on STM32F3 based flight controllers (such as the SPRacingF3)!**

By removing bulky, unused features (such as Barometer, Magnetometer, and Rangefinder) from the firmware build, we have freed up enough flash space to fit high-performance flight dynamics and full RPM filtering capabilities onto F3 boards. See the section below on [Building for SPRacingF3 (SPRF3)](#building-for-spracingf3-sprf3) for more details.

### 🛠️ Custom SPRF3 / SPRACINGF3 SPI-Edition

We have further optimized this build specifically for **SPRF3** and **SPRACINGF3** targets to resolve hardware incompatibilities and maximize RAM/Flash headroom:

- **Functional SPI Bus:** Fixed legacy STM32F3 SPI driver compatibility issues (implemented F3-specific SPI clock calculations, resolved signature conflicts on `spiInitDevice`, and replaced stream-based DMA logic with F3-compatible channel mappings).
- **RAM & Flash Memory Safety:**
  - **OSD disabled** (`#undef USE_OSD`)
  - **Barometer disabled** (`#undef USE_BARO`)
  - **Magnetometer disabled** (`#undef USE_MAG`)
  - These strategic feature cuts dropped RAM usage from a critical **99.9%** to a stable **80.7%**, preventing run-time stack overflows.
- **Optimized FEATURE_CUT_LEVEL:** Increased feature cut level to `12` in `target.mk` to automatically prune non-essential software blocks.
- **Sensor Drivers:** Correctly included and linked the `mpu6050` gyro/acc drivers into the build.

