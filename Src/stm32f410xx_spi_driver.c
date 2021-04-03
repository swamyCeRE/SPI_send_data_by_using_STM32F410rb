/*
 * stm32f410xx_spi_driver.c
 *
 *  Created on: 19-Mar-2021
 *      Author: Lingaswamy Shyaga
 */
#include <stdint.h>
#include "stm32f410xx_spi_driver.h"
#include "stm32f410xx.h"

/*=====================================================
 * @fn				-periperal clock set
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

void SPI_PerlClkControle(SPI_regdef_t *pSPIx,uint8_t EnorDi)
{
	     if(EnorDi == ENABLE)
			{
				if(pSPIx == SPI1)
				 {
					SPI1_PCLK_EN();
				 }
				else if(pSPIx == SPI2)
				 {
					SPI2_PCLK_EN();
				 }
				else if(pSPIx == SPI5)
				 {
					SPI5_PCLK_EN();
				 }

			}
			else
			{
				if(pSPIx == SPI1)
				{
					SPI1_PCLK_DI();
				}
				else if(pSPIx == SPI2)
				{
					SPI2_PCLK_DI();
				}
				else if(pSPIx == SPI5)
				{
					SPI5_PCLK_DI();
				}
			}
}


/*=====================================================
 * @fn				-Init and DeInt
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

void SPI_Init(SPI_handle_t *pSPIhandle)
{
	//peripheral clock enable

	SPI_PerlClkControle(pSPIhandle->pSPIx,ENABLE);

 // first lets configure the spi_CR1_register

 uint32_t tempreg=0 ;


 //fist step configure the device mode
 tempreg |= pSPIhandle->SPIConfig.SPI_DeviceMode<<SPI_CR1_MSTR;

 pSPIhandle->pSPIx->SPI_CR1 = tempreg;// for Debugging purpose I placed , actually it will take more cycle, if you don't need please remove

  //configure the bus configuration
 if(pSPIhandle->SPIConfig.SPI_BusConfig == SPI_BUS_CONFIG_FD)
 {
	 //bidi mode clear
	 tempreg &= ~(0x01<<SPI_CR1_BIDIMODE);
 }
 //configure the bus
 else if(pSPIhandle->SPIConfig.SPI_BusConfig == SPI_BUS_CONFIG_HD)
 {
	 //bidi mode set
	 tempreg |= (0x01<<SPI_CR1_BIDIMODE);
 }
 else if(pSPIhandle->SPIConfig.SPI_BusConfig == SPI_BUS_CONFIG_SIMPLEX_RXONLY)
 {
	 //bidi must be clear
	 tempreg &= ~(0x01<<SPI_CR1_BIDIMODE);

	 pSPIhandle->pSPIx->SPI_CR1 = tempreg;// for Debugging purpose I placed , actually it will take more cycle, if you don't need please remove

	 //bidi mode must be set
	 tempreg |= (0x01<<SPI_CR1_RXONLY);

	 pSPIhandle->pSPIx->SPI_CR1 = tempreg;// for Debugging purpose I placed , actually it will take more cycle, if you don't need please remove
 }
//27/03/2021 changed
 //3. Configure the spi serial clock speed(boud rate)

 tempreg |=pSPIhandle->SPIConfig.SPI_SclkSpeed<<SPI_CR1_BR;

 pSPIhandle->pSPIx->SPI_CR1 = tempreg;// for Debugging purpose I placed , actually it will take more cycle, if you don't need please remove

 //4. Configure the DFF

 tempreg |=pSPIhandle->SPIConfig.SPI_DFF<<SPI_CR1_DFF;

 pSPIhandle->pSPIx->SPI_CR1 = tempreg;// for Debugging purpose I placed , actually it will take more cycle, if you don't need please remove
 //5.configure the cpol

 tempreg |=pSPIhandle->SPIConfig.SPI_CPOL<<SPI_CR1_CPOL;

 pSPIhandle->pSPIx->SPI_CR1 = tempreg;// for Debugging purpose I placed , actually it will take more cycle, if you don't need please remove

 //6. configure the cpha

 tempreg |=pSPIhandle->SPIConfig.SPI_CPHA<<SPI_CR1_CPHA;

 pSPIhandle->pSPIx->SPI_CR1 = tempreg; // for Debugging purpose I placed , actually it will take more cycle, if you don't need please remove

 //7.cofigure the ssm

 tempreg |=pSPIhandle->SPIConfig.SPI_SSM<<SPI_CR1_SSM;

 pSPIhandle->pSPIx->SPI_CR1 = tempreg;

 /*

								 else if(pSPIhandle->SPIConfig.SPI_SclkSpeed == SPI_SClk_SPEED_BY_2)
								 {
									 //Sclk boudrate controle by 2
									 tempreg &=~(0x01<<SPI_CR1_BR);
								 }
								 else if(pSPIhandle->SPIConfig.SPI_SclkSpeed == SPI_SClk_SPEED_BY_4)
								 {
									 //Sclk boudrate controle by 4
									 tempreg |=(0x01<<SPI_CR1_BR);
								 }
								 else if(pSPIhandle->SPIConfig.SPI_SclkSpeed == SPI_SClk_SPEED_BY_8)
								 {
									 //Sclk boudrate controle by 8
									 tempreg |=(0x02<<SPI_CR1_BR);
								 }
								 else if(pSPIhandle->SPIConfig.SPI_SclkSpeed == SPI_SClk_SPEED_BY_16)
								 {
									 //Sclk boudrate controle by 16
									 tempreg |=(0x03<<SPI_CR1_BR);
								 }
								 else if(pSPIhandle->SPIConfig.SPI_SclkSpeed == SPI_SClk_SPEED_BY_32)
								 {
									 //Sclk boudrate controle by 32
									 tempreg |=(0x02<<SPI_CR1_BR);
								 }
								 else if(pSPIhandle->SPIConfig.SPI_SclkSpeed == SPI_SClk_SPEED_BY_64)
								 {
									 //Sclk boudrate controle by 64
									 tempreg |=(0x05<<SPI_CR1_BR);
								 }
								 else if(pSPIhandle->SPIConfig.SPI_SclkSpeed == SPI_SClk_SPEED_BY_128)
								 {
									 //Sclk boudrate controle by 128
									 tempreg |=(0x06<<SPI_CR1_BR);
								 }
								 else if(pSPIhandle->SPIConfig.SPI_SclkSpeed == SPI_SClk_SPEED_BY_256)
								 {
									 //Sclk boudrate controle by 256
									 tempreg |=(0x07<<SPI_CR1_BR);
								 }
								 else if(pSPIhandle->SPIConfig.SPI_DFF == SPI_DFF_8BIT)
								 {
									 //SPi data frame farmet 8 bit trasmition and receiving
									 tempreg &=~(0x01<<SPI_CR1_DFF);
								 }
								 else if(pSPIhandle->SPIConfig.SPI_DFF == SPI_DFF_16BIT)
								 {
									 //SPi data frame farmet 16 bit trasmition and receiving
									 tempreg |=(0x01<<SPI_CR1_DFF);
								 }
								 else if(pSPIhandle->SPIConfig.SPI_CPOL == SPI_CPOL_LOW)
								 {
									 //SPi clock polarity 0 in ideal state
									 tempreg &=~(0x01<<SPI_CR1_CPOL);
								 }
								 else if(pSPIhandle->SPIConfig.SPI_CPOL == SPI_CPOL_HIGH)
								 {
									 //SPi clock polarity 1 in ideal state
									 tempreg |=(0x01<<SPI_CR1_CPOL);
								 }
								 else if(pSPIhandle->SPIConfig.SPI_CPHA == SPI_CPHA_LOW)
								 {
									 //SPi The first clock transition is the first data capture edge
									 tempreg &=~(0x01<<SPI_CR1_CPHA);
								 }
								 else if(pSPIhandle->SPIConfig.SPI_CPHA == SPI_CPHA_HIGH)
								 {
									 //SPi The second clock transition is the first data capture edge
									 tempreg |=(0x01<<SPI_CR1_CPHA);
								 }
								 else if(pSPIhandle->SPIConfig.SPI_SSM == SPI_SSM_DI)
								 {
									 //SPi Software slave management disabled
									 tempreg &=~(0x01<<SPI_CR1_SSM);
								 }
								 else if(pSPIhandle->SPIConfig.SPI_SSM == SPI_SSM_EN)
								 {
									 //SPi Software slave management enabled
									 tempreg |=(0x01<<SPI_CR1_SSM);
								 }
*/





}
/*=====================================================
 * @fn				-Deint
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

void SPI_DeInit(SPI_regdef_t *pSPIx)
{
	if(pSPIx == SPI1)
	{
		SPI1_PCLK_DI();
	}
	else if(pSPIx == SPI2)
	{
		SPI2_PCLK_DI();
	}
	else if(pSPIx == SPI5)
	{
		SPI5_PCLK_DI();
	}
}

/*=====================================================
 * @fn				-flag
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
uint8_t SPI_GetFlagstatus(SPI_regdef_t *pSPIx,uint32_t FlagName)
{
	//2 is replacing at in if condition
	if(pSPIx->SPI_SR & FlagName)
	{
		return FLAG_SET;
	}
	return FLAG_RESET;

}
/*=====================================================
 * @fn				- Data Send
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
 * @Note			- This is blocking call
 *
 */

