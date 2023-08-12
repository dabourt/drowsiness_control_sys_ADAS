################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../ECU_Layer/ultrasonic_sensor/ultrasonic_sensor.c 

OBJS += \
./ECU_Layer/ultrasonic_sensor/ultrasonic_sensor.o 

C_DEPS += \
./ECU_Layer/ultrasonic_sensor/ultrasonic_sensor.d 


# Each subdirectory must supply rules for building sources it contributes
ECU_Layer/ultrasonic_sensor/%.o ECU_Layer/ultrasonic_sensor/%.su: ../ECU_Layer/ultrasonic_sensor/%.c ECU_Layer/ultrasonic_sensor/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F401xC -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-ECU_Layer-2f-ultrasonic_sensor

clean-ECU_Layer-2f-ultrasonic_sensor:
	-$(RM) ./ECU_Layer/ultrasonic_sensor/ultrasonic_sensor.d ./ECU_Layer/ultrasonic_sensor/ultrasonic_sensor.o ./ECU_Layer/ultrasonic_sensor/ultrasonic_sensor.su

.PHONY: clean-ECU_Layer-2f-ultrasonic_sensor

