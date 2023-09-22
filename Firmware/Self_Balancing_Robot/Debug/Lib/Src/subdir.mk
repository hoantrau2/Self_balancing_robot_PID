################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Lib/Src/motor.c \
../Lib/Src/mpu6050.c 

OBJS += \
./Lib/Src/motor.o \
./Lib/Src/mpu6050.o 

C_DEPS += \
./Lib/Src/motor.d \
./Lib/Src/mpu6050.d 


# Each subdirectory must supply rules for building sources it contributes
Lib/Src/motor.o: ../Lib/Src/motor.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32F103xB -DDEBUG -c -I../Core/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -I"C:/Users/84935/Desktop/Self-Balancing-Robot/FW/Self_Balancing_Robot/Lib/Inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Lib/Src/motor.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Lib/Src/mpu6050.o: ../Lib/Src/mpu6050.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32F103xB -DDEBUG -c -I../Core/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -I"C:/Users/84935/Desktop/Self-Balancing-Robot/FW/Self_Balancing_Robot/Lib/Inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Lib/Src/mpu6050.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

