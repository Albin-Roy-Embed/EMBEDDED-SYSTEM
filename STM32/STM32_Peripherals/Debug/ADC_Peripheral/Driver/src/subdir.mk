################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (14.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../ADC_Peripheral/Driver/src/STM32F401RE_ADC_Driver.c 

OBJS += \
./ADC_Peripheral/Driver/src/STM32F401RE_ADC_Driver.o 

C_DEPS += \
./ADC_Peripheral/Driver/src/STM32F401RE_ADC_Driver.d 


# Each subdirectory must supply rules for building sources it contributes
ADC_Peripheral/Driver/src/%.o ADC_Peripheral/Driver/src/%.su ADC_Peripheral/Driver/src/%.cyclo: ../ADC_Peripheral/Driver/src/%.c ADC_Peripheral/Driver/src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DNUCLEO_F401RE -DSTM32 -DSTM32F401RETx -DSTM32F4 -c -I../Inc -I"C:/Users/Albin Roy/Desktop/STM32/STM32_Peripherals/GPIO_Peripheral" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-ADC_Peripheral-2f-Driver-2f-src

clean-ADC_Peripheral-2f-Driver-2f-src:
	-$(RM) ./ADC_Peripheral/Driver/src/STM32F401RE_ADC_Driver.cyclo ./ADC_Peripheral/Driver/src/STM32F401RE_ADC_Driver.d ./ADC_Peripheral/Driver/src/STM32F401RE_ADC_Driver.o ./ADC_Peripheral/Driver/src/STM32F401RE_ADC_Driver.su

.PHONY: clean-ADC_Peripheral-2f-Driver-2f-src

