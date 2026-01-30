
/*
 * STM32F401_GPIO_Driver.c
 *
 *  Created on: Jan 28, 2026
 *      Author: user
 */

#ifndef SRC_STM32F401_GPIO_DRIVER_C_
#define SRC_STM32F401_GPIO_DRIVER_C_

#include "STM32F401xx_GPIO_Driver.h"
//GPIO_PeriClockControl(GPIOA, ENABLE);


/*********************************************************************
 * @fn                - GPIO_PeriClockControl
 *
 * @brief             - This function enables or disables peripheral clock for the given GPIO port
 *
 * @param[in]         - pGPIOx: base address of the GPIO peripheral(GPIOA, GPIOB, .....GPIOH)
 * @param[in]         - EnorDi: ENABLE or DISABLE macros
 *
 * @return            - none
 *
 * @Note              - none
 */


void PCLOCK_CONTROL(GPIO_REGDEF_t *pGPIOx, uint8_t ENorDI)
{
    if(pGPIOx == GPIOA)
    {
        GPIOA_PCLK_EN();
    }
    else if(pGPIOx == GPIOB)
    {
        GPIOB_PCLK_EN();
    }
    else if(pGPIOx == GPIOC)
    {
        GPIOC_PCLK_EN();
    }
    else if(pGPIOx == GPIOD)
    {
        GPIOD_PCLK_EN();
    }
    else if(pGPIOx == GPIOE)
    {
        GPIOE_PCLK_EN();
    }
    else if(pGPIOx == GPIOH)
    {
        GPIOH_PCLK_EN();
    }
    else
    {
        if(pGPIOx == GPIOA)
        {
            GPIOA_PCLK_DI();
        }
        else if(pGPIOx == GPIOB)
        {
            GPIOB_PCLK_DI();
        }
        else if(pGPIOx == GPIOC)
        {
            GPIOC_PCLK_DI();
        }
        else if(pGPIOx == GPIOD)
        {
            GPIOD_PCLK_DI();
        }
        else if(pGPIOx == GPIOE)
        {
            GPIOE_PCLK_DI();
        }
        else if(pGPIOx == GPIOH)
        {
            GPIOH_PCLK_DI();
        }
    }
}
//GPIO_PeriClockControl(GPIOA, ENABLE);


/*********************************************************************
 * @fn                - GPIO_PeriClockControl
 *
 * @brief             - This function enables or disables peripheral clock for the given GPIO port
 *
 * @param[in]         - pGPIOx: base address of the GPIO peripheral(GPIOA, GPIOB, .....GPIOH)
 * @param[in]         - EnorDi: ENABLE or DISABLE macros
 *
 * @return            - none
 *
 * @Note              - none
 */
void GPIO_INT(GPIO_HANDLE_t *pGPIO_HANDLE)
{

}

void GPIO_DEINT(GPIO_REGDEF_t *pGPIOx)
{

}

uint8_t GPIO_READ_INPUTPin(GPIO_REGDEF_t *pGPIOx,uint8_t PinNUMBER)
{

}

uint16_t GPIO_READ_INPUTPORT(GPIO_REGDEF_t *pGPIOx)
{

}

void WIRTE_OUTPUTPin(GPIO_REGDEF_t *pGPIOx,uint8_t PinNUMBER,uint8_t value)
{

}
void WIRTE_OUTPUTPORT(GPIO_REGDEF_t *pGPIOx,uint8_t value)
{

}
void TOGGLE_OUTPUTpin(GPIO_REGDEF_t *pGPIOx,uint8_t PinNUMBER)
{

}

#endif /* SRC_STM32F401_GPIO_DRIVER_C_ */
