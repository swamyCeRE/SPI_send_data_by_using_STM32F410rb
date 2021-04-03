/*
 * stm32f410xx.h
 *
 *  Created on: Feb 14, 2021
 *      Author: Lingaswamy Shyaga
 */

#ifndef INC_STM32F410XX_H_
#define INC_STM32F410XX_H_

#include <stdint.h>

//NVIC interrupt enable register
#define NVIC_ISER0	                 (volatile uint32_t*)0xE000E100
#define NVIC_ISER1	                 (volatile uint32_t*)0xE000E104
#define NVIC_ISER2	                 (volatile uint32_t*)0xE000E108
#define NVIC_ISER3	                 (volatile uint32_t*)0xE000E10C
//NVIC interrupt clear register
#define NVIC_ICER0                    (volatile uint32_t*)0XE000E180
#define NVIC_ICER1                    (volatile uint32_t*)0XE000E184
#define NVIC_ICER2                    (volatile uint32_t*)0XE000E188
#define NVIC_ICER3                    (volatile uint32_t*)0XE000E18C
//INTERRUPT priority register



#define NVIC_PR_BASSADDRESS           (volatile uint32_t*)0xE000E400



//ARM-M7 proccessor number of priority bits implimented in priority register

#define NO_PR_BITS_IMPLEMENTED		                4

/*================================================================================*/


#define FLASH_MEM_BASE_ADDR            0X08000000U  //128 KB
#define SRAM1_BASE_ADDR                0X20000000U //32 KB
#define SRAM						   SRAM1_BASE_ADD
#define ROM_BASE_ADDR				   0X1FFF0000U

// AHBx APBx bus periperall base address


#define PERIPH_BASE_ADDR       0x40000000U
#define APB1_PERIPH_BASE_ADDR  0x40000000U
#define APB2_PERIPH_BASE_ADDR  0x40010000U
#define AHB1_PERIPH_BASE_ADDR  0x40020000U
#define AHB2_PERIPH_BASE_ADDR  0x50000000U



//AHB1 hanging GPIOS and periperals

#define GPIO_A_BASE_ADDR    			(AHB1_PERIPH_BASE_ADDR + 0x0000)
#define GPIO_B_BASE_ADDR    			(AHB1_PERIPH_BASE_ADDR + 0x0400)
#define GPIO_C_BASE_ADDR    			(AHB1_PERIPH_BASE_ADDR + 0x0800)
#define RESERVED_00         			(AHB1_PERIPH_BASE_ADDR + 0x0C00)
#define GPIO_H_BASE_ADDR    			(AHB1_PERIPH_BASE_ADDR + 0x1C00)
#define RESERVED_01                     (AHB1_PERIPH_BASE_ADDR + 0x2000)
#define LPTIM1_BASE_ADDR	            (AHB1_PERIPH_BASE_ADDR + 0x2400)
#define RESERVED_02                     (AHB1_PERIPH_BASE_ADDR + 0x2800)
#define CRC_BASE_ADDR	                (AHB1_PERIPH_BASE_ADDR + 0x3000)
#define RESERVED_03                     (AHB1_PERIPH_BASE_ADDR + 0x3400)
#define RCC_BASE_ADDR	                (AHB1_PERIPH_BASE_ADDR + 0x3800)		 //0x40023830U
#define FLASH_INTR_RGT_BASE_ADDR	    (AHB1_PERIPH_BASE_ADDR + 0x3C00)
#define RESERVED_04                     (AHB1_PERIPH_BASE_ADDR + 0x5000)
#define DMA1_BASE_ADDR	                (AHB1_PERIPH_BASE_ADDR + 0x6000)
#define DMA2_BASE_ADDR	                (AHB1_PERIPH_BASE_ADDR + 0x6400)
#define RESERVED_05                     (AHB1_PERIPH_BASE_ADDR + 0x6800)
#define RNG_BASE_ADDR	                (0x40080000 + 0x0000)
#define RESERVED_06                     (0x40080000 + 0x0400)

//APB1 hanging  and periperals

