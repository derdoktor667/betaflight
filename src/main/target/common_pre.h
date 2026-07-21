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

#pragma once

/* ========================================================================= */
/* 1. Global Compiler & Debug Settings                                       */
/* ========================================================================= */
#define USE_PARAMETER_GROUPS
#pragma GCC diagnostic ignored "-Wsign-conversion"

#define I2C1_OVERCLOCK true
#define I2C2_OVERCLOCK true

/* ========================================================================= */
/* 2. MCU-Specific Basic Configuration                                       */
/* ========================================================================= */

#ifdef STM32F1
#define MINIMAL_CLI
#define USE_UART1_RX_DMA
#define USE_UART1_TX_DMA
#endif

#ifdef STM32F3
#define USE_ABSOLUTE_CONTROL
#define USE_ADC
#define USE_AIRMODE_LPF
#define USE_BATTERY_VOLTAGE_SAG_COMPENSATION
#define USE_BLACKBOX
#define USE_CCM_CODE
#define USE_CLI
#define USE_CLI_BATCH
#define USE_CUSTOM_BOX_NAMES
#define USE_CUSTOM_DEFAULTS_ADDRESS
#define USE_DMA
#define USE_D_MIN
#define USE_DSHOT
#define USE_DSHOT_DMAR
#define USE_DSHOT_TELEMETRY
#define USE_DSHOT_TELEMETRY_STATS
#define USE_DYN_IDLE
#define USE_DYN_LPF
#define USE_FLYSKY
#define USE_GYRO_DATA_ANALYSE
#define USE_GYRO_LPF2
#define USE_GYRO_OVERFLOW_CHECK
#define USE_HUFFMAN
#define USE_INTEGRATED_YAW_CONTROL
#define USE_INTERPOLATED_SP
#define USE_ITERM_RELAX
#define USE_LAUNCH_CONTROL
#define USE_LED_STRIP
#define USE_LED_STRIP_STATUS_MODE
#define USE_OVERCLOCK
#define USE_PERSISTENT_OBJECTS
#define USE_PERSISTENT_STATS
#define USE_PINIO
#define USE_PINIOBOX
#define USE_PROFILE_NAMES
#define USE_QUAD_MIXER_ONLY
#define USE_RC_SMOOTHING_FILTER
#define USE_RESOURCE_MGMT
#define USE_RPM_FILTER
#define USE_RUNAWAY_TAKEOFF
#define USE_RX_MSP_OVERRIDE
#define USE_SIGNATURE
#define USE_SIMPLIFIED_TUNING
#define USE_TELEMETRY
#define USE_TELEMETRY_IBUS
#define USE_THROTTLE_BOOST
#define USE_THRUST_LINEARIZATION
#define USE_TIMER_MGMT
#define USE_TPA_MODE
#define USE_USB_MSC
#define USE_VTX_TABLE
#define USE_YAW_SPIN_RECOVERY

#if !defined(USE_FRSKY) && !defined(USE_FLYSKY) && !defined(USE_SPEKTRUM) && !defined(USE_CRSF)
#define USE_FRSKY
#endif

#if defined(USE_FRSKY)
#define USE_SERIALRX_SBUS
#define USE_TELEMETRY_FRSKY_HUB
#define USE_TELEMETRY_SMARTPORT
#endif

#ifdef USE_SPEKTRUM
#define USE_SERIALRX_SPEKTRUM
#define USE_SERIALRX_SUMD
#define USE_TELEMETRY_SRXL
#endif

#ifdef USE_FLYSKY
#define USE_SERIALRX_IBUS
#define USE_TELEMETRY_IBUS
#define USE_TELEMETRY_IBUS_EXTENDED
#endif

#ifdef USE_CRSF
#define USE_SERIALRX_CRSF
#define USE_TELEMETRY_CRSF
#endif
#endif // STM32F3

#if defined(STM32F4) || defined(STM32F7) || defined(STM32H7) || defined(STM32G4)
#define USE_DSHOT
#define USE_DSHOT_BITBANG
#define USE_DSHOT_TELEMETRY
#define USE_DSHOT_TELEMETRY_STATS
#define USE_RPM_FILTER
#define USE_DYN_IDLE
#define USE_GYRO_DATA_ANALYSE
#define USE_ADC_INTERNAL
#define USE_USB_CDC_HID
#define USE_USB_MSC
#define USE_MCO
#define USE_DMA_SPEC
#define USE_TIMER_MGMT
#define USE_PERSISTENT_OBJECTS
#define USE_CUSTOM_DEFAULTS_ADDRESS
#define USE_SPI_TRANSACTION
#define I2C3_OVERCLOCK true

