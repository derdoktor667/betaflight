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

#if defined(STM32F303)
#define TARGET_BOARD_IDENTIFIER "SPR3"

#define USBD_PRODUCT_STRING     "Betaflight STM32F303"

#define USE_TARGET_CONFIG

#define USE_EXTI
#define USE_MPU_DATA_READY_SIGNAL
#define USE_GYRO_EXTI
#define USE_ESCSERIAL
#define USE_ACC
#define USE_GYRO
#define USE_GYRO_MPU6050
#define USE_ACC_MPU6050
#define GYRO_1_ALIGN CW270_DEG
#define USE_USB_DETECT
#define SERIAL_PORT_COUNT 5

#define LED0_PIN PB3

#define USE_BEEPER
#define BEEPER_PIN PC15
#define BEEPER_INVERTED

#define USE_I2C
#define USE_I2C_DEVICE_1
#define I2C_DEVICE (I2CDEV_1)

#define FLASH_CS_PIN PB12
#define FLASH_SPI_INSTANCE SPI2

#define USE_SPI
#define USE_SPI_DEVICE_2 // PB12,13,14,15 on AF5

#define USE_UART1
#define USE_UART2
#define USE_UART3

#define ESCSERIAL_TIMER_TX_PIN PA0 // (HARDARE=0,PPM)

#define UART1_TX_PIN PA9
#define UART1_RX_PIN PA10

#define UART2_TX_PIN PA14 // PA14 / SWCLK
#define UART2_RX_PIN PA15

#define UART3_TX_PIN PB10 // PB10 (AF7)
#define UART3_RX_PIN PB11 // PB11 (AF7)

#define USE_RX_CC2500_SPI_PA_LNA
#define USE_RX_CC2500_SPI_DIVERSITY

// IO - stm32f303cc in 48pin package
#define TARGET_IO_PORTA 0xffff
#define TARGET_IO_PORTB 0xffff
#define TARGET_IO_PORTC (BIT(13) | BIT(14) | BIT(15))
#define TARGET_IO_PORTF (BIT(0) | BIT(1) | BIT(3) | BIT(4))

#define USABLE_TIMER_CHANNEL_COUNT 17
#define USED_TIMERS (TIM_N(1) | TIM_N(2) | TIM_N(3) | TIM_N(4) | TIM_N(15) | TIM_N(16) | TIM_N(17))

#elif defined(STM32F405)
#define TARGET_BOARD_IDENTIFIER "S405"

#define USBD_PRODUCT_STRING     "Betaflight STM32F405"

#define USE_I2C_DEVICE_1
#define USE_I2C_DEVICE_2
#define USE_I2C_DEVICE_3

#define USE_UART1
#define USE_UART2
#define USE_UART3
#define USE_UART4
#define USE_UART5
#define USE_UART6

#define SERIAL_PORT_COUNT       (UNIFIED_SERIAL_PORT_COUNT + 6)

#define USE_INVERTER

#define USE_SPI_DEVICE_1
#define USE_SPI_DEVICE_2
#define USE_SPI_DEVICE_3

#define TARGET_IO_PORTA 0xffff
#define TARGET_IO_PORTB 0xffff
#define TARGET_IO_PORTC 0xffff
#define TARGET_IO_PORTD 0xffff
#define TARGET_IO_PORTE 0xffff
#define TARGET_IO_PORTF 0xffff

#elif defined(STM32F411)
#define TARGET_BOARD_IDENTIFIER "S411"

#define USBD_PRODUCT_STRING     "Betaflight STM32F411"

#define USE_I2C_DEVICE_1
#define USE_I2C_DEVICE_2
#define USE_I2C_DEVICE_3

#define USE_UART1
#define USE_UART2
#define USE_UART6

#define SERIAL_PORT_COUNT       (UNIFIED_SERIAL_PORT_COUNT + 3)

#define USE_INVERTER

#define USE_SPI_DEVICE_1
#define USE_SPI_DEVICE_2
#define USE_SPI_DEVICE_3

#define TARGET_IO_PORTA 0xffff
#define TARGET_IO_PORTB 0xffff
#define TARGET_IO_PORTC 0xffff
#define TARGET_IO_PORTD 0xffff
#define TARGET_IO_PORTE 0xffff

#elif defined(STM32F7X2)
#define TARGET_BOARD_IDENTIFIER "S7X2"

#define USBD_PRODUCT_STRING     "Betaflight STM32F7x2"

#define USE_I2C_DEVICE_1
#define USE_I2C_DEVICE_2
#define USE_I2C_DEVICE_3

#define USE_UART1
#define USE_UART2
#define USE_UART3
#define USE_UART4
#define USE_UART5
#define USE_UART6

#define SERIAL_PORT_COUNT       (UNIFIED_SERIAL_PORT_COUNT + 6) 

#define USE_SPI_DEVICE_1
#define USE_SPI_DEVICE_2
#define USE_SPI_DEVICE_3

#define TARGET_IO_PORTA 0xffff
#define TARGET_IO_PORTB 0xffff
#define TARGET_IO_PORTC 0xffff
#define TARGET_IO_PORTD 0xffff
#define TARGET_IO_PORTE 0xffff
#define TARGET_IO_PORTF 0xffff

