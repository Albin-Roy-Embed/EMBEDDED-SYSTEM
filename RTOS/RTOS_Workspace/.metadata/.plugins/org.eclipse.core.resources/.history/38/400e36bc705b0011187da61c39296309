
/*
 * STM32F401_GPIO_Driver.c
 *
 *  Created on: Jan 28, 2026
 *      Author: Albin
 */

#include "STM32f401xx_GPIO_Driver.h"

/*********************************************************************
 * @fn                - GPIO_PCLOCK_CONTROL
 *
 * @brief             - Enables or disables peripheral clock for the given GPIO port
 *
 * @param[in]         - pGPIOx: base address of the GPIO peripheral (GPIOA, GPIOB, ... GPIOH)
 * @param[in]         - EnorDi: ENABLE or DISABLE macros
 *
 * @return            - none
 *********************************************************************/
void GPIO_PCLOCK_CONTROL(GPIO_REGDEF_t *pGPIOx, uint8_t ENorDI)
{
    if(ENorDI == ENABLE)
    {
        if(pGPIOx == GPIOA) { GPIOA_PCLK_EN(); }
        else if(pGPIOx == GPIOB) { GPIOB_PCLK_EN(); }
        else if(pGPIOx == GPIOC) { GPIOC_PCLK_EN(); }
        else if(pGPIOx == GPIOD) { GPIOD_PCLK_EN(); }
        else if(pGPIOx == GPIOE) { GPIOE_PCLK_EN(); }
        else if(pGPIOx == GPIOH) { GPIOH_PCLK_EN(); }
    }
    else
    {
        if(pGPIOx == GPIOA) { GPIOA_PCLK_DI(); }
        else if(pGPIOx == GPIOB) { GPIOB_PCLK_DI(); }
        else if(pGPIOx == GPIOC) { GPIOC_PCLK_DI(); }
        else if(pGPIOx == GPIOD) { GPIOD_PCLK_DI(); }
        else if(pGPIOx == GPIOE) { GPIOE_PCLK_DI(); }
        else if(pGPIOx == GPIOH) { GPIOH_PCLK_DI(); }
    }
}

/*********************************************************************
 * @fn                - GPIO_INIT
 *
 * @brief             - Initializes the GPIO peripheral according to the configuration
 *
 * @param[in]         - pGPIO_HANDLE: pointer to GPIO handle structure
 *
 * @return            - none
 *********************************************************************/
void GPIO_INIT(GPIO_HANDLE_t *pGPIO_HANDLE)
{
    uint32_t temp = 0;

    // Enable peripheral clock
    GPIO_PCLOCK_CONTROL(pGPIO_HANDLE->pGPIOx, ENABLE);

    // Configure mode
    if(pGPIO_HANDLE->GPIO_PinConfig.GPIO_PinMODE <= GPIO_MODE_ANALOG)
    {
        temp = (pGPIO_HANDLE->GPIO_PinConfig.GPIO_PinMODE << (2 * pGPIO_HANDLE->GPIO_PinConfig.GPIO_PinNUMBER));
        pGPIO_HANDLE->pGPIOx->MODER &= ~(0x3 << (2 * pGPIO_HANDLE->GPIO_PinConfig.GPIO_PinNUMBER));
        pGPIO_HANDLE->pGPIOx->MODER |= temp;
        temp = 0;
    }
    else
    {
        // Interrupt mode
        if(pGPIO_HANDLE->GPIO_PinConfig.GPIO_PinMODE == GPIO_MODE_INTR_FT)
        {
            EXTI->FTSR |= (1 << pGPIO_HANDLE->GPIO_PinConfig.GPIO_PinNUMBER);
            EXTI->RTSR &= ~(1 << pGPIO_HANDLE->GPIO_PinConfig.GPIO_PinNUMBER);
        }
        else if(pGPIO_HANDLE->GPIO_PinConfig.GPIO_PinMODE == GPIO_MODE_INTR_RT)
        {
            EXTI->RTSR |= (1 << pGPIO_HANDLE->GPIO_PinConfig.GPIO_PinNUMBER);
            EXTI->FTSR &= ~(1 << pGPIO_HANDLE->GPIO_PinConfig.GPIO_PinNUMBER);
        }
        else if(pGPIO_HANDLE->GPIO_PinConfig.GPIO_PinMODE == GPIO_MODE_INTR_RFT)
        {
            EXTI->RTSR |= (1 << pGPIO_HANDLE->GPIO_PinConfig.GPIO_PinNUMBER);
            EXTI->FTSR |= (1 << pGPIO_HANDLE->GPIO_PinConfig.GPIO_PinNUMBER);
        }

        uint8_t temp1 = pGPIO_HANDLE->GPIO_PinConfig.GPIO_PinNUMBER / 4;
        uint8_t temp2 = pGPIO_HANDLE->GPIO_PinConfig.GPIO_PinNUMBER % 4;

        uint8_t portcode = GPIO_BASEADDR_TO_CODE(pGPIO_HANDLE->pGPIOx);
        SYSCFG_PCLK_EN();
        SYSCFG->EXTICR[temp1] = portcode << (temp2 * 4);

        EXTI->IMR |= (1 << pGPIO_HANDLE->GPIO_PinConfig.GPIO_PinNUMBER);
    }

    // Speed
    temp = (pGPIO_HANDLE->GPIO_PinConfig.GPIO_PinSPEED << (2 * pGPIO_HANDLE->GPIO_PinConfig.GPIO_PinNUMBER));
    pGPIO_HANDLE->pGPIOx->OSPEEDR &= ~(0x3 << (2 * pGPIO_HANDLE->GPIO_PinConfig.GPIO_PinNUMBER));
    pGPIO_HANDLE->pGPIOx->OSPEEDR |= temp;
    temp = 0;

    // Pull-up/pull-down
    temp = (pGPIO_HANDLE->GPIO_PinConfig.GPIO_PinPUPPD_CONTROL << (2 * pGPIO_HANDLE->GPIO_PinConfig.GPIO_PinNUMBER));
    pGPIO_HANDLE->pGPIOx->PUPDR &= ~(0x3 << (2 * pGPIO_HANDLE->GPIO_PinConfig.GPIO_PinNUMBER));
    pGPIO_HANDLE->pGPIOx->PUPDR |= temp;
    temp = 0;

    // Output type
    temp = (pGPIO_HANDLE->GPIO_PinConfig.GPIO_PinOP_TYPE << pGPIO_HANDLE->GPIO_PinConfig.GPIO_PinNUMBER);
    pGPIO_HANDLE->pGPIOx->OTYPER &= ~(0x1 << pGPIO_HANDLE->GPIO_PinConfig.GPIO_PinNUMBER);
    pGPIO_HANDLE->pGPIOx->OTYPER |= temp;
    temp = 0;
}

