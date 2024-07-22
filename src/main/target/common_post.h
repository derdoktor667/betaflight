/*
 * This file is part of Cleanflight and Betaflight.
 *
 * Cleanflight and Betaflight are free software. You can redistribute
 * this software and/or modify this software under the terms of the
 * GNU General Public License as published by the Free Software
 * Foundation, either version 3 of the License, or (at your option)
 * any later version.
 *
 * Cleanflight and Betaflight are distributed in the hope that they
 * will be useful, but WITHOUT ANY WARRANTY; without even the implied
 * warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See the GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this software.
 *
 * If not, see <http://www.gnu.org/licenses/>.
 */

// Touch up configuration

#pragma once

#include "build/version.h"

// Define USE_VTX_RTC6705 if USE_VTX_RTC6705_SOFTSPI is defined
#if defined(USE_VTX_RTC6705_SOFTSPI)
#define USE_VTX_RTC6705
#endif

// STM32F3 specific configurations
#ifdef STM32F3
// #undef USE_ESCSERIAL
#undef USE_BARO
#undef USE_RANGEFINDER
#endif

// DSHOT configurations
#ifndef USE_DSHOT
#undef USE_ESC_SENSOR
#endif

#ifndef USE_ESC_SENSOR
#undef USE_ESC_SENSOR_TELEMETRY
#endif

// I2C related configurations
#ifndef USE_I2C
#undef USE_I2C_OLED_DISPLAY
#undef USE_DASHBOARD
#else
#ifdef USE_DASHBOARD
#define USE_I2C_OLED_DISPLAY
#endif
#endif

// Barometer configurations depending on I2C
#if !defined(USE_I2C)
#ifdef USE_BARO_BMP280
#undef USE_BARO_BMP280
#endif
#ifdef USE_BARO_MS5611
#undef USE_BARO_MS5611
#endif
#endif

// Magnetometer configurations
#if !defined(USE_MAG)
#undef USE_MAG_DATA_READY_SIGNAL
#undef USE_MAG_HMC5883
#undef USE_MAG_SPI_HMC5883
#undef USE_MAG_QMC5883
#undef USE_MAG_LIS3MDL
#undef USE_MAG_AK8963
#undef USE_MAG_SPI_AK8963
#endif

// Vario configuration
#if !defined(USE_BARO) && !defined(USE_GPS)
#undef USE_VARIO
#endif

// Barometer End Of Conversion Pin configuration
#if defined(USE_BARO) && !defined(BARO_EOC_PIN)
#define BARO_EOC_PIN NONE
#endif

// Serial RX configurations
#if !defined(USE_SERIAL_RX)
#undef USE_SERIALRX_CRSF
#undef USE_SERIALRX_IBUS
#undef USE_SERIALRX_JETIEXBUS
#undef USE_SERIALRX_SBUS
#undef USE_SERIALRX_SPEKTRUM
#undef USE_SERIALRX_SUMD
#undef USE_SERIALRX_SUMH
#undef USE_SERIALRX_XBUS
#undef USE_SERIALRX_FPORT
#endif

// Telemetry configurations
#if !defined(USE_TELEMETRY)
#undef USE_CRSF_CMS_TELEMETRY
#undef USE_TELEMETRY_CRSF
#undef USE_TELEMETRY_GHST
#undef USE_TELEMETRY_FRSKY_HUB
#undef USE_TELEMETRY_HOTT
#undef USE_TELEMETRY_IBUS
#undef USE_TELEMETRY_IBUS_EXTENDED
#undef USE_TELEMETRY_JETIEXBUS
#undef USE_TELEMETRY_LTM
#undef USE_TELEMETRY_MAVLINK
#undef USE_TELEMETRY_SMARTPORT
#undef USE_TELEMETRY_SRXL
#undef USE_SERIALRX_FPORT
#endif

// Telemetry CRSF configurations
#if !defined(USE_SERIALRX_CRSF)
#undef USE_TELEMETRY_CRSF
#undef USE_CRSF_LINK_STATISTICS
#undef USE_CRSF_V3
#endif

