################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../RTE_Layer/Src/distance_measurment.c \
../RTE_Layer/Src/dma.c \
../RTE_Layer/Src/rte_layer.c \
../RTE_Layer/Src/rte_time.c \
../RTE_Layer/Src/usart.c \
../RTE_Layer/Src/usr_car_interface.c \
../RTE_Layer/Src/wheel_speed.c 

OBJS += \
./RTE_Layer/Src/distance_measurment.o \
./RTE_Layer/Src/dma.o \
./RTE_Layer/Src/rte_layer.o \
./RTE_Layer/Src/rte_time.o \
./RTE_Layer/Src/usart.o \
./RTE_Layer/Src/usr_car_interface.o \
./RTE_Layer/Src/wheel_speed.o 

C_DEPS += \
./RTE_Layer/Src/distance_measurment.d \
./RTE_Layer/Src/dma.d \
./RTE_Layer/Src/rte_layer.d \
./RTE_Layer/Src/rte_time.d \
./RTE_Layer/Src/usart.d \
./RTE_Layer/Src/usr_car_interface.d \
./RTE_Layer/Src/wheel_speed.d 


# Each subdirectory must supply rules for building sources it contributes
RTE_Layer/Src/%.o RTE_Layer/Src/%.su: ../RTE_Layer/Src/%.c RTE_Layer/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F401xC -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-RTE_Layer-2f-Src

clean-RTE_Layer-2f-Src:
	-$(RM) ./RTE_Layer/Src/distance_measurment.d ./RTE_Layer/Src/distance_measurment.o ./RTE_Layer/Src/distance_measurment.su ./RTE_Layer/Src/dma.d ./RTE_Layer/Src/dma.o ./RTE_Layer/Src/dma.su ./RTE_Layer/Src/rte_layer.d ./RTE_Layer/Src/rte_layer.o ./RTE_Layer/Src/rte_layer.su ./RTE_Layer/Src/rte_time.d ./RTE_Layer/Src/rte_time.o ./RTE_Layer/Src/rte_time.su ./RTE_Layer/Src/usart.d ./RTE_Layer/Src/usart.o ./RTE_Layer/Src/usart.su ./RTE_Layer/Src/usr_car_interface.d ./RTE_Layer/Src/usr_car_interface.o ./RTE_Layer/Src/usr_car_interface.su ./RTE_Layer/Src/wheel_speed.d ./RTE_Layer/Src/wheel_speed.o ./RTE_Layer/Src/wheel_speed.su

.PHONY: clean-RTE_Layer-2f-Src

