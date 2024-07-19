#pragma once

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

// Board Identification
#if defined(RMDO)
    #define TARGET_BOARD_IDENTIFIER "RMDO"
#elif defined(ZCOREF3)
    #define TARGET_BOARD_IDENTIFIER "ZCF3"
#elif defined(FLIP32F3OSD)
    #define TARGET_BOARD_IDENTIFIER "FLF3"
#elif defined(IRCSYNERGYF3)
    #define TARGET_BOARD_IDENTIFIER "ISF3"
#elif defined(SPRF3)
    #define TARGET_BOARD_IDENTIFIER "SPRF3"
#else
    #define TARGET_BOARD_IDENTIFIER "SRF3"
#endif

// LED Configuration
#if defined(ZCOREF3)
    #define LED0_PIN PB8
#else
    #define LED0_PIN PB3
#endif

// Beeper Configuration
#if !defined(IRCSYNERGYF3)
    #define USE_BEEPER
    #define BEEPER_PIN PC15
    #define BEEPER_INVERTED
#endif

// External Interrupts Configuration
#define USE_EXTI
#define USE_GYRO_EXTI
#define GYRO_1_EXTI_PIN PC13
#define USE_MPU_DATA_READY_SIGNAL
#define ENSURE_MPU_DATA_READY_IS_LOW

// Sensor Configuration
#define USE_GYRO
#define USE_ACC
#define USE_BARO
#define USE_BARO_BMP280

#if defined(FLIP32F3OSD)
    #define USE_GYRO_MPU6500
    #define GYRO_1_ALIGN CW270_DEG
    #define USE_ACC_MPU6500
#elif defined(ZCOREF3)
    #define USE_GYRO_MPU6500
    #define USE_GYRO_SPI_MPU6500
    #define GYRO_1_ALIGN CW180_DEG
    #define USE_ACC_MPU6500
    #define USE_ACC_SPI_MPU6500
    #define USE_SPI_DEVICE_1
    #define SPI1_NSS_PIN PB9
    #define SPI1_SCK_PIN PB3
    #define SPI1_MISO_PIN PB4
    #define SPI1_MOSI_PIN PB5
    #define GYRO_1_CS_PIN PB9
    #define GYRO_1_SPI_INSTANCE SPI1
#elif defined(IRCSYNERGYF3)
    #define USE_GYRO_SPI_MPU6000
    #define GYRO_1_ALIGN CW270_DEG
    #define USE_ACC_SPI_MPU6000
    #define GYRO_1_CS_PIN PB12
    #define GYRO_1_SPI_INSTANCE SPI2
#else
    #define USE_GYRO_MPU6050
    #define GYRO_1_ALIGN CW270_DEG
    #define USE_ACC_MPU6050
#endif

// Rangefinder and Magnetometer Configuration
#if defined(FLIP32F3OSD)
    #define USE_RANGEFINDER
    #define USE_RANGEFINDER_HCSR04
    #define RANGEFINDER_HCSR04_TRIGGER_PIN PB0
    #define RANGEFINDER_HCSR04_ECHO_PIN PB1
#elif defined(ZCOREF3)
    #define USE_MAG_DATA_READY_SIGNAL
    #define ENSURE_MAG_DATA_READY_IS_HIGH
#else
    #define USE_RANGEFINDER
    #define USE_RANGEFINDER_HCSR04
    #define RANGEFINDER_HCSR04_TRIGGER_PIN PB0
    #define RANGEFINDER_HCSR04_ECHO_PIN PB1
    #define USE_MAG
    #define USE_MAG_AK8975
    #define USE_MAG_HMC5883
    #define USE_MAG_QMC5883
    #define MAG_HMC5883_ALIGN CW270_DEG
    #define USE_MAG_DATA_READY_SIGNAL
    #define ENSURE_MAG_DATA_READY_IS_HIGH
    #define MAG_INT_EXTI PC14
#endif

// Flash Memory Configuration
#if !defined(IRCSYNERGYF3)
    #define USE_FLASHFS
    #define USE_FLASH_M25P16
#endif