#define TIM5_BASE_ADDR					(APB1_PERIPH_BASE_ADDR + 0C00)
#define TIM6_BASE_ADDR					(APB1_PERIPH_BASE_ADDR + 1000)
#define RTC_BASE_ADDR					(APB1_PERIPH_BASE_ADDR + 2800)
#define WWDG_BASE_ADDR					(APB1_PERIPH_BASE_ADDR + 2C00)
#define IWDG_BASE_ADDR					(APB1_PERIPH_BASE_ADDR + 3000)


#define SPI2_BASE_ADDR					(APB1_PERIPH_BASE_ADDR + 3800)

#define I2S2_BASE_ADDR					(APB1_PERIPH_BASE_ADDR + 3800)
#define USART2_BASE_ADDR				(APB1_PERIPH_BASE_ADDR + 4400)
#define I2C1_BASE_ADDR					(APB1_PERIPH_BASE_ADDR + 5800)
#define I2C2_BASE_ADDR					(APB1_PERIPH_BASE_ADDR + 5400)
#define I2C4_BASE_ADDR					(APB1_PERIPH_BASE_ADDR + 6000) // INCLUDING "FM+"
#define PWR_BASE_ADDR					(APB1_PERIPH_BASE_ADDR + 7000)
#define DAC_BASE_ADDR					(APB1_PERIPH_BASE_ADDR + 7400)


//APB2 hanging and periperals/

#define TIM1_BASE_ADDR					(APB2_PERIPH_BASE_ADDR + 0000)
#define UART1_BASE_ADDR					(APB2_PERIPH_BASE_ADDR + 1000)
#define UART6_BASE_ADDR					(APB2_PERIPH_BASE_ADDR + 1400)
#define ADC1_BASE_ADDR					(APB2_PERIPH_BASE_ADDR + 2000)

#define SPI1_BASE_ADDR					(APB2_PERIPH_BASE_ADDR + 3000)

#define I2S1_BASE_ADDR					(APB2_PERIPH_BASE_ADDR + 3000)
#define SYSCFG_BASE_ADDR				(APB2_PERIPH_BASE_ADDR + 3800)
#define EXTI_BASE_ADDR					 0x40013C00U                           //(APB2_PERIPH_BASE_ADDR + 3C00)
#define TIM9_BASE_ADDR			     	(APB2_PERIPH_BASE_ADDR + 4000)
#define TIM11_BASE_ADDR					(APB2_PERIPH_BASE_ADDR + 4800)

#define SPI5_BASE_ADDR					(APB2_PERIPH_BASE_ADDR + 5000)

#define I2S5_BASE_ADDR					(APB2_PERIPH_BASE_ADDR + 5000)


/**************SPI peripheral registar structure***************/
typedef struct
{
	volatile	uint32_t SPI_CR1;
	volatile	uint32_t SPI_CR2;
	volatile	uint32_t SPI_SR;
	volatile	uint32_t SPI_DR;
	volatile	uint32_t SPI_CRCPR;
	volatile	uint32_t SPI_RXCRCR;
	volatile	uint32_t SPI_TXCRCR;
	volatile	uint32_t SPI_I2SCFGR;
	volatile	uint32_t SPI_12SPR;
}SPI_regdef_t;

/***************periperal register structure*******************/

typedef struct
{
volatile	uint32_t MODER;		//GPIO port mode register
volatile	uint32_t OTYPER;	//GPIO port output type register
volatile	uint32_t OSPEEDER;  //GPIO port output speed register
volatile	uint32_t PUPDR;		//GPIO port pull-up/pull-down register
volatile	uint32_t IDR;		//GPIO port input data register
volatile	uint32_t ODR;		//GPIO port output data register
volatile	uint32_t BSRR;		//GPIO port bit set/reset register
volatile	uint32_t LCKR;		//GPIO port configuration lock register
volatile	uint32_t AFR[2];		//GPIO alternate function low register
}GPIO_regdef_t;

