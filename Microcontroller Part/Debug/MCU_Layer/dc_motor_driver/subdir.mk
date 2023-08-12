################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../MCU_Layer/dc_motor_driver/dc_gpio.c \
../MCU_Layer/dc_motor_driver/dc_motor.c \
../MCU_Layer/dc_motor_driver/dc_timer.c 

OBJS += \
./MCU_Layer/dc_motor_driver/dc_gpio.o \
./MCU_Layer/dc_motor_driver/dc_motor.o \
./MCU_Layer/dc_motor_driver/dc_timer.o 

C_DEPS += \
./MCU_Layer/dc_motor_driver/dc_gpio.d \
./MCU_Layer/dc_motor_driver/dc_motor.d \
./MCU_Layer/dc_motor_driver/dc_timer.d 


# Each subdirectory must supply rules for building sources it contributes
MCU_Layer/dc_motor_driver/%.o MCU_Layer/dc_motor_driver/%.su: ../MCU_Layer/dc_motor_driver/%.c MCU_Layer/dc_motor_driver/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F401xC -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-MCU_Layer-2f-dc_motor_driver

clean-MCU_Layer-2f-dc_motor_driver:
	-$(RM) ./MCU_Layer/dc_motor_driver/dc_gpio.d ./MCU_Layer/dc_motor_driver/dc_gpio.o ./MCU_Layer/dc_motor_driver/dc_gpio.su ./MCU_Layer/dc_motor_driver/dc_motor.d ./MCU_Layer/dc_motor_driver/dc_motor.o ./MCU_Layer/dc_motor_driver/dc_motor.su ./MCU_Layer/dc_motor_driver/dc_timer.d ./MCU_Layer/dc_motor_driver/dc_timer.o ./MCU_Layer/dc_motor_driver/dc_timer.su

.PHONY: clean-MCU_Layer-2f-dc_motor_driver