#if !defined(STM32G4)
#define USE_FAST_DATA
#endif

#if defined(STM32F7) || defined(STM32H7) || defined(STM32G4) || defined(STM32F40_41xxx) || defined(STM32F411xE)
#define USE_OVERCLOCK
#endif
#endif // High-Performance MCUs

#if defined(STM32F4) || defined(STM32F7) || defined(STM32H7)
#define TASK_GYROPID_DESIRED_PERIOD 125
#define SCHEDULER_DELAY_LIMIT 10
#else
#define TASK_GYROPID_DESIRED_PERIOD 1000
#define SCHEDULER_DELAY_LIMIT 100
#endif

#if (__FPU_PRESENT == 1) && (__FPU_USED == 1)
#define DEFAULT_AUX_CHANNEL_COUNT MAX_AUX_CHANNEL_COUNT
#else
#define DEFAULT_AUX_CHANNEL_COUNT 6
#endif

#if defined(USE_OVERCLOCK) && defined(STM32F411xE)
#define DEFAULT_CPU_OVERCLOCK 1
#else
#define DEFAULT_CPU_OVERCLOCK 0
#endif

/* ========================================================================= */
/* 3. Memory & RAM Utility Macros                                            */
/* ========================================================================= */

#ifdef USE_ITCM_RAM
#define FAST_CODE __attribute__((section(".tcm_code")))
#define FAST_CODE_NOINLINE NOINLINE
#else
#define FAST_CODE
#define FAST_CODE_NOINLINE
#endif

#ifdef USE_CCM_CODE
#define CCM_CODE __attribute__((section(".ccm_code")))
#else
#define CCM_CODE
#endif

#ifdef USE_FAST_RAM
#define FAST_RAM_ZERO_INIT __attribute__((section(".fastram_bss"), aligned(4)))
#define FAST_RAM __attribute__((section(".fastram_data"), aligned(4)))
#else
#define FAST_RAM_ZERO_INIT
#define FAST_RAM
#endif

#if defined(STM32F4) || defined(STM32H7)
#define PERSISTENT __attribute__((section(".persistent_data"), aligned(4)))
#endif

#ifdef USE_SRAM2
#define SRAM2 __attribute__((section(".sram2"), aligned(4)))
#else
#define SRAM2
#endif

#ifdef USE_DMA_RAM
#if defined(STM32H7)
#define DMA_RAM __attribute__((section(".DMA_RAM")))
#define DMA_RW_AXI __attribute__((section(".DMA_RW_AXI")))
extern uint8_t _dmaram_start__;
extern uint8_t _dmaram_end__;
#elif defined(STM32G4)
#define DMA_RAM_R __attribute__((section(".DMA_RAM_R")))
#define DMA_RAM_W __attribute__((section(".DMA_RAM_W")))
#define DMA_RAM_RW __attribute__((section(".DMA_RAM_RW")))
#endif
#else
#define DMA_RAM
#define DMA_RW_AXI
#define DMA_RAM_R
#define DMA_RAM_W
#define DMA_RAM_RW
#endif

/* ========================================================================= */
/* 4. Feature Set Definitions                                                */
/* ========================================================================= */

#define USE_MOTOR
#define USE_PWM_OUTPUT
#define USE_DMA
#define USE_TIMER
#define USE_BRUSHED_ESC_AUTODETECT
#define USE_SERIAL_PASSTHROUGH
#define USE_GYRO_REGISTER_DUMP
#define USE_PPM
#define USE_SERIALRX_IBUS
#define USE_CLI
#define USE_TASK_STATISTICS
#define USE_IMU_CALC
#define USE_SERIAL_RX

#if (TARGET_FLASH_SIZE > 128)
#define PID_PROFILE_COUNT 2
#define CONTROL_RATE_PROFILE_COUNT 3
#else
#define PID_PROFILE_COUNT 2
#define CONTROL_RATE_PROFILE_COUNT 3
#endif

#if ((FLASH_SIZE > 64) || (FEATURE_CUT_LEVEL < 12))
#define USE_INTERPOLATED_SP
#define USE_ABSOLUTE_CONTROL
#define USE_THROTTLE_BOOST
#define USE_BLACKBOX
#define USE_CLI_BATCH
#define USE_RESOURCE_MGMT
#define USE_RUNAWAY_TAKEOFF
#define USE_TELEMETRY
#endif

#if ((TARGET_FLASH_SIZE > 128) || (FEATURE_CUT_LEVEL < 12))
#define USE_GYRO_OVERFLOW_CHECK
#define USE_YAW_SPIN_RECOVERY
#define USE_DSHOT_DMAR
#endif