#if !defined(USE_RX_EXPRESSLRS) && !defined(USE_SERIALRX_CRSF)
#undef USE_RX_RSSI_DBM
#endif

// Telemetry GHST configuration
#if !defined(USE_SERIALRX_GHST)
#undef USE_TELEMETRY_GHST
#endif

// CRSF CMS Telemetry configuration
#if !defined(USE_TELEMETRY_CRSF) || !defined(USE_CMS)
#undef USE_CRSF_CMS_TELEMETRY
#endif

// Telemetry JETIEXBUS configuration
#if !defined(USE_SERIALRX_JETIEXBUS)
#undef USE_TELEMETRY_JETIEXBUS
#endif

// Telemetry IBUS extended configuration
#if !defined(USE_TELEMETRY_IBUS)
#undef USE_TELEMETRY_IBUS_EXTENDED
#endif

// Spektrum configurations
#ifndef USE_SERIALRX_SPEKTRUM
#undef USE_SPEKTRUM_BIND
#undef USE_SPEKTRUM_BIND_PLUG
#undef USE_SPEKTRUM_REAL_RSSI
#undef USE_SPEKTRUM_FAKE_RSSI
#undef USE_SPEKTRUM_RSSI_PERCENT_CONVERSION
#undef USE_SPEKTRUM_VTX_CONTROL
#undef USE_SPEKTRUM_VTX_TELEMETRY
#undef USE_SPEKTRUM_CMS_TELEMETRY
#undef USE_TELEMETRY_SRXL
#endif

// SBUS Channels configuration
#if defined(USE_SERIALRX_SBUS) || defined(USE_SERIALRX_FPORT)
#define USE_SBUS_CHANNELS
#endif

// MSP Over Telemetry configuration
#if !defined(USE_TELEMETRY_SMARTPORT) && !defined(USE_TELEMETRY_CRSF)
#undef USE_MSP_OVER_TELEMETRY
#endif

// VTX configurations
#if !defined(USE_VTX_COMMON) || !defined(USE_VTX_CONTROL)
#undef USE_VTX_COMMON
#undef USE_VTX_CONTROL
#undef USE_VTX_TRAMP
#undef USE_VTX_SMARTAUDIO
#undef USE_VTX_TABLE
#endif

// RX configurations
#if defined(USE_RX_FRSKY_SPI_D) || defined(USE_RX_FRSKY_SPI_X) || defined(USE_RX_REDPINE_SPI)
#define USE_RX_CC2500
#define USE_RX_FRSKY_SPI
#endif

#if defined(USE_RX_SFHSS_SPI)
#define USE_RX_CC2500
#endif

#if !defined(USE_RX_CC2500)
#undef USE_RX_CC2500_SPI_PA_LNA
#endif

#if !defined(USE_RX_CC2500_SPI_PA_LNA)
#undef USE_RX_CC2500_SPI_DIVERSITY
#endif

// DSHOT DMAR configuration
#ifndef ENABLE_DSHOT_DMAR
#define ENABLE_DSHOT_DMAR DSHOT_DMAR_OFF
#endif

// ADC configurations
#ifndef USE_ADC
#undef USE_ADC_INTERNAL
#endif

// Flash configurations
#if defined(USE_FLASH_W25M512)
#define USE_FLASH_W25M
#define USE_FLASH_M25P16
#define USE_FLASH_W25M
#endif

#if defined(USE_FLASH_W25M02G)
#define USE_FLASH_W25N01G
#define USE_FLASH_W25M
#endif

#if defined(USE_FLASH_M25P16) || defined(USE_FLASH_W25N01G)
#define USE_FLASH_CHIP
#endif

#ifndef USE_FLASH_CHIP
#undef USE_FLASHFS
#endif

// USB MSC configurations
#if (!defined(USE_SDCARD) && !defined(USE_FLASHFS)) || !defined(USE_BLACKBOX)
#undef USE_USB_MSC
#endif