//periperal structure for ETXI
typedef struct
{
volatile uint32_t 	CR;				//RCC clock control register
volatile uint32_t 	PLLCFGR;		//RCC PLL configuration register
volatile uint32_t 	CFGR;			//RCC clock configuration register
volatile uint32_t 	CIR;			//RCC clock interrupt register
volatile uint32_t 	AHB1RSTR;		//RCC AHB1 peripheral reset register

volatile uint32_t	RESERVED00;		//0x14
volatile uint32_t   RESERVED01;
volatile uint32_t	RESERVED02;		//0x1c

volatile uint32_t 	APB1RSTR;		//RCC APB1 peripheral reset register for
volatile uint32_t 	APB2RSTR;		//RCC APB2 peripheral reset register

volatile uint32_t	RESERVED03;		//0x28
volatile uint32_t	RESERVED04;		//0x2c

volatile uint32_t 	AHB1ENR;		//RCC AHB1 peripheral clock enable register

volatile uint32_t	RESERVED05;
volatile uint32_t	RESERVED06;
volatile uint32_t	RESERVED07;

volatile uint32_t 	APB1ENR;		//RCC APB1 peripheral clock enable register
volatile uint32_t 	APB2ENR;		//RCC APB2 peripheral clock enable register

volatile uint32_t	RESERVED08;
volatile uint32_t	RESERVED09;

volatile uint32_t   AHB1LPENR;		//RCC AHB1 peripheral clock enable in low power mode register

volatile uint32_t	RESERVED10;
volatile uint32_t	RESERVED11;
volatile uint32_t	RESERVED12;

volatile uint32_t   APB1LPENR;		//RCC APB1 peripheral clock enable in low power mode register
volatile uint32_t   APB2LPENR;		//RCC APB2 peripheral clock enabled in low power mode register

volatile uint32_t	RESERVED13;
volatile uint32_t	RESERVED14;

volatile uint32_t 	BDCR;			//RCC Backup domain control register
volatile uint32_t 	CSR;			//RCC clock control & status register

volatile uint32_t	RESERVED15;
volatile uint32_t	RESERVED16;

volatile uint32_t 	SSCGR;			//RCC spread spectrum clock generation register

volatile uint32_t	RESERVED17;
volatile uint32_t	RESERVED18;

volatile uint32_t 	DCKCFGR;		//RCC Dedicated Clocks Configuration Register
volatile uint32_t 	DCKCFGR2;		//RCC dedicated Clocks Configuration Register 2


}RCC_regdef_t;


//periperal structure for ETXI
typedef struct
{
 volatile uint32_t IMR;
 volatile uint32_t EMR;
 volatile uint32_t RTSR;
 volatile uint32_t FTSR;
 volatile uint32_t SWIER;
 volatile uint32_t PR;
}EXTI_regdef_t;

//periperal structure for ETXI

typedef struct
{
 volatile uint32_t MEMRMP;
 volatile uint32_t PMC;
 volatile uint32_t EXTICR[3];
 volatile uint32_t Reserved;
 volatile uint32_t CFGR2;
 volatile uint32_t CMPCR;
 volatile uint32_t CFGR;
}SYSCFG_regdef_t;

#define GPIOA	((GPIO_regdef_t*)GPIO_A_BASE_ADDR)
#define GPIOB	((GPIO_regdef_t*)GPIO_B_BASE_ADDR)
#define GPIOC	((GPIO_regdef_t*)GPIO_C_BASE_ADDR)
#define GPIOH	((GPIO_regdef_t*)GPIO_H_BASE_ADDR)

//SPI

#define SPI1    ((SPI_regdef_t*)SPI1_BASE_ADDR)
#define SPI2    (SPI_regdef_t*)0x40003800U      //((SPI_regdef_t*)SPI2_BASE_ADDR)
#define SPI5    ((SPI_regdef_t*)SPI5_BASE_ADDR)

//RCC_regdef_t  *RCC;

#define RCC		((RCC_regdef_t*)RCC_BASE_ADDR)
#define EXTI    ((EXTI_regdef_t*)EXTI_BASE_ADDR)
#define SYSCFG	((SYSCFG_regdef_t*)SYSCFG_BASE_ADDR)


//clock enable macro for GPIOx periperal

#define GPIOA_PCLK_EN()    (RCC->AHB1ENR |=(0X01<<0))
#define GPIOB_PCLK_EN()    (RCC->AHB1ENR |=(0X01<<1))
#define GPIOC_PCLK_EN()    (RCC->AHB1ENR |=(0X01<<2))
#define GPIOH_PCLK_EN()    (RCC->AHB1ENR |=(0X01<<7))

//clock enable macro for I2Cx periperal

