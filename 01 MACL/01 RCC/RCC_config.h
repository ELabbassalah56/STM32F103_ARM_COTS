/*********************************************************/
/*************** AUTHOR   :ELabbas salah  ****************/
/*************** DATE     : 10 NOV 2020   ****************/
/*************** SWC      :   ARM_RCC_SWC ****************/
/*************** VERSION  :    V1.0       ****************/
/*********************************************************/
#ifndef RCC_CONFIG_H_
#define RCC_CONFIG_H_


/* Enable Clock secuirty sys */
#define  ENABLE_CLK_SECUIRTY_SYS    RCC_CSS_OFF 
/* Choose HSI as system CLK */
#define ENABLE_HSI						0

/* Choose HSE as system CLK */
#define ENABLE_HSE						0
/* Choose PLL as system CLK */
#define ENABLE_PLL						1

#if (ENABLE_PLL)

/* * * * * * * * * * * *
 *   PLL CLK Source    *
 * * * * * * * * * * * */
/*
 	HALF_HSI,
	HALF_HSE,
	HSE
  */
#define PLL_CLK_SRC					HSE
/* * * * * * * * * * * * * * *
 * PLL Multiplication Factor *
 * * * * * * * * * * * * * * */
/*
	 PLL_INPUT_CLOCKx2,
	 PLL_INPUT_CLOCKx3,
	 PLL_INPUT_CLOCKx4,
	 PLL_INPUT_CLOCKx5,
	 PLL_INPUT_CLOCKx6,
	 PLL_INPUT_CLOCKx7,
	 PLL_INPUT_CLOCKx8,
	 PLL_INPUT_CLOCKx9,
	 PLL_INPUT_CLOCKx10,
	 PLL_INPUT_CLOCKx11,
	 PLL_INPUT_CLOCKx12,
	 PLL_INPUT_CLOCKx13,
	 PLL_INPUT_CLOCKx14,
	 PLL_INPUT_CLOCKx15,
	 PLL_INPUT_CLOCKx16,
	*/
#define PLL_MUL_FACTOR		 PLL_INPUT_CLOCKx16
#endif

#define ENABLE_MCO						0
#if (ENABLE_MCO)

/* * * * * * * * * * * * * * *
 *   MCO Prescaler Factor    *
 * * * * * * * * * * * * * * */

/*
	MCO_NO_CLK,
	MCO_SYS_CLK_SEL,
	MCO_HSI_CLK_SEL,
	MCO_HSE_CLK_SEL,
	MCO_PLL_CLK_DIV_BY_2_SEL
 */
#define MCO_PRESCALER_FACTOR			MCO_PLL_CLK_DIV_BY_2_SEL
#endif

#endif