void SPI_SendData(SPI_regdef_t *pSPIx,uint8_t *pTxBuffer, uint32_t Len)
{
  while(Len>0)
  {
	  //wait untill TXE set
	  while( SPI_GetFlagstatus(pSPIx,SPI_TXE_FLAG) == FLAG_RESET );
       //2.check the DFF bit in CR1
	  if((pSPIx->SPI_CR1 & (0x01 <<SPI_CR1_DFF)))
	  {
		  //16 bit DFF
		  //1.load the data into the DR
		  pSPIx->SPI_DR =*(uint16_t*)pTxBuffer;
		  Len--;
		  Len--;
		  (uint16_t*)pTxBuffer++;
	  }
	  else
	  {
		  //8 bit DFF
		  //2.load the data into the DR
		  pSPIx->SPI_DR =*pTxBuffer;
		  Len--;
		  pTxBuffer++;
	  }
  }
}
/*=====================================================
 * @fn				-Data Receive
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

void SPI_RecieveData(SPI_regdef_t *pSPIx,uint8_t *pRxBuffer, uint32_t Len)
	{
	 while(Len>0)
	  {
		  //wait untill RXE set
		  while( SPI_GetFlagstatus(pSPIx,SPI_RXE_FLAG) == FLAG_RESET );
		   //2.check the DFF bit in CR1
		  if((pSPIx->SPI_CR1 & (0x01 <<SPI_CR1_DFF)))
		  {
			  //16 bit DFF
			  //1.load the data from DR to Rxbuffer
			   *(uint16_t*)pRxBuffer = pSPIx->SPI_DR;
			  Len--;
			  Len--;
			  (uint16_t*)pRxBuffer++;
		  }
		  else
		  {
			  //8 bit DFF
			  //2.load the data into the DR
			  *pRxBuffer=pSPIx->SPI_DR;
			  Len--;
			  pRxBuffer++;
		  }
	  }
}
/*=====================================================
 * @fn				-spi Nss pin enable
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
void SPI_SSMConfing(SPI_regdef_t *pSPIx,uint8_t  EnorDi)
{
	if(EnorDi == ENABLE)
	{
	pSPIx->SPI_CR1 |= (0x01 << SPI_CR1_SSM);
	}
	else
	{
		pSPIx->SPI_CR1 &= ~(0x01 << SPI_CR1_SSM);
	}
}

/*=====================================================
 * @fn				-spi Nss pin enable
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
void SPI_SSOEConfig(SPI_regdef_t *pSPIx,uint8_t  EnorDi)
{
	if(EnorDi == ENABLE)
	{
	pSPIx->SPI_CR2 |= (0x01 << SPI_CR2_SSOE);
	}
	else
	{
		pSPIx->SPI_CR2 &= ~(0x01 << SPI_CR2_SSOE);
	}
}



/*=====================================================
 * @fn				-spi Nss pin enable
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
void SPI_SSIConfig(SPI_regdef_t *pSPIx,uint8_t  EnorDi)
{
	if(EnorDi == ENABLE)
	{
	pSPIx->SPI_CR1 |= (0x01 << SPI_CR1_SSI);
	}
	else
	{
		pSPIx->SPI_CR1 &= ~(0x01 << SPI_CR1_SSI);
	}
}
//Spi periperal controle
void SPI_PeriperalConrol(SPI_regdef_t *pSPIx,uint8_t  EnorDi)
{
	if(EnorDi == ENABLE)
	{
	pSPIx->SPI_CR1 |= (0x01 << SPI_CR1_SPE);
	}
	else
	{
		pSPIx->SPI_CR1 &= ~(0x01 << SPI_CR1_SPE);
	}
}

// IRQ Configuration and ISR handling
/*=====================================================
 * @fn				-IRQ Configuration handling
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




void SPI_interruptIRQConfig(uint8_t IRQNumber,uint8_t EnorDi)
{

}
/*=====================================================
 * @fn				-ISR Configuration and  handling
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
void SPI_priorityIRQconfig(uint8_t IRQNumber,uint32_t IRQPriority)
{

}
/*=====================================================
 * @fn				-Init and DeInt
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
 * @fn				-Init and DeInt
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
void SPI_IRQHandler(SPI_handle_t *pHandle)
{

}
