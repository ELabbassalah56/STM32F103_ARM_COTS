/*********************************************************/
/*************** AUTHOR   :ELabbas salah  ****************/
/*************** DATE     : 10 NOV 2020   ****************/
/*************** SWC      :   ARM_RCC_SWC ****************/
/*************** VERSION  :    V1.0       ****************/
/*********************************************************/
#ifndef RCC_PRIVATE_H_
#define RCC_PRIVATE_H_


/*
typedef struct{
	volatile u32 CR;
	volatile u32 CFGR;
	volatile u32 CIR;
	volatile u32 APB2RSTR;
	volatile u32 APB1RSTR;
	volatile u32 AHBENR;
	volatile u32 APB2ENR;
	volatile u32 APB1ENR;
	volatile u32 BDCR;
	volatile u32 CSR;
}RCC;


// M is Refer To MCal

#define MRCC ((volatile RCC *)0x40021000)
*/
/*
   base address 0x40021000
*/
#define RCC_CR_REG        * ( (volatile u32 * const)0x40021000)
/*
   add offset  4 byte 
*/
#define RCC_CFGR_REG      * ( (volatile u32 * const)0x40021004)

#define RCC_CIR_REG       * ( (volatile u32 * const)0x40021008)

#define RCC_APB2RSTR_REG  * ( (volatile u32 * const)0x4002100C)

#define RCC_APB1RSTR_REG  * ( (volatile u32 * const)0x40021010)

#define RCC_AHBENR_REG    * ( (volatile u32 * const)0x40021014)

#define RCC_APB2ENR_REG   * ( (volatile u32 * const)0x40021018)

#define RCC_APB1ENR_REG   * ( (volatile u32 * const)0x4002101C)

#define RCC_BDCR_REG      * ( (volatile u32 * const)0x40021020)

#define RCC_CSR_REG       * ( (volatile u32 * const)0x40021024)
/*
 RCC_RC (clk control reg ) 
 define name of bit reg  
*/

#define RCC_CR_PLLRDY    25    /* Read bit */

#define RCC_CR_PLLON     24    /* Read/Write bit */

#define RCC_CR_CSSON     19     /* Read/Write bit */

#define RCC_CR_HSEBYP    18     /* Read/Write bit */

#define RCC_CR_HSERDY    17     /* Read bit */

#define RCC_CR_HSEON     16     /* Read/Write bit */

#define RCC_CR_HSIRDY    1     /* Read bit */

#define RCC_CR_HSION     0     /* Read/Write bit */

/*  RCC_CFGR ( configuration Register ) 
	define name of bit reg 
*/

#define RCC_CFGR_MCO_0    24
#define RCC_CFGR_MCO_1    25
#define RCC_CFGR_MCO_2    26

#define RCC_CFGR_USB_PRE  22

#define RCC_CFGR_PLL_MUL0 18
#define RCC_CFGR_PLL_MUL1 19
#define RCC_CFGR_PLL_MUL2 20
#define RCC_CFGR_PLL_MUL3 21

#define RCC_CFGR_PLL_XTPRE 17
#define RCC_CFGR_PLL_SCR   16


#define RCC_CFGR_SW0       0
#define RCC_CFGR_SW1       1

#define RCC_CFGR_SWS0      2
#define RCC_CFGR_SWS1      3







/* CLK DEVICE */

#define   RCC_HSE_CRY    0
#define   RCC_HSE_RC     1

/* CLK SECUIRTY SYS IN HSE */
#define  RCC_CSS_OFF   0
#define  RCC_CSS_ON    1  // Clock detector ON if the HSE oscillator is ready , OFF if not.


#endif