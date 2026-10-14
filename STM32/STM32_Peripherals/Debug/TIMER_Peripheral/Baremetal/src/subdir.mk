################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (14.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../TIMER_Peripheral/Baremetal/src/TIMERs_Baremetal.c 

OBJS += \
./TIMER_Peripheral/Baremetal/src/TIMERs_Baremetal.o 

C_DEPS += \
./TIMER_Peripheral/Baremetal/src/TIMERs_Baremetal.d 


# Each subdirectory must supply rules for building sources it contributes
TIMER_Peripheral/Baremetal/src/%.o TIMER_Peripheral/Baremetal/src/%.su TIMER_Peripheral/Baremetal/src/%.cyclo: ../TIMER_Peripheral/Baremetal/src/%.c TIMER_Peripheral/Baremetal/src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DNUCLEO_F401RE -DSTM32 -DSTM32F401RETx -DSTM32F4 -c -I../Inc -I"C:/Users/Albin Roy/Desktop/STM32/STM32_Peripherals/GPIO_Peripheral" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-TIMER_Peripheral-2f-Baremetal-2f-src

clean-TIMER_Peripheral-2f-Baremetal-2f-src:
	-$(RM) ./TIMER_Peripheral/Baremetal/src/TIMERs_Baremetal.cyclo ./TIMER_Peripheral/Baremetal/src/TIMERs_Baremetal.d ./TIMER_Peripheral/Baremetal/src/TIMERs_Baremetal.o ./TIMER_Peripheral/Baremetal/src/TIMERs_Baremetal.su

.PHONY: clean-TIMER_Peripheral-2f-Baremetal-2f-src

