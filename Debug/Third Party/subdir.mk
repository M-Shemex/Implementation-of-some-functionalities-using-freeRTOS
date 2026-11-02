################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Third\ Party/croutine.c \
../Third\ Party/event_groups.c \
../Third\ Party/list.c \
../Third\ Party/queue.c \
../Third\ Party/stream_buffer.c \
../Third\ Party/tasks.c \
../Third\ Party/timers.c 

OBJS += \
./Third\ Party/croutine.o \
./Third\ Party/event_groups.o \
./Third\ Party/list.o \
./Third\ Party/queue.o \
./Third\ Party/stream_buffer.o \
./Third\ Party/tasks.o \
./Third\ Party/timers.o 

C_DEPS += \
./Third\ Party/croutine.d \
./Third\ Party/event_groups.d \
./Third\ Party/list.d \
./Third\ Party/queue.d \
./Third\ Party/stream_buffer.d \
./Third\ Party/tasks.d \
./Third\ Party/timers.d 


# Each subdirectory must supply rules for building sources it contributes
Third\ Party/croutine.o: ../Third\ Party/croutine.c Third\ Party/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F103xB -c -I../Core/Inc -I"D:/RT LV/RTOS/Workspace/FreeRTOS/Third Party/portable/GCC/ARM_CM3" -I"D:/RT LV/RTOS/Workspace/FreeRTOS/Third Party/include" -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -I"D:/RT LV/RTOS/Workspace/FreeRTOS/Third Party" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"Third Party/croutine.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Third\ Party/event_groups.o: ../Third\ Party/event_groups.c Third\ Party/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F103xB -c -I../Core/Inc -I"D:/RT LV/RTOS/Workspace/FreeRTOS/Third Party/portable/GCC/ARM_CM3" -I"D:/RT LV/RTOS/Workspace/FreeRTOS/Third Party/include" -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -I"D:/RT LV/RTOS/Workspace/FreeRTOS/Third Party" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"Third Party/event_groups.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Third\ Party/list.o: ../Third\ Party/list.c Third\ Party/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F103xB -c -I../Core/Inc -I"D:/RT LV/RTOS/Workspace/FreeRTOS/Third Party/portable/GCC/ARM_CM3" -I"D:/RT LV/RTOS/Workspace/FreeRTOS/Third Party/include" -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -I"D:/RT LV/RTOS/Workspace/FreeRTOS/Third Party" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"Third Party/list.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Third\ Party/queue.o: ../Third\ Party/queue.c Third\ Party/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F103xB -c -I../Core/Inc -I"D:/RT LV/RTOS/Workspace/FreeRTOS/Third Party/portable/GCC/ARM_CM3" -I"D:/RT LV/RTOS/Workspace/FreeRTOS/Third Party/include" -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -I"D:/RT LV/RTOS/Workspace/FreeRTOS/Third Party" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"Third Party/queue.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Third\ Party/stream_buffer.o: ../Third\ Party/stream_buffer.c Third\ Party/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F103xB -c -I../Core/Inc -I"D:/RT LV/RTOS/Workspace/FreeRTOS/Third Party/portable/GCC/ARM_CM3" -I"D:/RT LV/RTOS/Workspace/FreeRTOS/Third Party/include" -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -I"D:/RT LV/RTOS/Workspace/FreeRTOS/Third Party" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"Third Party/stream_buffer.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Third\ Party/tasks.o: ../Third\ Party/tasks.c Third\ Party/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F103xB -c -I../Core/Inc -I"D:/RT LV/RTOS/Workspace/FreeRTOS/Third Party/portable/GCC/ARM_CM3" -I"D:/RT LV/RTOS/Workspace/FreeRTOS/Third Party/include" -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -I"D:/RT LV/RTOS/Workspace/FreeRTOS/Third Party" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"Third Party/tasks.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Third\ Party/timers.o: ../Third\ Party/timers.c Third\ Party/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F103xB -c -I../Core/Inc -I"D:/RT LV/RTOS/Workspace/FreeRTOS/Third Party/portable/GCC/ARM_CM3" -I"D:/RT LV/RTOS/Workspace/FreeRTOS/Third Party/include" -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -I"D:/RT LV/RTOS/Workspace/FreeRTOS/Third Party" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"Third Party/timers.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Third-20-Party

clean-Third-20-Party:
	-$(RM) ./Third\ Party/croutine.cyclo ./Third\ Party/croutine.d ./Third\ Party/croutine.o ./Third\ Party/croutine.su ./Third\ Party/event_groups.cyclo ./Third\ Party/event_groups.d ./Third\ Party/event_groups.o ./Third\ Party/event_groups.su ./Third\ Party/list.cyclo ./Third\ Party/list.d ./Third\ Party/list.o ./Third\ Party/list.su ./Third\ Party/queue.cyclo ./Third\ Party/queue.d ./Third\ Party/queue.o ./Third\ Party/queue.su ./Third\ Party/stream_buffer.cyclo ./Third\ Party/stream_buffer.d ./Third\ Party/stream_buffer.o ./Third\ Party/stream_buffer.su ./Third\ Party/tasks.cyclo ./Third\ Party/tasks.d ./Third\ Party/tasks.o ./Third\ Party/tasks.su ./Third\ Party/timers.cyclo ./Third\ Party/timers.d ./Third\ Party/timers.o ./Third\ Party/timers.su

.PHONY: clean-Third-20-Party

