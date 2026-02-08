/*
 * GPIO_Toggle.c
 *
 *  Created on: Feb 5, 2026
 *      Author: user
 */
#include "STM32F401xx.h"
#include "STM32f401xx_GPIO_Driver.h"

void delay(void)
{
    for(uint32_t i = 0; i <= 500000; i++);
}

int main(void)
{
    GPIO_HANDLE_t Gpioled;
    GPIO_HANDLE_t Gpiobtn;

    Gpioled.pGPIOx = GPIOA;
    Gpioled.GPIO_PinConfig.GPIO_PinNUMBER = GPIO_PIN_NUM_5;
    Gpioled.GPIO_PinConfig.GPIO_PinMODE = GPIO_MODE_OUT;
    Gpioled.GPIO_PinConfig.GPIO_PinSPEED = GPIO_MODE_MED_SPEED;
    Gpioled.GPIO_PinConfig.GPIO_PinPUPPD_CONTROL = GPIO_MODE_NO_PU_PD;
    Gpioled.GPIO_PinConfig.GPIO_PinOP_TYPE = GPIO_OTYPE_PP;

    GPIO_PCLOCK_CONTROL(GPIOA, ENABLE);
    GPIO_INIT(&Gpioled);

    Gpiobtn.pGPIOx = GPIOC;
    Gpiobtn.GPIO_PinConfig.GPIO_PinNUMBER = GPIO_PIN_NUM_13;
    Gpiobtn.GPIO_PinConfig.GPIO_PinMODE = GPIO_MODE_IN;
    Gpiobtn.GPIO_PinConfig.GPIO_PinSPEED = GPIO_MODE_MED_SPEED;
    Gpiobtn.GPIO_PinConfig.GPIO_PinPUPPD_CONTROL = GPIO_MODE_PU;

    GPIO_PCLOCK_CONTROL(GPIOC, ENABLE);
    GPIO_INIT(&Gpiobtn);

    while(1)
    {
        if(GPIO_READ_INPUTPin(GPIOC, GPIO_PIN_NUM_13) == 0)
        {
            delay();
            TOGGLE_OUTPUTpin(GPIOA, GPIO_PIN_NUM_5);
        }
    }
}