// SDCard configurations
#if !defined(USE_SDCARD)
#undef USE_SDCARD_SDIO
#undef USE_SDCARD_SPI
#endif

// USB VCP configurations
#if !defined(USE_VCP)
#undef USE_USB_CDC_HID
#undef USE_USB_MSC
#endif

#if defined(USE_USB_CDC_HID) || defined(USE_USB_MSC)
#define USE_USB_ADVANCED_PROFILES
#endif

// OSD configurations
#if defined(USE_MAX7456)
#define USE_OSD
#endif

#if !defined(USE_OSD)
#undef USE_RX_LINK_QUALITY_INFO
#undef USE_OSD_PROFILES
#undef USE_OSD_STICK_OVERLAY
#undef USE_RX_LINK_UPLINK_POWER
#endif

// GPS Rescue configuration
#if defined(USE_GPS_RESCUE)
#define USE_GPS
#endif

// Gyro configurations
#if defined(USE_GYRO_L3G4200D) || defined(USE_GYRO_MPU3050) || defined(USE_GYRO_MPU6000) || defined(USE_GYRO_MPU6050) || defined(USE_GYRO_MPU6500)
#define USE_I2C_GYRO
#endif

#if defined(USE_GYRO_SPI_ICM20689) || defined(USE_GYRO_SPI_MPU6000) || defined(USE_GYRO_SPI_MPU6500) || defined(USE_GYRO_SPI_MPU9250) || defined(USE_GYRO_L3GD20)
#define USE_SPI_GYRO
#endif

// CX10 configuration
#if defined(USE_RX_CX10)
#define USE_RX_XN297
#endif

// System HSE Value configuration
#if !defined(STM32F4) || defined(USE_UNIFIED_TARGET)
#define SYSTEM_HSE_VALUE 0
#else
#ifdef TARGET_XTAL_MHZ
#define SYSTEM_HSE_VALUE TARGET_XTAL_MHZ
#else
#define SYSTEM_HSE_VALUE (HSE_VALUE / 1000000U)
#endif
#endif // !STM32F4 || USE_UNIFIED_TARGET

// SPI Preinit configuration
#ifdef USE_SPI
#ifndef SPI_PREINIT_COUNT
#define SPI_PREINIT_COUNT 16 // 2 x 8 (GYROx2, BARO, MAG, MAX, FLASHx2, RX)
#endif
#endif

// Blackbox configuration
#ifndef USE_BLACKBOX
#undef USE_USB_MSC
#endif

// Persistent MSC RTC configuration
#if (!defined(USE_FLASHFS) || !defined(USE_RTC_TIME) || !defined(USE_USB_MSC) || !defined(USE_PERSISTENT_OBJECTS))
#undef USE_PERSISTENT_MSC_RTC
#endif

// Serial 4-way BLHeli configurations
#if !defined(USE_SERIAL_4WAY_BLHELI_BOOTLOADER) && !defined(USE_SERIAL_4WAY_SK_BOOTLOADER)
#undef USE_SERIAL_4WAY_BLHELI_INTERFACE
#elif !defined(USE_SERIAL_4WAY_BLHELI_INTERFACE) && (defined(USE_SERIAL_4WAY_BLHELI_BOOTLOADER) || defined(USE_SERIAL_4WAY_SK_BOOTLOADER))
#define USE_SERIAL_4WAY_BLHELI_INTERFACE
#endif

#if !defined(USE_PWM_OUTPUT)
#undef USE_SERIAL_4WAY_BLHELI_INTERFACE // implementation requires USE_PWM_OUTPUT to find motor outputs.
#endif

// LED Strip configurations
#if !defined(USE_LED_STRIP)
#undef USE_LED_STRIP_STATUS_MODE
#endif

#if defined(USE_LED_STRIP) && !defined(USE_LED_STRIP_STATUS_MODE)
#define USE_WS2811_SINGLE_COLOUR
#endif