#if ((TARGET_FLASH_SIZE > 256) || (FEATURE_CUT_LEVEL < 12))
#define USE_LED_STRIP
#define USE_GYRO_LPF2
#define USE_DYN_LPF
#define USE_D_MIN
#define USE_THROTTLE_BOOST
#define USE_ITERM_RELAX
#define USE_RC_SMOOTHING_FILTER
#define USE_TPA_MODE
#endif

#if ((TARGET_FLASH_SIZE > 256) || (FEATURE_CUT_LEVEL < 10))
#define USE_VIRTUAL_CURRENT_METER
#define USE_SERIAL_4WAY_BLHELI_BOOTLOADER
#define USE_RCDEVICE
#endif

#if ((TARGET_FLASH_SIZE > 256) || (FEATURE_CUT_LEVEL < 9))
#define USE_GYRO_LPF2
#endif

#if ((TARGET_FLASH_SIZE > 256) || (FEATURE_CUT_LEVEL < 8))
#define USE_LAUNCH_CONTROL
#define USE_DYN_LPF
#define USE_D_MIN
#endif

#if ((TARGET_FLASH_SIZE > 256) || (FEATURE_CUT_LEVEL < 7))
#define USE_THROTTLE_BOOST
#define USE_INTEGRATED_YAW_CONTROL
#endif

#if ((TARGET_FLASH_SIZE > 256) || (FEATURE_CUT_LEVEL < 6))
#define USE_ITERM_RELAX
#define USE_RC_SMOOTHING_FILTER
#define USE_THRUST_LINEARIZATION
#define USE_TPA_MODE
#endif

#if ((FLASH_SIZE > 256) || (FEATURE_CUT_LEVEL < 5))
#define USE_ESC_SENSOR
#define USE_PWM
#define USE_VIRTUAL_CURRENT_METER
#endif

#if ((TARGET_FLASH_SIZE > 256) || (FEATURE_CUT_LEVEL < 4))
#define USE_HUFFMAN
#define USE_PINIO
#define USE_PINIOBOX
#define USE_LAUNCH_CONTROL
#endif

#if ((TARGET_FLASH_SIZE > 256) || (FEATURE_CUT_LEVEL < 3))
#ifdef USE_SERIALRX_SPEKTRUM
#define USE_SPEKTRUM_BIND
#define USE_SPEKTRUM_BIND_PLUG
#define USE_SPEKTRUM_REAL_RSSI
#define USE_SPEKTRUM_FAKE_RSSI
#define USE_SPEKTRUM_RSSI_PERCENT_CONVERSION
#define USE_SPEKTRUM_VTX_CONTROL
#define USE_SPEKTRUM_VTX_TELEMETRY
#define USE_SPEKTRUM_CMS_TELEMETRY
#define USE_PIN_PULL_UP_DOWN
#endif
#endif

#if ((FLASH_SIZE > 256) || (FEATURE_CUT_LEVEL < 1))
#define USE_BOARD_INFO
#define USE_RX_MSP
#define USE_ESC_SENSOR_INFO
#define USE_RX_RSSI_DBM
#endif

#if ((TARGET_FLASH_SIZE > 256) || (FEATURE_CUT_LEVEL == 0))
#define USE_AIRMODE_LPF
#define USE_CANVAS
#define USE_DSHOT_DMAR
#define USE_OSD
#define USE_OSD_OVER_MSP_DISPLAYPORT
#define USE_OSD_ADJUSTMENTS
#define USE_SENSOR_NAMES
#define USE_TELEMETRY_IBUS
#define USE_TELEMETRY_IBUS_EXTENDED
#define USE_SIGNATURE
#define USE_ABSOLUTE_CONTROL
#define USE_LED_STRIP_STATUS_MODE
#define USE_RX_LINK_QUALITY_INFO
#define USE_ESC_SENSOR_TELEMETRY
#define USE_OSD_PROFILES
#define USE_OSD_STICK_OVERLAY
#define USE_ESCSERIAL_SIMONK
#define USE_SERIAL_4WAY_SK_BOOTLOADER
#define USE_TELEMETRY_SENSORS_DISABLED_DETAILS
#define USE_VTX_TABLE
#define USE_PERSISTENT_STATS
#define USE_PROFILE_NAMES
#define USE_INTERPOLATED_SP
#define USE_CUSTOM_BOX_NAMES
#define USE_BATTERY_VOLTAGE_SAG_COMPENSATION
#define USE_RX_MSP_OVERRIDE
#define USE_SIMPLIFIED_TUNING
#endif
