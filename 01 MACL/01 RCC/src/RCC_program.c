/*********************************************************/
/*************** AUTHOR   :ELabbas salah  ****************/
/*************** DATE     : 10 NOV 2020   ****************/
/*************** SWC      :   ARM_RCC_SWC ****************/
/*************** VERSION  :    V1.0       ****************/
/*********************************************************/

/*LIB LAYER*/
#include "STD_TYPE.h"
#include "BIT_MATH.h"

/*MCAL LAYER*/
#include "RCC_private.h"
#include "RCC_config.h"
#include "RCC_interface.h"

void RCC_voidInit(void)
{
	/*******************************************
	 - This function enables system clock based
	   on the user configuration.
	 *******************************************/
#if (ENABLE_CLK_SECUIRTY_SYS)
	RCC_voidEnableClockSecuirtySys();
#endif
#if (ENABLE_HSI)
	RCC_voidEnableHSI();
#elif (ENABLE_HSE)
	RCC_voidEnableHSE();
#elif (ENABLE_PLL)
	RCC_voidEnablePLL(PLL_CLK_SRC, PLL_MUL_FACTOR);
#else
#error No system clock is enabled
#endif
#if (ENABLE_MCO)
	RCC_voidMcoClk(MCO_PRESCALER_FACTOR);
#endif
}

void RCC_voidEnableHSI(void)
{
	u32 LOC_u32TimeOut = 0;
	/* ENABLE HSI CLK  */
	SET_BIT(RCC_CR_REG, RCC_CR_HSION);
	/*  wait untile reg rdy */
	while ((!GET_BIT(RCC_CR_REG, RCC_CR_HSIRDY)) && (LOC_u32TimeOut < 100000)){LOC_u32TimeOut++;}
	if( LOC_u32TimeOut >= 100000 ){ /*TimeOut*/ }
	/* Select HSI switch system */
	CLEAR_BIT(RCC_CFGR_REG, RCC_CFGR_SW0);
	CLEAR_BIT(RCC_CFGR_REG, RCC_CFGR_SW1);
}

void RCC_voidEnableHSE(void)
{
	u32 LOC_u32TimeOut = 0;
	/* ENABLE HSE CLK  */
	SET_BIT(RCC_CR_REG, RCC_CR_HSEON);
	/*  wait untile reg rdy */
	while ((!GET_BIT(RCC_CR_REG, RCC_CR_HSERDY)) && (LOC_u32TimeOut < 100000)){LOC_u32TimeOut++;}
	if( LOC_u32TimeOut >= 100000 ){ /*TimeOut*/ }
	/* Select HSE switch system */
	SET_BIT(RCC_CFGR_REG, RCC_CFGR_SW0);
	CLEAR_BIT(RCC_CFGR_REG, RCC_CFGR_SW1);
}

void RCC_voidEnablePLL(u8 Copy_u8PllClkSource, u8 copy_u8PllValue)
{
	u32 LOC_u32TimeOut = 0;
	/* wait untile be ready */
	while ((!GET_BIT(RCC_CR_REG, RCC_CR_PLLRDY)) && (LOC_u32TimeOut < 100000)){LOC_u32TimeOut++;}
	if( LOC_u32TimeOut >= 100000 ){ /*TimeOut*/ }
	/* Select HSE switch system */
	CLEAR_BIT(RCC_CFGR_REG, RCC_CFGR_SW0);
	SET_BIT(RCC_CFGR_REG, RCC_CFGR_SW1);
	/* switch on pllClkSource */
	switch (Copy_u8PllClkSource)
	{

	case HALF_HSI:
		CLEAR_BIT(RCC_CFGR_REG, RCC_CFGR_PLL_SCR);
		break;
	case HALF_HSE:
		SET_BIT(RCC_CFGR_REG, RCC_CFGR_PLL_SCR);
		SET_BIT(RCC_CFGR_REG, RCC_CFGR_PLL_XTPRE);
		break;
	case HSE:
		SET_BIT(RCC_CFGR_REG, RCC_CFGR_PLL_SCR);
		CLEAR_BIT(RCC_CFGR_REG, RCC_CFGR_PLL_XTPRE);
		break;
	default:

		break;
	}
	RCC_CFGR_REG = (RCC_CFGR_REG & 0xFFC3FFFF) | (copy_u8PllValue << RCC_CFGR_PLL_MUL0);
		/* PLL Enable */
	SET_BIT(RCC_CR_REG, RCC_CR_PLLON);
}

void RCC_voidEnableClock(u8 Copy_u8BusID, u8 Copy_u8PeripheralID)
{
	if (Copy_u8PeripheralID < 32)
	{
		switch (Copy_u8BusID)
		{
		case RCC_AHB:
			SET_BIT(RCC_AHBENR_REG, Copy_u8PeripheralID);
			break;
		case RCC_APB1:
			SET_BIT(RCC_APB1ENR_REG, Copy_u8PeripheralID);
			break;
		case RCC_APB2:
			SET_BIT(RCC_APB2ENR_REG, Copy_u8PeripheralID);
			break;
		default:

			break;
		}
	}
}
void RCC_voidDisableClock(u8 Copy_u8BusID, u8 Copy_u8PeripheralID)
{
	if (Copy_u8PeripheralID < 32)
	{
		switch (Copy_u8BusID)
		{
		case RCC_AHB:
			CLEAR_BIT(RCC_AHBENR_REG, Copy_u8PeripheralID);
			break;
		case RCC_APB1:
			CLEAR_BIT(RCC_APB1ENR_REG, Copy_u8PeripheralID);
			break;
		case RCC_APB2:
			CLEAR_BIT(RCC_APB2ENR_REG, Copy_u8PeripheralID);
			break;
		default:

			break;
		}
	}
}
void RCC_voidMcoClk(u8 Copy_u8McoClkSource)
{
	RCC_CFGR_REG = (RCC_CFGR_REG & 0xF8FFFFFF) | (Copy_u8McoClkSource << RCC_CFGR_MCO_0);
}

void RCC_voidEnableClockSecuirtySys(void)
{
	SET_BIT(RCC_CR_REG, RCC_CR_CSSON);
}