// Simulator build configurations
#if defined(SIMULATOR_BUILD) || defined(UNIT_TEST)
// This feature uses 'arm_math.h', which does not exist for x86.
#undef USE_GYRO_DATA_ANALYSE
#endif

// CMS configurations
#ifndef USE_CMS
#undef USE_CMS_FAILSAFE_MENU
#endif

#ifndef USE_DSHOT
#undef USE_DSHOT_TELEMETRY
#undef USE_DSHOT_BITBANG
#endif

#ifndef USE_DSHOT_TELEMETRY
#undef USE_RPM_FILTER
#undef USE_DSHOT_TELEMETRY_STATS
#endif

// Board info configurations
#if !defined(USE_BOARD_INFO)
#undef USE_SIGNATURE
#endif

// ACC configurations
#if !defined(USE_ACC)
#undef USE_GPS_RESCUE
#undef USE_ACRO_TRAINER
#endif

#if (!defined(USE_GPS_RESCUE) || !defined(USE_CMS_FAILSAFE_MENU))
#undef USE_CMS_GPS_RESCUE_MENU
#endif

// Beeper configurations
#ifndef USE_BEEPER
#undef BEEPER_PIN
#undef BEEPER_PWM_HZ
#endif

// Timer DMA configurations
#if defined(USE_DSHOT) || defined(USE_LED_STRIP) || defined(USE_TRANSPONDER)
#define USE_TIMER_DMA
#else
#undef USE_DMA_SPEC
#endif

#if !defined(USE_DMA_SPEC)
#undef USE_TIMER_MGMT
#endif

#if defined(USE_TIMER_MGMT)
#undef USED_TIMERS
#else
#undef USE_UNIFIED_TARGET
#endif

// Rangefinder configurations
#if !defined(USE_RANGEFINDER)
#undef USE_RANGEFINDER_HCSR04
#undef USE_RANGEFINDER_SRF10
#undef USE_RANGEFINDER_HCSR04_I2C
#undef USE_RANGEFINDER_VL53L0X
#undef USE_RANGEFINDER_UIB
#undef USE_RANGEFINDER_TF
#endif

// GPS Rescue CMS configuration
#ifndef USE_GPS_RESCUE
#undef USE_CMS_GPS_RESCUE_MENU
#endif

// HAL support for ESCSERIAL on STM32F7
#ifdef STM32F7
#undef USE_ESCSERIAL
#endif

// Configuration storage
#if defined(CONFIG_IN_RAM) || defined(CONFIG_IN_FILE) || defined(CONFIG_IN_EXTERNAL_FLASH) || defined(CONFIG_IN_SDCARD)
#ifndef EEPROM_SIZE
#define EEPROM_SIZE 4096
#endif
extern uint8_t eepromData[EEPROM_SIZE];
#define __config_start (*eepromData)
#define __config_end (*ARRAYEND(eepromData))
#else
#ifndef CONFIG_IN_FLASH
#define CONFIG_IN_FLASH
#endif
extern uint8_t __config_start; // configured via linker script when building binaries.
extern uint8_t __config_end;
#endif

// Flash boot loader configuration
#if defined(USE_EXST) && !defined(RAMBASED)
#define USE_FLASH_BOOT_LOADER
#endif

// RPM filter configuration
#if !defined(USE_RPM_FILTER)
#undef USE_DYN_IDLE
#endif

// Iterm relax configuration
#ifndef USE_ITERM_RELAX
#undef USE_ABSOLUTE_CONTROL
#endif

// Custom defaults configuration
#if defined(USE_CUSTOM_DEFAULTS)
#define USE_CUSTOM_DEFAULTS_ADDRESS
#endif

// EXTI configurations
#if !defined(USE_EXTI)
#undef USE_RX_SPI
#undef USE_RANGEFINDER_HCSR04
#endif

// RX Bind configuration
#if defined(USE_RX_SPI) || defined(USE_SERIALRX_SRXL2)
#define USE_RX_BIND
#endif
#ifndef USE_GPS
#undef USE_GPS_PLUS_CODES
#endif
