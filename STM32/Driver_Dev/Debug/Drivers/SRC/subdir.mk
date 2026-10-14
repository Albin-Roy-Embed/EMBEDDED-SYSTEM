################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (14.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../drivers/src/HCSR04_Driver.c \
../drivers/src/stm32f401re_adc_driver.c \
../drivers/src/stm32f401re_gpio_driver.c \
../drivers/src/stm32f401re_i2c_driver.c \
../drivers/src/stm32f401re_rcc_driver.c \
../drivers/src/stm32f401re_spi_driver.c \
../drivers/src/stm32f401re_systick_driver.c \
../drivers/src/stm32f401re_timer_driver.c \
../drivers/src/stm32f401re_usart_driver.c 

OBJS += \
./drivers/src/HCSR04_Driver.o \
./drivers/src/stm32f401re_adc_driver.o \
./drivers/src/stm32f401re_gpio_driver.o \
./drivers/src/stm32f401re_i2c_driver.o \
./drivers/src/stm32f401re_rcc_driver.o \
./drivers/src/stm32f401re_spi_driver.o \
./drivers/src/stm32f401re_systick_driver.o \
./drivers/src/stm32f401re_timer_driver.o \
./drivers/src/stm32f401re_usart_driver.o 

C_DEPS += \
./drivers/src/HCSR04_Driver.d \
./drivers/src/stm32f401re_adc_driver.d \
./drivers/src/stm32f401re_gpio_driver.d \
./drivers/src/stm32f401re_i2c_driver.d \
./drivers/src/stm32f401re_rcc_driver.d \
./drivers/src/stm32f401re_spi_driver.d \
./drivers/src/stm32f401re_systick_driver.d \
./drivers/src/stm32f401re_timer_driver.d \
./drivers/src/stm32f401re_usart_driver.d 


# Each subdirectory must supply rules for building sources it contributes
drivers/src/%.o drivers/src/%.su drivers/src/%.cyclo: ../drivers/src/%.c drivers/src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DNUCLEO_F401RE -DSTM32 -DSTM32F401RETx -DSTM32F4 -c -I"C:/Users/Albin Roy/Desktop/STM32/driver_dev/External_drivers/SSD1306_Display/inc" -I"C:/Users/Albin Roy/Desktop/STM32/driver_dev/External_drivers/SSD1306_Display/bitmaps" -I../Inc -I"C:/Users/Albin Roy/Desktop/STM32/driver_dev/External_drivers/RTC_DS1307/inc" -I"C:/Users/Albin Roy/Desktop/STM32/driver_dev/External_drivers/BMP280_Sensor/inc" -I"C:/Users/Albin Roy/Desktop/STM32/driver_dev/Core/Inc" -I"C:/Users/Albin Roy/Desktop/STM32/driver_dev/Examples/inc" -I"C:/Users/Albin Roy/Desktop/STM32/driver_dev/drivers/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=soft -mthumb -o "$@"

clean: clean-drivers-2f-src

clean-drivers-2f-src:
	-$(RM) ./drivers/src/HCSR04_Driver.cyclo ./drivers/src/HCSR04_Driver.d ./drivers/src/HCSR04_Driver.o ./drivers/src/HCSR04_Driver.su ./drivers/src/stm32f401re_adc_driver.cyclo ./drivers/src/stm32f401re_adc_driver.d ./drivers/src/stm32f401re_adc_driver.o ./drivers/src/stm32f401re_adc_driver.su ./drivers/src/stm32f401re_gpio_driver.cyclo ./drivers/src/stm32f401re_gpio_driver.d ./drivers/src/stm32f401re_gpio_driver.o ./drivers/src/stm32f401re_gpio_driver.su ./drivers/src/stm32f401re_i2c_driver.cyclo ./drivers/src/stm32f401re_i2c_driver.d ./drivers/src/stm32f401re_i2c_driver.o ./drivers/src/stm32f401re_i2c_driver.su ./drivers/src/stm32f401re_rcc_driver.cyclo ./drivers/src/stm32f401re_rcc_driver.d ./drivers/src/stm32f401re_rcc_driver.o ./drivers/src/stm32f401re_rcc_driver.su ./drivers/src/stm32f401re_spi_driver.cyclo ./drivers/src/stm32f401re_spi_driver.d ./drivers/src/stm32f401re_spi_driver.o ./drivers/src/stm32f401re_spi_driver.su ./drivers/src/stm32f401re_systick_driver.cyclo ./drivers/src/stm32f401re_systick_driver.d ./drivers/src/stm32f401re_systick_driver.o ./drivers/src/stm32f401re_systick_driver.su ./drivers/src/stm32f401re_timer_driver.cyclo ./drivers/src/stm32f401re_timer_driver.d ./drivers/src/stm32f401re_timer_driver.o ./drivers/src/stm32f401re_timer_driver.su ./drivers/src/stm32f401re_usart_driver.cyclo ./drivers/src/stm32f401re_usart_driver.d ./drivers/src/stm32f401re_usart_driver.o ./drivers/src/stm32f401re_usart_driver.su

.PHONY: clean-drivers-2f-src

