################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Applications_Layer/Robot_Car_Driver/rc_driver.c 

OBJS += \
./Applications_Layer/Robot_Car_Driver/rc_driver.o 

C_DEPS += \
./Applications_Layer/Robot_Car_Driver/rc_driver.d 


# Each subdirectory must supply rules for building sources it contributes
Applications_Layer/Robot_Car_Driver/%.o Applications_Layer/Robot_Car_Driver/%.su: ../Applications_Layer/Robot_Car_Driver/%.c Applications_Layer/Robot_Car_Driver/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F401xC -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Applications_Layer-2f-Robot_Car_Driver

clean-Applications_Layer-2f-Robot_Car_Driver:
	-$(RM) ./Applications_Layer/Robot_Car_Driver/rc_driver.d ./Applications_Layer/Robot_Car_Driver/rc_driver.o ./Applications_Layer/Robot_Car_Driver/rc_driver.su

.PHONY: clean-Applications_Layer-2f-Robot_Car_Driver