#define I2C1_PCLK_EN()     (RCC->APB1ENR |=(0X01<<21))
#define I2C2_PCLK_EN()     (RCC->APB1ENR |=(0X01<<22))
#define I2C4_PCLK_EN()     (RCC->APB1ENR |=(0X01<<24))

//clock enable macro for SPI periperal

#define SPI2_PCLK_EN()     (RCC->APB1ENR |=(0X01<<14))
#define SPI5_PCLK_EN()     (RCC->APB1ENR |=(0X01<<15))
#define SPI1_PCLK_EN()     (RCC->APB2ENR |=(0X01<<12))

//clock enable macro for USART periperal

#define USART2_PCLK_EN()     (RCC->APB1ENR |=(0X01<<17))
#define USART1_PCLK_EN()     (RCC->APB2ENR |=(0X01<<4))
#define USART6_PCLK_EN()     (RCC->APB2ENR |=(0X01<<5))

//clock enable macro for SYSCFG periperal

#define SYSCFG_PCLK_EN()     (RCC->APB2ENR |=(0X01<<12))

//clock disable macro for GPIOx periperal

#define GPIOA_PCLK_DI()    (RCC->AHB1ENR &=~(0X01<<0))
#define GPIOB_PCLK_DI()    (RCC->AHB1ENR &=~(0X01<<1))
#define GPIOC_PCLK_DI()    (RCC->AHB1ENR &=~(0X01<<2))
#define GPIOH_PCLK_DI()    (RCC->AHB1ENR &=~(0X01<<7))


//clock disable macro for I2Cx periperal

#define I2C1_PCLK_DI()     (RCC->APB1ENR &=~(0X01<<21))
#define I2C2_PCLK_DI()     (RCC->APB1ENR &=~(0X01<<22))
#define I2C4_PCLK_DI()     (RCC->APB1ENR &=~(0X01<<24))

//clock disable macro for SPI periperal

#define SPI2_PCLK_DI()     (RCC->APB1ENR &=~(0X01<<14))
#define SPI5_PCLK_DI()     (RCC->APB1ENR &=~(0X01<<15))
#define SPI1_PCLK_DI()     (RCC->APB2ENR &=~(0X01<<12))

//clock disable macro for USART periperal

#define USART2_PCLK_DI()     (RCC->APB1ENR &=~(0X01<<17))
#define USART1_PCLK_DI()     (RCC->APB2ENR &=~(0X01<<4))
#define USART6_PCLK_DI()     (RCC->APB2ENR &=~(0X01<<5))

//clock disable macro for USART periperal

#define SYSCFG_PCLK_DI()     (RCC->APB2ENR &=~(0X01<<12))


//some generic macros
#define ENABLE    		1
#define DISABLE			0
#define SET				ENABLE
#define RESET           DISABLE
#define CLEAR			DISABLE
#define GPIO_PIN_SET	SET
#define GPIO_PIN_CLEAR	RESET
#define FLAG_RESET		RESET
#define FLAG_SET		SET
//macrose RESET gpio periperals

#define GPIOA_REG_RESET()				do{ (RCC->AHB1RSTR |=(0X01<<0));  (RCC->AHB1RSTR &=~(0X01<<0));}while(0)
#define GPIOB_REG_RESET()				do{ (RCC->AHB1RSTR |=(0X01<<1));  (RCC->AHB1RSTR &=~(0X01<<1));}while(0)
#define GPIOC_REG_RESET()				do{ (RCC->AHB1RSTR |=(0X01<<2));  (RCC->AHB1RSTR &=~(0X01<<2));}while(0)
#define GPIOH_REG_RESET()				do{ (RCC->AHB1RSTR |=(0X01<<7));  (RCC->AHB1RSTR &=~(0X01<<7));}while(0)

#define SPI1_REG_RESET()          		do{ (RCC->AHB1RSTR |=(0X01<<0));  (RCC->AHB1RSTR &=~(0X01<<0));}while(0)

//IRQ(interrupt restst) for stm32f410rb mcu
#define IRQ_NO_EXTI0        6
#define IRQ_NO_EXTI1	    7
#define IRQ_NO_EXTI2	    8
#define IRQ_NO_EXTI3	    9
#define IRQ_NO_EXTI4	    10
#define IRQ_NO_EXTI9_5      23
#define IRQ_NO_EXTI15_10	40


