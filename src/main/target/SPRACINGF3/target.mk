# Define the list of targets
F3_TARGETS += $(TARGET)

# Define the default features and target source files
FEATURES    = ONBOARDFLASH RPM_FILTER
TARGET_SRC  = drivers/accgyro/accgyro_mpu.c \
              drivers/accgyro/accgyro_mpu6050.c

FEATURE_CUT_LEVEL = 0
