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

/* ------------------------------------------------------------------------
 * Board identifier
 * ------------------------------------------------------------------------ */
#define TARGET_BOARD_IDENTIFIER "SPRF3"

/* ------------------------------------------------------------------------
 * LED
 * ------------------------------------------------------------------------ */
#define LED0_PIN PB3

/* ------------------------------------------------------------------------
 * Beeper
 * ------------------------------------------------------------------------ */
#define USE_BEEPER
#define BEEPER_PIN      PC15
#define BEEPER_INVERTED

/* ------------------------------------------------------------------------
 * External interrupts / gyro data-ready
 * ------------------------------------------------------------------------ */
#define USE_EXTI
#define USE_GYRO_EXTI
#define GYRO_1_EXTI_PIN PC13
#define USE_MPU_DATA_READY_SIGNAL
#define ENSURE_MPU_DATA_READY_IS_LOW

/* ------------------------------------------------------------------------
 * Gyro / accelerometer
 * ------------------------------------------------------------------------ */
#define USE_GYRO
#define USE_ACC
#define USE_GYRO_MPU6050
#define GYRO_1_ALIGN        CW270_DEG
#define USE_ACC_MPU6050

/* ------------------------------------------------------------------------
 * UART
 * ------------------------------------------------------------------------ */
#define USE_UART1
#define USE_UART2
#define USE_UART3
#define USE_SOFTSERIAL1
#define USE_SOFTSERIAL2
#define SERIAL_PORT_COUNT 5

#define SOFTSERIAL1_RX_PIN PB4
#define SOFTSERIAL1_TX_PIN PB5
#define SOFTSERIAL2_RX_PIN PB0
#define SOFTSERIAL2_TX_PIN PB1

#define USE_ESCSERIAL
#define ESCSERIAL_TIMER_TX_PIN PA0

#define UART1_TX_PIN PA9
#define UART1_RX_PIN PA10
#define UART2_TX_PIN PA14
#define UART2_RX_PIN PA15
#define UART3_TX_PIN PB10
#define UART3_RX_PIN PB11

/* ------------------------------------------------------------------------
 * I2C
 * ------------------------------------------------------------------------ */
#define USE_I2C
#define USE_I2C_DEVICE_1
#define I2C_DEVICE (I2CDEV_1)

/* ------------------------------------------------------------------------
 * SPI / ADC / default blackbox behavior
 * ------------------------------------------------------------------------ */
#define USE_SPI
#define USE_SPI_DEVICE_2
#define FLASH_CS_PIN       PB12
#define FLASH_SPI_INSTANCE SPI2

#define DEFAULT_VOLTAGE_METER_SOURCE VOLTAGE_METER_ADC
#define DEFAULT_CURRENT_METER_SOURCE CURRENT_METER_ADC
#define USE_ADC
#define ADC_INSTANCE       ADC2
#define VBAT_ADC_PIN       PA4
#define CURRENT_METER_ADC_PIN PA5
#define RSSI_ADC_PIN       PB2

#define ENABLE_BLACKBOX_LOGGING_ON_SPIFLASH_BY_DEFAULT
#define DEFAULT_RX_FEATURE FEATURE_RX_SERIAL
#define DEFAULT_FEATURES   (FEATURE_RSSI_ADC | FEATURE_TELEMETRY | FEATURE_DYNAMIC_FILTER)

#define USE_MSP_CURRENT_METER
#define REMAP_TIM17_DMA

/* ------------------------------------------------------------------------
 * SPRF3-specific features
 * ------------------------------------------------------------------------ */
#define USE_DSHOT
#define USE_DSHOT_TELEMETRY
#define USE_GYRO_DATA_ANALYSE
#define USE_RPM_FILTER

/* ------------------------------------------------------------------------
 * UART1 TX-DMA is not compatible with DSHOT
 * ------------------------------------------------------------------------ */
#undef USE_UART1_TX_DMA

/* ------------------------------------------------------------------------
 * IO ports
 * ------------------------------------------------------------------------ */
#define TARGET_IO_PORTA 0xffff
#define TARGET_IO_PORTB 0xffff
#define TARGET_IO_PORTC (BIT(13) | BIT(14) | BIT(15))
#define TARGET_IO_PORTF (BIT(0) | BIT(1) | BIT(3) | BIT(4))

/* ------------------------------------------------------------------------
 * Timers
 * ------------------------------------------------------------------------ */
#define USABLE_TIMER_CHANNEL_COUNT 17
#define USED_TIMERS (TIM_N(1) | TIM_N(2) | TIM_N(3) | TIM_N(4) | TIM_N(15) | TIM_N(16) | TIM_N(17))
