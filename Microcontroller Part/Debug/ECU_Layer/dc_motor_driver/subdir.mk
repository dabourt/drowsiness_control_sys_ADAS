################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../ECU_Layer/dc_motor_driver/dc_gpio.c \
../ECU_Layer/dc_motor_driver/dc_motor.c \
../ECU_Layer/dc_motor_driver/dc_timer.c 

OBJS += \
./ECU_Layer/dc_motor_driver/dc_gpio.o \
./ECU_Layer/dc_motor_driver/dc_motor.o \
./ECU_Layer/dc_motor_driver/dc_timer.o 

C_DEPS += \
./ECU_Layer/dc_motor_driver/dc_gpio.d \
./ECU_Layer/dc_motor_driver/dc_motor.d \
./ECU_Layer/dc_motor_driver/dc_timer.d 


# Each subdirectory must supply rules for building sources it contributes
ECU_Layer/dc_motor_driver/%.o ECU_Layer/dc_motor_driver/%.su: ../ECU_Layer/dc_motor_driver/%.c ECU_Layer/dc_motor_driver/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F401xC -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-ECU_Layer-2f-dc_motor_driver

clean-ECU_Layer-2f-dc_motor_driver:
	-$(RM) ./ECU_Layer/dc_motor_driver/dc_gpio.d ./ECU_Layer/dc_motor_driver/dc_gpio.o ./ECU_Layer/dc_motor_driver/dc_gpio.su ./ECU_Layer/dc_motor_driver/dc_motor.d ./ECU_Layer/dc_motor_driver/dc_motor.o ./ECU_Layer/dc_motor_driver/dc_motor.su ./ECU_Layer/dc_motor_driver/dc_timer.d ./ECU_Layer/dc_motor_driver/dc_timer.o ./ECU_Layer/dc_motor_driver/dc_timer.su

.PHONY: clean-ECU_Layer-2f-dc_motor_driver

