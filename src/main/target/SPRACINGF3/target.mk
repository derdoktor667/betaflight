F3_TARGETS += $(TARGET)

FEATURES    = ONBOARDFLASH
TARGET_SRC  = drivers/accgyro/accgyro_mpu.c

# Set FEATURE_CUT_LEVEL and TARGET_SRC based on TARGET
ifeq ($(TARGET), SPRF3)
    TARGET_SRC += drivers/accgyro/accgyro_mpu6050.c
    FEATURE_CUT_LEVEL = 0
else
    FEATURE_CUT_LEVEL = 6
    TARGET_SRC += \
        drivers/barometer/barometer_ms5611.c \
        drivers/barometer/barometer_bmp085.c \
        drivers/barometer/barometer_bmp280.c \
        drivers/compass/compass_ak8975.c \
        drivers/compass/compass_hmc5883l.c \
        drivers/compass/compass_qmc5883l.c
endif

# Further adjustments based on specific TARGET values
ifeq ($(TARGET), FLIP32F3OSD)
    FEATURE_CUT_LEVEL = 2
    TARGET_SRC += drivers/accgyro/accgyro_mpu6500.c
else ifeq ($(TARGET), ZCOREF3)
    FEATURE_CUT_LEVEL = 2
    TARGET_SRC += \
        drivers/accgyro/accgyro_mpu6500.c \
        drivers/accgyro/accgyro_spi_mpu6500.c
else ifeq ($(TARGET), IRCSYNERGYF3)
    FEATURE_CUT_LEVEL = 1
    TARGET_SRC += drivers/accgyro/accgyro_spi_mpu6000.c
endif
