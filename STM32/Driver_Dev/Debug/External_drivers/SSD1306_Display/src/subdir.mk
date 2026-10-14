################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (14.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../External_drivers/SSD1306_Display/src/SSD1306.c \
../External_drivers/SSD1306_Display/src/SSD1306_Graphics.c 

OBJS += \
./External_drivers/SSD1306_Display/src/SSD1306.o \
./External_drivers/SSD1306_Display/src/SSD1306_Graphics.o 

C_DEPS += \
./External_drivers/SSD1306_Display/src/SSD1306.d \
./External_drivers/SSD1306_Display/src/SSD1306_Graphics.d 


# Each subdirectory must supply rules for building sources it contributes
External_drivers/SSD1306_Display/src/%.o External_drivers/SSD1306_Display/src/%.su External_drivers/SSD1306_Display/src/%.cyclo: ../External_drivers/SSD1306_Display/src/%.c External_drivers/SSD1306_Display/src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DNUCLEO_F401RE -DSTM32 -DSTM32F401RETx -DSTM32F4 -c -I"C:/Users/Albin Roy/Desktop/STM32/driver_dev/External_drivers/SSD1306_Display/inc" -I"C:/Users/Albin Roy/Desktop/STM32/driver_dev/External_drivers/SSD1306_Display/bitmaps" -I../Inc -I"C:/Users/Albin Roy/Desktop/STM32/driver_dev/External_drivers/RTC_DS1307/inc" -I"C:/Users/Albin Roy/Desktop/STM32/driver_dev/External_drivers/BMP280_Sensor/inc" -I"C:/Users/Albin Roy/Desktop/STM32/driver_dev/Core/Inc" -I"C:/Users/Albin Roy/Desktop/STM32/driver_dev/Examples/inc" -I"C:/Users/Albin Roy/Desktop/STM32/driver_dev/drivers/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=soft -mthumb -o "$@"

clean: clean-External_drivers-2f-SSD1306_Display-2f-src

clean-External_drivers-2f-SSD1306_Display-2f-src:
	-$(RM) ./External_drivers/SSD1306_Display/src/SSD1306.cyclo ./External_drivers/SSD1306_Display/src/SSD1306.d ./External_drivers/SSD1306_Display/src/SSD1306.o ./External_drivers/SSD1306_Display/src/SSD1306.su ./External_drivers/SSD1306_Display/src/SSD1306_Graphics.cyclo ./External_drivers/SSD1306_Display/src/SSD1306_Graphics.d ./External_drivers/SSD1306_Display/src/SSD1306_Graphics.o ./External_drivers/SSD1306_Display/src/SSD1306_Graphics.su

.PHONY: clean-External_drivers-2f-SSD1306_Display-2f-src

