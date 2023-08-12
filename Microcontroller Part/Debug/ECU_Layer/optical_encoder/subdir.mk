################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../ECU_Layer/optical_encoder/optical_encoder.c 

OBJS += \
./ECU_Layer/optical_encoder/optical_encoder.o 

C_DEPS += \
./ECU_Layer/optical_encoder/optical_encoder.d 


# Each subdirectory must supply rules for building sources it contributes
ECU_Layer/optical_encoder/%.o ECU_Layer/optical_encoder/%.su: ../ECU_Layer/optical_encoder/%.c ECU_Layer/optical_encoder/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F401xC -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-ECU_Layer-2f-optical_encoder

clean-ECU_Layer-2f-optical_encoder:
	-$(RM) ./ECU_Layer/optical_encoder/optical_encoder.d ./ECU_Layer/optical_encoder/optical_encoder.o ./ECU_Layer/optical_encoder/optical_encoder.su

.PHONY: clean-ECU_Layer-2f-optical_encoder