//IRQ priority
#define NVIC_IRQ_PRT_0       0
#define NVIC_IRQ_PRT_1       1
#define NVIC_IRQ_PRT_2       2
#define NVIC_IRQ_PRT_3       3
#define NVIC_IRQ_PRT_4       4
#define NVIC_IRQ_PRT_5       5
#define NVIC_IRQ_PRT_6       6
#define NVIC_IRQ_PRT_7       7
#define NVIC_IRQ_PRT_8       8
#define NVIC_IRQ_PRT_9       9
#define NVIC_IRQ_PRT_10      10
#define NVIC_IRQ_PRT_11      11
#define NVIC_IRQ_PRT_12      12
#define NVIC_IRQ_PRT_13      13
#define NVIC_IRQ_PRT_14      14
#define NVIC_IRQ_PRT_15      15



//Bit position defination of SPI control register 1 (SPI_CR1)
#define SPI_CR1_CPHA	  0
#define SPI_CR1_CPOL	  1
#define SPI_CR1_MSTR	  2
#define SPI_CR1_BR   	  3
#define SPI_CR1_SPE       6
#define SPI_CR1_LSBFIRST  7
#define SPI_CR1_SSI		  8
#define SPI_CR1_SSM		  9
#define SPI_CR1_RXONLY	  10
#define SPI_CR1_DFF		  11
#define SPI_CR1_CRCNEXT   12
#define SPI_CR1_CRCEN	  13
#define SPI_CR1_BIDIOE    14
#define SPI_CR1_BIDIMODE  15

//Bit position defination of SPI control register 2 (SPI_CR2)

#define SPI_CR2_RXDMAEN		0
#define SPI_CR2_TXDMAEN		1
#define SPI_CR2_SSOE		2
#define SPI_CR2_FRF         4
#define SPI_CR2_ERRIE       5
#define SPI_CR2_RXNEIE      6
#define SPI_CR2_TXEIE       7


//Bit position defination of SPI status register  SPI_SR

#define SPI_SR_RXNE			0
#define SPI_SR_TXE          1
#define SPI_SR_CHSIDE		2
#define SPI_SR_UDR			3
#define SPI_SR_CRCERR		4
#define SPI_SR_MODF			5
#define SPI_SR_OVR          6
#define SPI_SR_BSY			7
#define SPI_SR_FRE			8








/*
typedef struct
{
	uint32_t pin_mode_0  :2;
	uint32_t pin_mode_1  :2;
	uint32_t pin_mode_2  :2;
	uint32_t pin_mode_3  :2;
	uint32_t pin_mode_4  :2;
	uint32_t pin_mode_5  :2;
	uint32_t pin_mode_6  :2;
	uint32_t pin_mode_7  :2;
	uint32_t pin_mode_8  :2;
	uint32_t pin_mode_9  :2;
	uint32_t pin_mode_10 :2;
	uint32_t pin_mode_11 :2;
	uint32_t pin_mode_12 :2;
	uint32_t pin_mode_13 :2;
	uint32_t pin_mode_14 :2;
	uint32_t pin_mode_15 :2;
}GPIOx_MODER_t;

typedef struct
{
	uint32_t pin_ODR_0  :1;
	uint32_t pin_ODR_1  :1;
	uint32_t pin_ODR_2  :1;
	uint32_t pin_ODR_3  :1;
	uint32_t pin_ODR_4  :1;
	uint32_t pin_ODR_5  :1;
	uint32_t pin_ODR_6  :1;
	uint32_t pin_ODR_7  :1;
	uint32_t pin_ODR_8  :1;
	uint32_t pin_ODR_9  :1;
	uint32_t pin_ODR_10 :1;
	uint32_t pin_ODR_11 :1;
	uint32_t pin_ODR_12 :1;
	uint32_t pin_ODR_13 :1;
	uint32_t pin_ODR_14 :1;
	uint32_t pin_ODR_15 :1;
	uint32_t reserved   :16;
}GPIOx_ODR_t;



 * void GPIOA_PCLK_EN(void)
{
	RCC->AHB1ENR |=(0x01<<0);

}
 */

#endif /* INC_STM32F410XX_H_ */
