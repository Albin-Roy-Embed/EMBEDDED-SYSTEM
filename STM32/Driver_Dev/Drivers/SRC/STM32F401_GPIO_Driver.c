
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


void GPIO_PCLOCK_CONTROL(GPIO_REGDEF_t *pGPIOx, uint8_t EnorDi)
{
    if(EnorDi == ENABLE)
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

/*********************************************************************
 * @fn                - GPIO_INT
 *
 * @brief             - Initializes the GPIO peripheral according to the
 *                      configuration in the handle structure
 *
 * @param[in]         - pGPIO_HANDLE: pointer to GPIO handle structure
 *
 * @return            - none
 *
 * @Note              - This function sets up pin configuration, mode,
 *                      speed, pull-up/pull-down, etc.
 */

void GPIO_INIT(GPIO_HANDLE_t *pGPIO_HANDLE)
{
	uint32_t temp=0;
	//enable the peripheral clock
	GPIO_PCLOCK_CONTROL(pGPIO_HANDLE->pGPIOx,ENABLE);

	//GPIO mode
	if(pGPIO_HANDLE->GPIO_PinConfig.GPIO_PinMODE <=GPIO_MODE_ANALOG)
	{
		temp = (pGPIO_HANDLE->GPIO_PinConfig.GPIO_PinMODE <<(2*pGPIO_HANDLE->GPIO_PinConfig.GPIO_PinNUMBER));
		pGPIO_HANDLE->pGPIOx->MODER &=~(0x3 <<(2* pGPIO_HANDLE->GPIO_PinConfig.GPIO_PinNUMBER));
		pGPIO_HANDLE->pGPIOx->MODER |=temp;
		temp=0;
	}
	else
	{

	}

	//SPEED
	if(pGPIO_HANDLE->GPIO_PinConfig.GPIO_PinMODE <=GPIO_MODE_ANALOG)
	{
		temp = (pGPIO_HANDLE->GPIO_PinConfig.GPIO_PinSPEED <<(2*pGPIO_HANDLE->GPIO_PinConfig.GPIO_PinNUMBER));
		pGPIO_HANDLE->pGPIOx->OSPEEDR &=~(0x3 <<(2* pGPIO_HANDLE->GPIO_PinConfig.GPIO_PinNUMBER));
		pGPIO_HANDLE->pGPIOx->OSPEEDR |=temp;
		temp=0;
	}
	else
	{

	}

	//pull/pull down
	if(pGPIO_HANDLE->GPIO_PinConfig.GPIO_PinMODE <=GPIO_MODE_ANALOG)
	{
		temp = (pGPIO_HANDLE->GPIO_PinConfig.GPIO_PinPUPPD_CONTROL <<(2*pGPIO_HANDLE->GPIO_PinConfig.GPIO_PinNUMBER));
		pGPIO_HANDLE->pGPIOx->PUPDR&=~(0x3 <<(2* pGPIO_HANDLE->GPIO_PinConfig.GPIO_PinNUMBER));
		pGPIO_HANDLE->pGPIOx->PUPDR |=temp;
		temp=0;
	}
	else
	{

	}

	//optyper
	if(pGPIO_HANDLE->GPIO_PinConfig.GPIO_PinMODE <=GPIO_MODE_ANALOG)
	{
		temp = (pGPIO_HANDLE->GPIO_PinConfig.GPIO_PinOP_TYPE <<pGPIO_HANDLE->GPIO_PinConfig.GPIO_PinNUMBER);
		pGPIO_HANDLE->pGPIOx->OTYPER&=~(0x1 << pGPIO_HANDLE->GPIO_PinConfig.GPIO_PinNUMBER);
		pGPIO_HANDLE->pGPIOx->OTYPER |=temp;
		temp=0;
	}
}

/*********************************************************************
 * @fn                - GPIO_DEINT
 *
 * @brief             - De-initializes the given GPIO port (resets registers)
 *
 * @param[in]         - pGPIOx: base address of the GPIO peripheral
 *
 * @return            - none
 *
 * @Note              - Resets all configuration registers of the port
 */
void GPIO_DEINIT(GPIO_REGDEF_t *pGPIOx)
{
    GPIO_PCLOCK_CONTROL(pGPIOx, DISABLE);

    pGPIOx->MODER   = 0x00000000;
    pGPIOx->OTYPER  = 0x00000000;
    pGPIOx->OSPEEDR = 0x00000000;
    pGPIOx->PUPDR   = 0x00000000;
    pGPIOx->ODR     = 0x00000000;
}
/*********************************************************************
 * @fn                - GPIO_READ_INPUTPin
 *
 * @brief             - Reads the value from a specific input pin
 *
 * @param[in]         - pGPIOx: base address of the GPIO peripheral
 * @param[in]         - PinNUMBER: pin number to read
 *
 * @return            - 0 or 1 (logic level on the pin)
 *
 * @Note              - Useful for single-bit input reads
 */
uint8_t GPIO_READ_INPUTPin(GPIO_REGDEF_t *pGPIOx,uint8_t PinNUMBER)
{
   uint8_t value;
   value = (uint8_t)((pGPIOx->IDR >>PinNUMBER) & 1);
   return value;
}

/*********************************************************************
 * @fn                - GPIO_READ_INPUTPORT
 *
 * @brief             - Reads the entire input port value
 *
 * @param[in]         - pGPIOx: base address of the GPIO peripheral
 *
 * @return            - 16-bit value representing all pin states
 *
 * @Note              - Useful for reading multiple pins at once
 */
uint16_t GPIO_READ_INPUTPORT(GPIO_REGDEF_t *pGPIOx)
{
   uint16_t value;
   value=(uint16_t) pGPIOx->IDR;
   return value;
}

/*********************************************************************
 * @fn                - WRITE_OUTPUTPin
 *
 * @brief             - Writes a logic value to a specific output pin
 *
 * @param[in]         - pGPIOx: base address of the GPIO peripheral
 * @param[in]         - PinNUMBER: pin number to write
 * @param[in]         - value: 0 or 1
 *
 * @return            - none
 *
 * @Note              - Sets or clears the bit in ODR register
 */
void WRITE_OUTPUTPin(GPIO_REGDEF_t *pGPIOx,uint8_t PinNUMBER,uint8_t value)
{
      if(value==1)
      {
        pGPIOx->ODR |=(1<<PinNUMBER);
       }
      else
      {
    	  pGPIOx->ODR &=~(1<<PinNUMBER);
      }
}

/*********************************************************************
 * @fn                - WRITE_OUTPUTPORT
 *
 * @brief             - Writes a 16-bit value to the entire output port
 *
 * @param[in]         - pGPIOx: base address of the GPIO peripheral
 * @param[in]         - value: 16-bit value to write
 *
 * @return            - none
 *
 * @Note              - Overwrites all pin states in ODR register
 */
void WRITE_OUTPUTPORT(GPIO_REGDEF_t *pGPIOx,uint16_t value)
{
    pGPIOx->ODR= value;
}

/*********************************************************************
 * @fn                - TOGGLE_OUTPUTpin
 *
 * @brief             - Toggles the output state of a specific pin
 *
 * @param[in]         - pGPIOx: base address of the GPIO peripheral
 * @param[in]         - PinNUMBER: pin number to toggle
 *
 * @return            - none
 *
 * @Note              - Flips the bit in ODR register
 */
void TOGGLE_OUTPUTpin(GPIO_REGDEF_t *pGPIOx,uint8_t PinNUMBER)
{
	 pGPIOx->ODR ^=(1<<PinNUMBER);
}

#endif /* SRC_STM32F401_GPIO_DRIVER_C_ */
