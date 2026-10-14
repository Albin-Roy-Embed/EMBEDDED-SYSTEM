################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (14.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../GPIO_Peripheral/Application/Blink.c 

OBJS += \
./GPIO_Peripheral/Application/Blink.o 

C_DEPS += \
./GPIO_Peripheral/Application/Blink.d 


# Each subdirectory must supply rules for building sources it contributes
GPIO_Peripheral/Application/%.o GPIO_Peripheral/Application/%.su GPIO_Peripheral/Application/%.cyclo: ../GPIO_Peripheral/Application/%.c GPIO_Peripheral/Application/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DNUCLEO_F401RE -DSTM32 -DSTM32F401RETx -DSTM32F4 -c -I../Inc -I"C:/Users/Albin Roy/Desktop/STM32/STM32_Peripherals/GPIO_Peripheral" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-GPIO_Peripheral-2f-Application

clean-GPIO_Peripheral-2f-Application:
	-$(RM) ./GPIO_Peripheral/Application/Blink.cyclo ./GPIO_Peripheral/Application/Blink.d ./GPIO_Peripheral/Application/Blink.o ./GPIO_Peripheral/Application/Blink.su

.PHONY: clean-GPIO_Peripheral-2f-Application

