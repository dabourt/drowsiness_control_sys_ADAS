################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../ECU_Layer/GSM_800L/gsm_800l.c 

OBJS += \
./ECU_Layer/GSM_800L/gsm_800l.o 

C_DEPS += \
./ECU_Layer/GSM_800L/gsm_800l.d 


# Each subdirectory must supply rules for building sources it contributes
ECU_Layer/GSM_800L/%.o ECU_Layer/GSM_800L/%.su: ../ECU_Layer/GSM_800L/%.c ECU_Layer/GSM_800L/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F401xC -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-ECU_Layer-2f-GSM_800L

clean-ECU_Layer-2f-GSM_800L:
	-$(RM) ./ECU_Layer/GSM_800L/gsm_800l.d ./ECU_Layer/GSM_800L/gsm_800l.o ./ECU_Layer/GSM_800L/gsm_800l.su

.PHONY: clean-ECU_Layer-2f-GSM_800L

