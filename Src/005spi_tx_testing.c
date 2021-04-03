/*
 * stm_main.c
 *
 *  Created on: 23-Mar-2021
 *      Author: Lingaswamy Shyaga
 */

/*
 *PB15 spi2_mosi
 *PB14 spi2_miso
 *PB13 spi2_sclk
 *PB12 spi2_NSS
 * ALT funtion mode=5
 */

#include<string.h>
#include<stdio.h>
#include "stm32f410xx.h"
#include "stm32f410xx_spi_driver.h"
#include "stm32f410xx_gpio_driver.h"


void SPI2_init(void)
{




	SPI_handle_t spi_handler;
	spi_handler.pSPIx = SPI2;
	spi_handler.SPIConfig.SPI_BusConfig = SPI_BUS_CONFIG_FD;
	spi_handler.SPIConfig.SPI_DeviceMode = SPI_DEVICE_MODE_MASTER;
	spi_handler.SPIConfig.SPI_SclkSpeed = SPI_SClk_SPEED_BY_2;//generate sclk of 8MHZ
	spi_handler.SPIConfig.SPI_DFF = SPI_DFF_8BIT;
	spi_handler.SPIConfig.SPI_CPOL = SPI_CPOL_HIGH;
	spi_handler.SPIConfig.SPI_CPHA = SPI_CPHA_LOW;
	spi_handler.SPIConfig.SPI_SSM = SPI_SSM_EN;//software slave management enbled for NSS pin

	SPI_Init(&spi_handler);
}

void SPI2_GPIO_init(void)
{
	//this function is used to initialize the GPIO pins to behave as SPI2 pins
	GPIO_handle_t SPIpin;

	memset(&SPIpin,0,sizeof(SPIpin));

	SPIpin.pGPIOx = GPIOB;
	SPIpin.GPIO_PinConfig_t.GPIO_PinMode = GPIO_MODE_ALT;
	SPIpin.GPIO_PinConfig_t.GPIO_PinAltfunMode =5;
	SPIpin.GPIO_PinConfig_t.GPIO_PinOPType =GPIO_PIN_OUT_TP_PUPL;
	SPIpin.GPIO_PinConfig_t.GPIO_PinPuPdControl= GPIO_PIN_NO_PUPDR;
	SPIpin.GPIO_PinConfig_t.GPIO_Pinspeed = GPIO_PIN_SPD_HIGH;

	//sclk
	SPIpin.GPIO_PinConfig_t.GPIO_PinNumber = GPIO_PIN_13;
	GPIO_Init(&SPIpin);

	//MOSI
	SPIpin.GPIO_PinConfig_t.GPIO_PinNumber = GPIO_PIN_15;
	GPIO_Init(&SPIpin);

	//MISO
	 SPIpin.GPIO_PinConfig_t.GPIO_PinNumber = GPIO_PIN_14;
	GPIO_Init(&SPIpin);


	//NSS
	SPIpin.GPIO_PinConfig_t.GPIO_PinNumber = GPIO_PIN_12;
	GPIO_Init(&SPIpin);

}
int main()
{
	char user_data[] = "Hellow world";
	//this function is used to initialize the GPIO pins to behave as SPI2 pins
	SPI2_GPIO_init();


	//This fuction is used to initialize the SPI2 peripheral parameters
	SPI2_init();

	//this make the SSM bit is enbled
	SPI_SSMConfing(SPI2,ENABLE);

	//this make the SSI signal low and avoid the MODF error
	SPI_SSIConfig(SPI2,ENABLE);


	//enble the spi2 periperal
	SPI_PeriperalConrol(SPI2,ENABLE);
	//to send data
	SPI_SendData(SPI2,(uint8_t*)user_data,strlen(user_data));

	//Lets confirm SPI is not busy
	while(SPI_GetFlagstatus(SPI2,SPI_BUSY_FLAG));
	//disable the spi2 periperal
	SPI_PeriperalConrol(SPI2,DISABLE);

	while(1);
	return 0;

}
