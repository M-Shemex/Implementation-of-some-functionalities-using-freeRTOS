################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Third\ Party/portable/MemMang/heap_4.c 

OBJS += \
./Third\ Party/portable/MemMang/heap_4.o 

C_DEPS += \
./Third\ Party/portable/MemMang/heap_4.d 


# Each subdirectory must supply rules for building sources it contributes
Third\ Party/portable/MemMang/heap_4.o: ../Third\ Party/portable/MemMang/heap_4.c Third\ Party/portable/MemMang/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F103xB -c -I../Core/Inc -I"D:/RT LV/RTOS/Workspace/FreeRTOS/Third Party/portable/GCC/ARM_CM3" -I"D:/RT LV/RTOS/Workspace/FreeRTOS/Third Party/include" -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -I"D:/RT LV/RTOS/Workspace/FreeRTOS/Third Party" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"Third Party/portable/MemMang/heap_4.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Third-20-Party-2f-portable-2f-MemMang

clean-Third-20-Party-2f-portable-2f-MemMang:
	-$(RM) ./Third\ Party/portable/MemMang/heap_4.cyclo ./Third\ Party/portable/MemMang/heap_4.d ./Third\ Party/portable/MemMang/heap_4.o ./Third\ Party/portable/MemMang/heap_4.su

.PHONY: clean-Third-20-Party-2f-portable-2f-MemMang