/*********************************************************************
 * @fn                - GPIO_DEINIT
 *
 * @brief             - De-initializes the given GPIO port (resets registers)
 *
 * @param[in]         - pGPIOx: base address of the GPIO peripheral
 *
 * @return            - none
 *********************************************************************/
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
 *********************************************************************/
uint8_t GPIO_READ_INPUTPin(GPIO_REGDEF_t *pGPIOx, uint8_t PinNUMBER)
{
   uint8_t value;
   value = (uint8_t)((pGPIOx->IDR >> PinNUMBER) & 1);
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
 *********************************************************************/
uint16_t GPIO_READ_INPUTPORT(GPIO_REGDEF_t *pGPIOx)
{
   uint16_t value;
   value = (uint16_t) pGPIOx->IDR;
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
 *********************************************************************/
void WIRTE_OUTPUTPin(GPIO_REGDEF_t *pGPIOx, uint8_t PinNUMBER, uint8_t value)
{
    if(value == 1)
    {
        pGPIOx->ODR |= (1 << PinNUMBER);
    }
    else
    {
        pGPIOx->ODR &= ~(1 << PinNUMBER);
    }
}

/*********************************************************************
 * @fn                - WRITE_OUTPUTPORT
 *
 * @brief             - Writes a 16-bit value to the entire output port
 *
 * @param[in]         - pGPIOx: base address of the GPIO peripheral
 * @param[in]         - value: 16-bit value to write
 *********************************************************************/
void WRITE_OUTPUTPORT(GPIO_REGDEF_t *pGPIOx, uint16_t value)
{
    pGPIOx->ODR = value;
}
/*********************************************************************
 * @fn                - TOGGLE_OUTPUTpin
 *
 * @brief             - Toggles the output state of a specific pin
 *
 * @param[in]         - pGPIOx: base address of the GPIO peripheral
 * @param[in]         - PinNUMBER: pin number to toggle
 *********************************************************************/
void TOGGLE_OUTPUTpin(GPIO_REGDEF_t *pGPIOx, uint8_t PinNUMBER)
{
    pGPIOx->ODR ^= (1 << PinNUMBER);
}


void GPIO_IRQINTERRRUPTCONFIG(uint8_t IRQNUMBER, uint8_t ENorDI)
{
    if(ENorDI == ENABLE)
    {
        if(IRQNUMBER <= 31)
        {
            *NVIC_ISER0 |= (1 << IRQNUMBER);
        }
        else if(IRQNUMBER > 31 && IRQNUMBER < 64)
        {
            *NVIC_ISER1 |= (1 << (IRQNUMBER % 32));
        }
        else if(IRQNUMBER >= 64 && IRQNUMBER < 96)
        {
            *NVIC_ISER2 |= (1 << (IRQNUMBER % 32));
        }
    }
    else
    {
        if(IRQNUMBER <= 31)
        {
            *NVIC_ICER0 |= (1 << IRQNUMBER);
        }
        else if(IRQNUMBER > 31 && IRQNUMBER < 64)
        {
            *NVIC_ICER1 |= (1 << (IRQNUMBER % 32));
        }
        else if(IRQNUMBER >= 64 && IRQNUMBER < 96)
        {
            *NVIC_ICER2 |= (1 << (IRQNUMBER % 32));
        }
    }
}
