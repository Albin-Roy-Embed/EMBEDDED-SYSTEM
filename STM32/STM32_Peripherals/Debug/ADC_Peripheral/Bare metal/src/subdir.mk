################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (14.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../ADC_Peripheral/Bare\ metal/src/ADC_Barematal.c 

OBJS += \
./ADC_Peripheral/Bare\ metal/src/ADC_Barematal.o 

C_DEPS += \
./ADC_Peripheral/Bare\ metal/src/ADC_Barematal.d 


# Each subdirectory must supply rules for building sources it contributes
ADC_Peripheral/Bare\ metal/src/ADC_Barematal.o: ../ADC_Peripheral/Bare\ metal/src/ADC_Barematal.c ADC_Peripheral/Bare\ metal/src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DNUCLEO_F401RE -DSTM32 -DSTM32F401RETx -DSTM32F4 -c -I../Inc -I"C:/Users/Albin Roy/Desktop/STM32/STM32_Peripherals/GPIO_Peripheral" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"ADC_Peripheral/Bare metal/src/ADC_Barematal.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-ADC_Peripheral-2f-Bare-20-metal-2f-src

clean-ADC_Peripheral-2f-Bare-20-metal-2f-src:
	-$(RM) ./ADC_Peripheral/Bare\ metal/src/ADC_Barematal.cyclo ./ADC_Peripheral/Bare\ metal/src/ADC_Barematal.d ./ADC_Peripheral/Bare\ metal/src/ADC_Barematal.o ./ADC_Peripheral/Bare\ metal/src/ADC_Barematal.su

.PHONY: clean-ADC_Peripheral-2f-Bare-20-metal-2f-src

