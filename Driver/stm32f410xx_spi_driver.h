/*
 * stm32f410rb_spi_driver.h
 *
 *  Created on: 19-Mar-2021
 *      Author: Lingaswamy Shyaga
 */


#ifndef INC_STM32F410XX_SPI_DRIVER_H_


#include<stdint.h>
#include "stm32f410xx.h"


/*
 * Configuration structure for SPIx periperal
 */

typedef struct
{
	uint8_t SPI_DeviceMode;
	uint8_t SPI_BusConfig;
	uint8_t SPI_SclkSpeed;
	uint8_t SPI_DFF;    //diferent speeds
	uint8_t SPI_CPOL;
	uint8_t SPI_CPHA;
	uint8_t SPI_SSM;
}SPI_Confing_t;



/*
 *Handle structure for SPIx periperal
 */
typedef struct
{
	SPI_regdef_t   *pSPIx; //this holds the base addres of SPIx(x:0,1,2) peripheral
	SPI_Confing_t   SPIConfig;
}SPI_handle_t;


//SPI_DeviceMode
#define SPI_DEVICE_MODE_MASTER  	  1
#define SPI_DEVICE_MODE_SLAVE         0

//spi_busconfig
#define SPI_BUS_CONFIG_FD             1
#define SPI_BUS_CONFIG_HD             2
#define SPI_BUS_CONFIG_SIMPLEX_RXONLY 3

//spi_sClk_speed

#define SPI_SClk_SPEED_BY_2		    	  0
#define SPI_SClk_SPEED_BY_4			      1
#define SPI_SClk_SPEED_BY_8			      2
#define SPI_SClk_SPEED_BY_16			  3
#define SPI_SClk_SPEED_BY_32			  4
#define SPI_SClk_SPEED_BY_64			  5
#define SPI_SClk_SPEED_BY_128			  6
#define SPI_SClk_SPEED_BY_256			  7


//spi_DFF

#define SPI_DFF_8BIT	          0
#define SPI_DFF_16BIT	          1

//SPI_CPOL
#define SPI_CPOL_HIGH	          1
#define SPI_CPOL_LOW	          0

//SPI_CPHA
#define SPI_CPHA_HIGH	                  1
#define SPI_CPHA_LOW	                  0


//SPI_SSM
#define SPI_SSM_EN		                  1
#define SPI_SSM_DI		                  0



#define SPI_RXE_FLAG				(0x01 << SPI_SR_RXNE)
#define SPI_TXE_FLAG				(0x01 << SPI_SR_TXE)
#define SPI_CHSIDE_FLAG				(0x01 << SPI_SR_CHSIDE)
#define SPI_UDR_FLAG				(0x01 << SPI_SR_UDR)
#define SPI_CRCERR_FLAG				(0x01 << SPI_SR_CRCERR)
#define SPI_MODF_FLAG				(0x01 << SPI_SR_MODF)
#define SPI_OVR_FLAG				(0x01 << SPI_SR_OVR)
#define SPI_BUSY_FLAG				(0x01 << SPI_SR_BSY)
#define SPI_FRE_FLAG				(0x01 << SPI_SR_FRE)












/******************************************************************************************
 * 			 APIs supported by this driver
 * 	for more infromation  about the APIs please check the function definitions
 *
 *******************************************************************************************
 */



//periperal clock set

void SPI_PerlClkControle(SPI_regdef_t *pSPIx,uint8_t EnorDi);


//Init and DeInt

void SPI_Init(SPI_handle_t *pSPIhandle);
void SPI_DeInit(SPI_regdef_t *pSPIx);


// Data send and Receive

void SPI_SendData(SPI_regdef_t *pSPIx,uint8_t *pTxBuffer, uint32_t Len);

void SPI_RecieveData(SPI_regdef_t *pSPIx,uint8_t *pRxBuffer, uint32_t Len);

//flag set or reset

uint8_t SPI_GetFlagstatus(SPI_regdef_t *pSPIx,uint32_t FlagName);

//spi2 SSM bit enable

void SPI_SSMConfing(SPI_regdef_t *pSPIx,uint8_t  EnorDi);

//spi2 NSS by using SSI bit enable

void SPI_SSIConfig(SPI_regdef_t *pSPIx,uint8_t  EnorDi);

//spi2 NSS by using SSOE bit enable

void SPI_SSOEConfig(SPI_regdef_t *pSPIx,uint8_t  EnorDi);

//Other Periperals control APIs

void SPI_PeriperalConrol(SPI_regdef_t *pSPIx,uint8_t  EnorDi);

// IRQ Configuration and ISR handling

void SPI_interruptIRQConfig(uint8_t IRQNumber,uint8_t EnorDi);
void SPI_priorityIRQconfig(uint8_t IRQNumber,uint32_t IRQPriority);
void SPI_IRQHandler(SPI_handle_t *pHandle);





#define INC_STM32F410XX_SPI_DRIVER_H_



#endif /* INC_STM32F410XX_SPI_DRIVER_H_ */