// UART Configuration
#define USE_UART1
#define USE_UART2
#define USE_UART3
#define USE_SOFTSERIAL1
#define USE_SOFTSERIAL2

#define SERIAL_PORT_COUNT 5

#if !defined(ZCOREF3)
    #define SOFTSERIAL1_RX_PIN PB4
    #define SOFTSERIAL1_TX_PIN PB5
    #define SOFTSERIAL2_RX_PIN PB0
    #define SOFTSERIAL2_TX_PIN PB1
#endif

// ESC Serial Configuration
#define USE_ESCSERIAL
#define ESCSERIAL_TIMER_TX_PIN PA0

// UART Pin Configuration
#define UART1_TX_PIN PA9
#define UART1_RX_PIN PA10
#define UART2_TX_PIN PA14
#define UART2_RX_PIN PA15
#define UART3_TX_PIN PB10
#define UART3_RX_PIN PB11

// I2C Configuration
#define USE_I2C
#define USE_I2C_DEVICE_1
#define I2C_DEVICE (I2CDEV_1)

// SPI Configuration
#define USE_SPI
#define USE_SPI_DEVICE_2

#if !defined(IRCSYNERGYF3)
    #define FLASH_CS_PIN PB12
    #define FLASH_SPI_INSTANCE SPI2
    #define DEFAULT_VOLTAGE_METER_SOURCE VOLTAGE_METER_ADC
    #define DEFAULT_CURRENT_METER_SOURCE CURRENT_METER_ADC
    #define USE_ADC
    #define ADC_INSTANCE ADC2
    #define VBAT_ADC_PIN PA4
    #define CURRENT_METER_ADC_PIN PA5
    #define RSSI_ADC_PIN PB2

    #if !defined(SPRF3)
        #define USE_OSD
        #define USE_OSD_OVER_MSP_DISPLAYPORT
        #define USE_SLOW_MSP_DISPLAYPORT_RATE_WHEN_UNARMED
    #endif
#endif

#define USE_MSP_CURRENT_METER
#define REMAP_TIM17_DMA

// SPRF3 Board Specific Configuration
#if defined(SPRF3)
    #undef USE_RANGEFINDER
    #undef USE_RANGEFINDER_HCSR04
    #undef RANGEFINDER_HCSR04_TRIGGER_PIN
    #undef RANGEFINDER_HCSR04_ECHO_PIN
    #undef RANGEFINDER_HCSR04_SOFTSERIAL2_EXCLUSIVE
    #undef USE_BARO
    #undef USE_BARO_MS5611
    #undef USE_BARO_BMP085
    #undef USE_BARO_BMP280
    #undef USE_MAG
    #undef USE_MAG_AK8975
    #undef USE_MAG_HMC5883
    #undef USE_MAG_QMC5883
    #undef MAG_HMC5883_ALIGN

    #define USE_DSHOT
    // #define DEFAULT_RX_FEATURE FEATURE_RX_SERIAL
#endif

// UART1 TX and DSHOT Compatibility
#if defined(USE_UART1_TX_DMA) && defined(USE_DSHOT)
    #undef USE_UART1_TX_DMA
#endif

#if !defined(IRCSYNERGYF3)
    #define ENABLE_BLACKBOX_LOGGING_ON_SPIFLASH_BY_DEFAULT
    #define DEFAULT_RX_FEATURE FEATURE_RX_SERIAL
    #define DEFAULT_FEATURES (FEATURE_RSSI_ADC | FEATURE_TELEMETRY)
#endif

// IO Port Configuration
#define TARGET_IO_PORTA 0xffff
#define TARGET_IO_PORTB 0xffff
#define TARGET_IO_PORTC (BIT(13) | BIT(14) | BIT(15))
#define TARGET_IO_PORTF (BIT(0) | BIT(1) | BIT(3) | BIT(4))

// Timer Configuration
#define USABLE_TIMER_CHANNEL_COUNT 17
#define USED_TIMERS (TIM_N(1) | TIM_N(2) | TIM_N(3) | TIM_N(4) | TIM_N(15) | TIM_N(16) | TIM_N(17))
