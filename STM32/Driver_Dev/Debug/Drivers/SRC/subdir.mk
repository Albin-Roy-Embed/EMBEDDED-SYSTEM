################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/SRC/STM32F401_GPIO_Driver.c 

OBJS += \
./Drivers/SRC/STM32F401_GPIO_Driver.o 

C_DEPS += \
./Drivers/SRC/STM32F401_GPIO_Driver.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/SRC/STM32F401_GPIO_Driver.o: ../Drivers/SRC/STM32F401_GPIO_Driver.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DNUCLEO_F401RE -DSTM32 -DSTM32F401RETx -DSTM32F4 -c -I../Inc -I"C:/Users/admin/OneDrive/Desktop/EMBEDDED-SYSTEM/STM32/Driver_Dev/Drivers/INC" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Drivers/SRC/STM32F401_GPIO_Driver.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