#elif defined(STM32F745)
#define TARGET_BOARD_IDENTIFIER "S745"

#define USBD_PRODUCT_STRING     "Betaflight STM32F745"

#define USE_I2C_DEVICE_1
#define USE_I2C_DEVICE_2
#define USE_I2C_DEVICE_3
#define USE_I2C_DEVICE_4

#define USE_UART1
#define USE_UART2
#define USE_UART3
#define USE_UART4
#define USE_UART5
#define USE_UART6
#define USE_UART7
#define USE_UART8

#define SERIAL_PORT_COUNT       (UNIFIED_SERIAL_PORT_COUNT + 8)

#define USE_SPI_DEVICE_1
#define USE_SPI_DEVICE_2
#define USE_SPI_DEVICE_3
#define USE_SPI_DEVICE_4

#define TARGET_IO_PORTA 0xffff
#define TARGET_IO_PORTB 0xffff
#define TARGET_IO_PORTC 0xffff
#define TARGET_IO_PORTD 0xffff
#define TARGET_IO_PORTE 0xffff
#define TARGET_IO_PORTF 0xffff
#endif

// Treat the target as unified, and expect manufacturer id / board name
// to be supplied when the board is configured for the first time
#define USE_UNIFIED_TARGET

#if !defined(STM32F303)

#define USE_BEEPER

// MPU interrupt
#define USE_EXTI
#define USE_MPU_DATA_READY_SIGNAL
#define USE_GYRO_EXTI

#define USE_ACC
#define USE_GYRO

#define USE_ACC_MPU6500
#define USE_GYRO_MPU6500
#define USE_ACC_SPI_MPU6000
#define USE_GYRO_SPI_MPU6000
#define USE_ACC_SPI_MPU6500
#define USE_GYRO_SPI_MPU6500
#define USE_ACC_SPI_ICM20689
#define USE_GYRO_SPI_ICM20689
#define USE_ACCGYRO_LSM6DSO

#define USE_MAG
#define USE_MAG_DATA_READY_SIGNAL
#define USE_MAG_HMC5883
#define USE_MAG_SPI_HMC5883
#define USE_MAG_QMC5883
#define USE_MAG_LIS3MDL
#define USE_MAG_AK8963
#define USE_MAG_MPU925X_AK8963
#define USE_MAG_SPI_AK8963
#define USE_MAG_AK8975

#define USE_BARO
#define USE_BARO_MS5611
#define USE_BARO_SPI_MS5611
#define USE_BARO_BMP280
#define USE_BARO_SPI_BMP280
#define USE_BARO_BMP388
#define USE_BARO_SPI_BMP388
#define USE_BARO_LPS
#define USE_BARO_SPI_LPS
#define USE_BARO_QMP6988
#define USE_BARO_SPI_QMP6988
#define USE_BARO_DPS310
#define USE_BARO_SPI_DPS310

#define USE_SDCARD
#define USE_SDCARD_SPI
#define USE_SDCARD_SDIO

#define USE_FLASHFS
#define USE_FLASH_TOOLS
#define USE_FLASH_M25P16
#define USE_FLASH_W25N01G          // 1Gb NAND flash support
#define USE_FLASH_W25M             // Stacked die support
#define USE_FLASH_W25M512          // 512Kb (256Kb x 2 stacked) NOR flash support
#define USE_FLASH_W25M02G          // 2Gb (1Gb x 2 stacked) NAND flash support

#define USE_MAX7456

#define USE_VTX_RTC6705
#define USE_VTX_RTC6705_SOFTSPI

#define USE_TRANSPONDER

#define USE_RANGEFINDER
#define USE_RANGEFINDER_HCSR04
#define USE_RANGEFINDER_TF

#define USE_SPI
#define SPI_FULL_RECONFIGURABILITY

#define USE_I2C
#define I2C_FULL_RECONFIGURABILITY

#define USE_VCP

#define USE_SOFTSERIAL1
#define USE_SOFTSERIAL2

#define UNIFIED_SERIAL_PORT_COUNT       3

#define USE_USB_DETECT

#define USE_ESCSERIAL

#define USE_ADC

#define USE_RX_SPI

#define USE_RX_FRSKY_SPI_D
#define USE_RX_FRSKY_SPI_X
#define USE_RX_SFHSS_SPI
#define USE_RX_REDPINE_SPI
#define USE_RX_FRSKY_SPI_TELEMETRY
#define USE_RX_CC2500_SPI_PA_LNA
#define USE_RX_CC2500_SPI_DIVERSITY

#define USE_RX_FLYSKY
#define USE_RX_FLYSKY_SPI_LED

#define USE_RX_SPEKTRUM
#define USE_RX_SPEKTRUM_TELEMETRY

#define USE_CUSTOM_DEFAULTS

// Additional drivers included for targets with > 512KB of flash
#if (TARGET_FLASH_SIZE > 512)
#define USE_ACC_MPU6050
#define USE_GYRO_MPU6050
#define USE_ACCGYRO_BMI270

#define USE_BARO_BMP085
#endif
