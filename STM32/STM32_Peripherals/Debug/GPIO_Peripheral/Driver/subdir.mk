################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (14.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../GPIO_Peripheral/Driver/stm32f401re_gpio_driver.c 

OBJS += \
./GPIO_Peripheral/Driver/stm32f401re_gpio_driver.o 

C_DEPS += \
./GPIO_Peripheral/Driver/stm32f401re_gpio_driver.d 


# Each subdirectory must supply rules for building sources it contributes
GPIO_Peripheral/Driver/%.o GPIO_Peripheral/Driver/%.su GPIO_Peripheral/Driver/%.cyclo: ../GPIO_Peripheral/Driver/%.c GPIO_Peripheral/Driver/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DNUCLEO_F401RE -DSTM32 -DSTM32F401RETx -DSTM32F4 -c -I../Inc -I"C:/Users/Albin Roy/Desktop/STM32/STM32_Peripherals/GPIO_Peripheral" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-GPIO_Peripheral-2f-Driver

clean-GPIO_Peripheral-2f-Driver:
	-$(RM) ./GPIO_Peripheral/Driver/stm32f401re_gpio_driver.cyclo ./GPIO_Peripheral/Driver/stm32f401re_gpio_driver.d ./GPIO_Peripheral/Driver/stm32f401re_gpio_driver.o ./GPIO_Peripheral/Driver/stm32f401re_gpio_driver.su

.PHONY: clean-GPIO_Peripheral-2f-Driver

