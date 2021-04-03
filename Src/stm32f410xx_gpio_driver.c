/*
 * stm32f410xx_Driver.c
 *
 *  Created on: 15-Feb-2021
 *      Author: Lingaswamy Shyaga
 *
 */
#include <stdint.h>
#include "stm32f410xx_gpio_driver.h"
#include "stm32f410xx.h"
//#define NVIC_PR_BASSADDRESS           (volatile uint32_t*)0xE000E401

/*=====================================================
 * @fn				-GPIO_periperalClockControle
 *
 * @brief			-
 *
 * @param[in]		-
 * @param[in]		-
 * @param[in]		-
 *
 *
 * @return			-
 *
 * @Note			-
 *
 */

//periperal clock set

void GPIO_PerlClkControle(GPIO_regdef_t *pGPIOx,uint8_t EnorDi)
{
	if(EnorDi == ENABLE)
	{
		if(pGPIOx == GPIOA)
		  {
		 //	GPIOA_PCLK_DI();
			GPIOA_PCLK_EN();

			//uint32_t *pClk_ctrl_reg =(uint32_t*)0x40023830;

			//*pClk_ctrl_reg |=(0x1<<0);
			//*pClk_ctrl_reg &=~(0x1<<1);
			//*pClk_ctrl_reg &=~(0x1<<2);
			//*pClk_ctrl_reg &=~(0x1<<7);

			}//do{(uint32_t *pClk_ctrl_reg =(uint32_t*)0x40023830); (uint32_t temp = temp |(1<<0)); (*pClk_ctrl_reg =temp);}while(0)

		else if(pGPIOx == GPIOB)
		{
		//	GPIOB_PCLK_DI();
			GPIOB_PCLK_EN();

			//uint32_t *pClk_ctrl_reg =(uint32_t*)0x40023830;
			//*pClk_ctrl_reg |= (0x1<<1);

			//*pClk_ctrl_reg &=~(0x1<<2);
			//*pClk_ctrl_reg &=~(0x1<<3);
			//*pClk_ctrl_reg &=~(0x1<<7);
			//GPIOB_PCLK_EN();
		}
		else if(pGPIOx == GPIOC)
		{
		//	GPIOC_PCLK_DI();
			GPIOC_PCLK_EN();
			//uint32_t *pClk_ctrl_reg =(uint32_t*)0x40023830;
			//*pClk_ctrl_reg |= (0x1<<2);

			//*pClk_ctrl_reg &= ~(0x1<<1);
			//*pClk_ctrl_reg &= ~(0x1<<7);
		}
		else if(pGPIOx == GPIOH)
		{
		//	GPIOH_PCLK_DI();
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
		else if(pGPIOx == GPIOC)
		{
			 GPIOC_PCLK_DI();
		}
	}
}



/*=====================================================
 * @fn				-GPIO_Intialization
 *
 * @brief			-
 *
 * @param[in]		-
 * @param[in]		-
 * @param[in]		-
 *
 *
 * @return			-
 *
 * @Note			-
 *
 */

//Init and DeInt

void GPIO_Init(GPIO_handle_t *pGPIOhandle)
{
	uint32_t temp;//temp.register

	//enble the peripheral clock

	GPIO_PerlClkControle(pGPIOhandle->pGPIOx,ENABLE);

	//configuration gpio modes
	if(pGPIOhandle->GPIO_PinConfig_t.GPIO_PinMode <= GPIO_MODE_ALT)
	{
		temp=(pGPIOhandle->GPIO_PinConfig_t.GPIO_PinMode << (2 * pGPIOhandle->GPIO_PinConfig_t.GPIO_PinNumber));
		pGPIOhandle->pGPIOx->MODER &=~(0x3 << 2 * pGPIOhandle->GPIO_PinConfig_t.GPIO_PinNumber);
		pGPIOhandle->pGPIOx->MODER |=temp;
	}
	else
	{
		if(pGPIOhandle->GPIO_PinConfig_t.GPIO_PinMode<= GPIO_MODE_IT_FT)
		{
			//confingure the Falling edge
			EXTI->FTSR |=(0x1<<pGPIOhandle->GPIO_PinConfig_t.GPIO_PinNumber);
			//clear cofinguration Of rising edge
			EXTI->RTSR &=~(0x1<<pGPIOhandle->GPIO_PinConfig_t.GPIO_PinNumber);
		}
		else if(pGPIOhandle->GPIO_PinConfig_t.GPIO_PinMode<= GPIO_MODE_IT_RT)
		{
			//configure the rising edge

			EXTI->RTSR |=(0x1<<pGPIOhandle->GPIO_PinConfig_t.GPIO_PinNumber);

			//clear cofinguration Of Falling edge

			EXTI->FTSR &=~(0x1<<pGPIOhandle->GPIO_PinConfig_t.GPIO_PinNumber);
		}
		else if(pGPIOhandle->GPIO_PinConfig_t.GPIO_PinMode<= GPIO_MODE_IT_RFT)
		{
			//confingure the rising and falling edge

			EXTI->FTSR |=(0x01<<pGPIOhandle->GPIO_PinConfig_t.GPIO_PinNumber);


			EXTI->RTSR |=(0x01<<pGPIOhandle->GPIO_PinConfig_t.GPIO_PinNumber);
		}
		//2.configure the GPIO port selection in SYSCNFG-EXTICR
		uint8_t temp1        = pGPIOhandle->GPIO_PinConfig_t.GPIO_PinNumber/4;
		uint8_t temp2        = pGPIOhandle->GPIO_PinConfig_t.GPIO_PinNumber%4;
		uint8_t portocode    = GPIO_BASEADDRESS_TO_CODE(pGPIOhandle->pGPIOx);
		SYSCFG->EXTICR[temp1]= portocode*(4*temp2);

		SYSCFG_PCLK_EN();

		//3. enable the exti interrupt delivery using IRM
		EXTI->IMR |=(0X01<<pGPIOhandle->GPIO_PinConfig_t.GPIO_PinNumber );


	}

	//configure the speed
	temp=0;
	temp=(pGPIOhandle->GPIO_PinConfig_t.GPIO_Pinspeed << (2* pGPIOhandle->GPIO_PinConfig_t.GPIO_PinNumber));

	pGPIOhandle->pGPIOx->OSPEEDER &=~(0x3 <<(2* pGPIOhandle->GPIO_PinConfig_t.GPIO_PinNumber));

	pGPIOhandle->pGPIOx->OSPEEDER|=temp;

	//configure the pupd settings
	temp=0;
	temp=(pGPIOhandle->GPIO_PinConfig_t.GPIO_PinPuPdControl <<(2* pGPIOhandle->GPIO_PinConfig_t.GPIO_PinNumber));
	pGPIOhandle->pGPIOx->PUPDR &=~(0x3 << pGPIOhandle->GPIO_PinConfig_t.GPIO_PinNumber);
	pGPIOhandle->pGPIOx->PUPDR|=temp;

	//configure the otype settings
	temp=0;
	temp=(pGPIOhandle->GPIO_PinConfig_t.GPIO_PinOPType << (pGPIOhandle->GPIO_PinConfig_t.GPIO_PinNumber));
	pGPIOhandle->pGPIOx->OTYPER &=~(0x01 << pGPIOhandle->GPIO_PinConfig_t.GPIO_PinNumber);//clear
	pGPIOhandle->pGPIOx->OTYPER|=temp;

	if(pGPIOhandle->GPIO_PinConfig_t.GPIO_PinMode == GPIO_MODE_ALT)
	{
		uint32_t temp1;
		uint32_t temp2;
		temp1 =pGPIOhandle->GPIO_PinConfig_t.GPIO_PinNumber/8;
		temp2 =pGPIOhandle->GPIO_PinConfig_t.GPIO_PinNumber%8;
		pGPIOhandle->pGPIOx->AFR[temp1] &=~(0xF << (4* temp2));
		pGPIOhandle->pGPIOx->AFR[temp1] |=(pGPIOhandle->GPIO_PinConfig_t.GPIO_PinAltfunMode << (4* temp2));
	}
}

/*=====================================================
 * @fn				-GPIO_Diinitialization
 *
 * @brief			-
 *
 * @param[in]		-
 * @param[in]		-
 * @param[in]		-
 *
 *
 * @return			-
 *
 * @Note			-
 *
 */

void GPIO_DiInit(GPIO_regdef_t *pGPIOx)
{


			if(pGPIOx == GPIOA)
			{
				GPIOA_REG_RESET();
			}
			else if(pGPIOx == GPIOB)
			{
				GPIOB_REG_RESET();
			}
			else if(pGPIOx == GPIOC)
			{
				GPIOC_REG_RESET();
			}
			else if(pGPIOx == GPIOC)
			{
				GPIOH_REG_RESET();
			}

}
/*=====================================================
 * @fn				-GPIO_ReadFromInputPort
 *
 * @brief			-
 *
 * @param[in]		-
 * @param[in]		-
 * @param[in]		-
 *
 *
 * @return			-
 *
 * @Note			-
 *
 */

//data read and write

uint8_t GPIO_ReadfromInputPin(GPIO_regdef_t *pGPIOx,uint8_t PinNumber)
{
	uint8_t value;

	value=(uint8_t)((pGPIOx->IDR >> PinNumber) & 0x00000001);

	return value;
}
/*=====================================================
 * @fn				-GPIO_ReadFromInputPort
 *
 * @brief			-
 *
 * @param[in]		-
 * @param[in]		-
 * @param[in]		-
 *
 *
 * @return			-
 *
 * @Note			-
 *
 */

/*=====================================================
 * @fn				-GPIO_ReadFromInputPort
 *
 * @brief			-
 *
 * @param[in]		-
 * @param[in]		-
 * @param[in]		-
 *
 *
 * @return			-
 *
 * @Note			-
 *
 */


uint16_t GPIO_ReadfromInputport(GPIO_regdef_t *pGPIOx)
{

	uint16_t value;

	value=(uint16_t)(pGPIOx->IDR);

	return value;

}

/*=====================================================
 * @fn				-GPIO_WriteoutputPin
 *
 * @brief			-
 *
 * @param[in]		-
 * @param[in]		-
 * @param[in]		-
 *
 *
 * @return			-
 *
 * @Note			-
 *
 */

void GPIO_WritetOutputPin(GPIO_regdef_t *pGPIOx,uint8_t PinNumber,uint8_t value)
{
	if(value == GPIO_PIN_SET)
	{
		//write 1 to the output data register at the bit field corresponding to the pin
		pGPIOx->ODR |=(1<< PinNumber);
	}
	else
	{
		//write 0
		pGPIOx->ODR &= ~(1<< PinNumber);
	}
}


/*=====================================================
 * @fn				-GPIO_WritetOoutputport
 *
 * @brief			-
 *
 * @param[in]		-
 * @param[in]		-
 * @param[in]		-
 *
 *
 * @return			-
 *
 * @Note			-
 *
 */

void GPIO_WritetOoutputport(GPIO_regdef_t *pGPIOx,uint16_t value)
{
	pGPIOx->ODR = value;
}


/*=====================================================
 * @fn				-GPIO_ToggleOutputPin
 *
 * @brief			-
 *
 * @param[in]		-
 * @param[in]		-
 * @param[in]		-
 *
 *
 * @return			-
 *
 * @Note			-
 *
 */

void GPIO_ToggleOutputPin(GPIO_regdef_t *pGPIOx,uint8_t PinNumber)
{
		pGPIOx->ODR ^=(0x1 << PinNumber);
}



/*=====================================================
 * @fn				-GPIO_IRQConfig
 *
 * @brief			-
 *
 * @param[in]		-
 * @param[in]		-
 * @param[in]		-
 *
 *
 * @return			-
 *
 * @Note			-
 *
 */

//Confinguration Handler

void GPIO_interruptIRQConfig(uint8_t IRQNumber,uint8_t EnorDi)
{
	if(EnorDi==ENABLE)
	{
		if(IRQNumber<=31)
		{
			//program ISER0 register
			*NVIC_ISER0 |=(0x01<<IRQNumber);
		}
		else if(IRQNumber > 31 && IRQNumber < 64)
		{
			//program Isr register 32 to 63
			*NVIC_ISER1 |=(0x01<<(IRQNumber) % 32);
		}
		else if(IRQNumber >= 63 && IRQNumber < 96)
		{
			//program Isr register 64 to 95
			*NVIC_ISER2 |=(0x01<<((IRQNumber) % 64));
		}
	}
	else
	{
		if(IRQNumber<=31)
		{
		//program ISER0 register

		*NVIC_ICER0 |=(0x01<<(IRQNumber));
		}
		else if(IRQNumber > 32 && IRQNumber < 64)
		{
		//program Isr register 32 to 63

		*NVIC_ICER1 |=(0x01<<(IRQNumber % 32));

		}
		else if(IRQNumber >= 64 && IRQNumber < 96)
		{
		//program Isr register 64 to 95

		*NVIC_ICER2 |=(0x01<<(IRQNumber % 64));

		}

	}
}

void GPIO_priorityIRQconfig(uint8_t IRQNumber,uint32_t IRQPriority)
{
	uint8_t iprx = IRQNumber / 4;
	uint8_t iprx_section = IRQNumber % 4;
	uint8_t shift_amout = (8* iprx_section)+(8 - NO_PR_BITS_IMPLEMENTED);
//                                                                           #define NVIC_PR_BASSADDRESS           (volatile uint32_t*)0xE000E400
	                                                                       //*(0xE000E400U + (iprx*4)) |= (IRQPriority << shift_amout);
	*(NVIC_PR_BASSADDRESS + (iprx*4)) |= (IRQPriority << shift_amout);

}
void GPIO_IRQHandler(uint8_t PinNumber)
{
	//clear the exit register correspoding to the pin number
	if(EXTI->PR & (0x01 << PinNumber))
	{
		EXTI->PR |= (0x01 << PinNumber);
	}
}
