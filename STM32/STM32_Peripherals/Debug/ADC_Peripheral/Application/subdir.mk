################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (14.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../ADC_Peripheral/Application/ADC_Driver_Application_LDR.c \
../ADC_Peripheral/Application/ADC_Driver_Application_LED.c 

OBJS += \
./ADC_Peripheral/Application/ADC_Driver_Application_LDR.o \
./ADC_Peripheral/Application/ADC_Driver_Application_LED.o 

C_DEPS += \
./ADC_Peripheral/Application/ADC_Driver_Application_LDR.d \
./ADC_Peripheral/Application/ADC_Driver_Application_LED.d 


# Each subdirectory must supply rules for building sources it contributes
ADC_Peripheral/Application/%.o ADC_Peripheral/Application/%.su ADC_Peripheral/Application/%.cyclo: ../ADC_Peripheral/Application/%.c ADC_Peripheral/Application/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DNUCLEO_F401RE -DSTM32 -DSTM32F401RETx -DSTM32F4 -c -I../Inc -I"C:/Users/Albin Roy/Desktop/STM32/STM32_Peripherals/GPIO_Peripheral" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-ADC_Peripheral-2f-Application

clean-ADC_Peripheral-2f-Application:
	-$(RM) ./ADC_Peripheral/Application/ADC_Driver_Application_LDR.cyclo ./ADC_Peripheral/Application/ADC_Driver_Application_LDR.d ./ADC_Peripheral/Application/ADC_Driver_Application_LDR.o ./ADC_Peripheral/Application/ADC_Driver_Application_LDR.su ./ADC_Peripheral/Application/ADC_Driver_Application_LED.cyclo ./ADC_Peripheral/Application/ADC_Driver_Application_LED.d ./ADC_Peripheral/Application/ADC_Driver_Application_LED.o ./ADC_Peripheral/Application/ADC_Driver_Application_LED.su

.PHONY: clean-ADC_Peripheral-2f-Application

