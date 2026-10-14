################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (14.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../External_drivers/RTC_DS1307/src/DS1307.c 

OBJS += \
./External_drivers/RTC_DS1307/src/DS1307.o 

C_DEPS += \
./External_drivers/RTC_DS1307/src/DS1307.d 


# Each subdirectory must supply rules for building sources it contributes
External_drivers/RTC_DS1307/src/%.o External_drivers/RTC_DS1307/src/%.su External_drivers/RTC_DS1307/src/%.cyclo: ../External_drivers/RTC_DS1307/src/%.c External_drivers/RTC_DS1307/src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DNUCLEO_F401RE -DSTM32 -DSTM32F401RETx -DSTM32F4 -c -I"C:/Users/Albin Roy/Desktop/STM32/driver_dev/External_drivers/SSD1306_Display/inc" -I"C:/Users/Albin Roy/Desktop/STM32/driver_dev/External_drivers/SSD1306_Display/bitmaps" -I../Inc -I"C:/Users/Albin Roy/Desktop/STM32/driver_dev/External_drivers/RTC_DS1307/inc" -I"C:/Users/Albin Roy/Desktop/STM32/driver_dev/External_drivers/BMP280_Sensor/inc" -I"C:/Users/Albin Roy/Desktop/STM32/driver_dev/Core/Inc" -I"C:/Users/Albin Roy/Desktop/STM32/driver_dev/Examples/inc" -I"C:/Users/Albin Roy/Desktop/STM32/driver_dev/drivers/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=soft -mthumb -o "$@"

clean: clean-External_drivers-2f-RTC_DS1307-2f-src

clean-External_drivers-2f-RTC_DS1307-2f-src:
	-$(RM) ./External_drivers/RTC_DS1307/src/DS1307.cyclo ./External_drivers/RTC_DS1307/src/DS1307.d ./External_drivers/RTC_DS1307/src/DS1307.o ./External_drivers/RTC_DS1307/src/DS1307.su

.PHONY: clean-External_drivers-2f-RTC_DS1307-2f-src

