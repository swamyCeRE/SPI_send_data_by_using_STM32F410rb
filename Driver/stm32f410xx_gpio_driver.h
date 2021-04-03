/*
 * stm32f410xx_driver.h
 *
 *  Created on: 15-Feb-2021
 *      Author: Lingaswamy Shyaga
 */
#include "stm32f410xx.h"

#ifndef INC_STM32F410XX_DRIVER_H_
#define INC_STM32F410XX_DRIVER_H_

typedef struct
{
	uint8_t GPIO_PinNumber;			//@GPIO PASSIBLE PIN NUMBERS
	uint8_t GPIO_PinMode;			//@GPIO PASSIBLE MODES
	uint8_t GPIO_Pinspeed; 			//@GPIO PIN OUTPUT SPEED
	uint8_t GPIO_PinPuPdControl;	//@GPIO PULLUP AND  PULLDOWN
	uint8_t GPIO_PinOPType;			//@GPIO PIN OUTPUT TYPE
	uint8_t GPIO_PinAltfunMode;
}GPIO_PinConfig_t;

//this handle structure for a GPIO pin

typedef struct
{
	GPIO_regdef_t *pGPIOx;				//this holds the base address of the GPIO port to which the pin belongs
	GPIO_PinConfig_t GPIO_PinConfig_t;  //this holds GPIO pin  confinguration settings
}GPIO_handle_t;

//@GPIO PASSIBLE PIN NUMBERS
#define     GPIO_PIN_0			0
#define     GPIO_PIN_1			1
#define     GPIO_PIN_2			2
#define     GPIO_PIN_3			3
#define     GPIO_PIN_4			4
#define     GPIO_PIN_5			5
#define     GPIO_PIN_6			6
#define     GPIO_PIN_7			7
#define     GPIO_PIN_8			8
#define     GPIO_PIN_9			9
#define     GPIO_PIN_10			10
#define     GPIO_PIN_11			11
#define     GPIO_PIN_12		    12
#define     GPIO_PIN_13			13
#define     GPIO_PIN_14			14
#define     GPIO_PIN_15			15

//@GPIO PASSIBLE MODES
#define     GPIO_MODE_IN     	0
#define 	GPIO_MODE_OUT    	1
#define		GPIO_MODE_ALT    	2
#define 	GPIO_MODE_ANALOG 	3
#define 	GPIO_MODE_IT_FT		4 //IT=INPUT ,FT=FALLING EDGE
#define     GPIO_MODE_IT_RT		5 //IT=INPUT ,RT=RISSING EDGE
#define     GPIO_MODE_IT_RFT	6 //IT=INPUT TRIGGER,RTF=RISSING EDGE FALLING EDGE

//@GPIO PIN OUTPUT SPEED
#define   GPIO_PIN_SPD_LOW		O
#define   GPIO_PIN_SPD_MEDIE	1
#define   GPIO_PIN_SPD_HIGH		2
#define   GPIO_PIN_SPD_VHIGH	3


//@GPIO PULLUP AND  PULLDOWN
#define  GPIO_PIN_NO_PUPDR      0
#define  GPIO_PIN_PUPDR_UP      1
#define  GPIO_PIN_PUPDR_DOWN    2



//@GPIO PIN OUTPUT TYPE

#define GPIO_PIN_OUT_TP_PUPL    0	//OUTPUT PUSH-PULL
#define GPIO_PIN_OUT_TP_ODRN    1   //OUTPUT OPEN_DRAIN


#define GPIO_BASEADDRESS_TO_CODE(x)    ((x==GPIOA)? 0:\
									   (x==GPIOB) ? 1:\
									   (x==GPIOC) ? 2:\
									   (x==GPIOH) ? 3:0)









/*================================API supported this prototypes==============================*/

/*========================================prototypes===========================================*/
//periperal clock set

void GPIO_PerlClkControle(GPIO_regdef_t *pGPIOx,uint8_t EnorDi);


//Init and DeInt

void GPIO_Init(GPIO_handle_t *pGPIOhandle);
void GPIO_DiInit(GPIO_regdef_t *pGPIOx);

//data read and write

uint8_t GPIO_ReadfromInputPin(GPIO_regdef_t *pGPIOx,uint8_t PinNumber);
uint16_t GPIO_ReadfromInputport(GPIO_regdef_t *pGPIOx);
void GPIO_WritetOutputPin(GPIO_regdef_t *pGPIOx,uint8_t PinNumber,uint8_t value);
void GPIO_WritetOoutputport(GPIO_regdef_t *pGPIOx,uint16_t value);
void GPIO_ToggleOutputPin(GPIO_regdef_t *pGPIOx,uint8_t PinNumber);

//Confinguration Handler

void GPIO_interruptIRQConfig(uint8_t IRQNumber,uint8_t EnorDi);
void GPIO_priorityIRQconfig(uint8_t IRQNumber,uint32_t IRQPriority);
void GPIO_IRQHandler(uint8_t PinNumber);








#endif /* INC_STM32F410XX_DRIVER_H_ */
