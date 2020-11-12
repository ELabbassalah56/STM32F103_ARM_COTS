/*********************************************************/
/*************** AUTHOR   :ELabbas salah  ****************/
/*************** DATE     : 10 NOV 2020   ****************/
/*************** SWC      :   ARM_RCC_SWC ****************/
/*************** VERSION  :    V1.0       ****************/
/*********************************************************/

/*LIB LAYER*/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

/*MCAL LAYER*/
#include "RCC_interface..h"
#include "RCC_private.h"
#include "RCC_config.h"

Void RCC_VoidInit(Void)
{
	/*******************************************
	 - This function enables system clock based
	   on the user configuration.
	 *******************************************/
#if (ENABLE_CLK_SECUIRTY_SYS)
	RCC_VoidEnableClockSecuirtySys();
#endif
#if (ENABLE_HSI)
	RCC_VoidEnableHSI();
#elif (ENABLE_HSE)
	RCC_VoidEnableHSE();
#elif (ENABLE_PLL)
	RCC_VoidEnablePLL(PLL_CLK_SRC, PLL_MUL_FACTOR);
#else
#error No system clock is enabled
#endif
#if (ENABLE_MCO)
	RCC_VoidMcoClk(MCO_PRESCALER_FACTOR);
#endif
}

Void RCC_VoidEnableHSI(Void)
{
	u8 local_u8HsiCounter = 0;
	/* ENABLE HSI CLK  */
	SET_BIT(RCC_CR_REG, RCC_CR_HSION);
	/*  wait untile reg rdy */
	while ((!GET_BIT(RCC_CR_REG, RCC_CR_HSIRDY)) && (local_u8HsiCounter < 256))
	{
		local_u8HsiCounter++;
	}
	/* Select HSI switch system */
	CLEAR_BIT(RCC_CFGR_REG, RCC_CFGR_SW0);
	CLEAR_BIT(RCC_CFGR_REG, RCC_CFGR_SW1);
}

Void RCC_VoidEnableHSE(Void)
{
	u8 local_u8HseCounter = 0;
	/* ENABLE HSE CLK  */
	SET_BIT(RCC_CR_REG, RCC_CR_HSEON);
	/*  wait untile reg rdy */
	while ((!GET_BIT(RCC_CR_REG, RCC_CR_HSERDY)) && (local_u8HseCounter < 256))
	{
		local_u8HseCounter++;
	}
	/* Select HSE switch system */
	SET_BIT(RCC_CFGR_REG, RCC_CFGR_SW0);
	CLEAR_BIT(RCC_CFGR_REG, RCC_CFGR_SW1);
}

Void RCC_VoidEnablePLL(u8 Copy_u8PllClkSource, u8 copy_u8PllValue)
{
	u8 local_u8PllCounter = 0;
	/* PLL Enable */
	SET_BIT(RCC_CR_REG, RCC_CR_PLLON);
	/* wait untile be ready */
	while ((!GET_BIT(RCC_CR_REG, RCC_CR_PLLRDY)) && (local_u8PllCounter < 256))
	{
		local_u8PllCounter++;
	}
	/* Select HSE switch system */
	CLEAR_BIT(RCC_CFGR_REG, RCC_CFGR_SW0);
	SET_BIT(RCC_CFGR_REG, RCC_CFGR_SW1);
	/* switch on pllClkSource */
	switch (Copy_u8PllClkSource)
	{

	case Half_HSI:
		CLEAR_BIT(RCC_CFGR_REG, RCC_CFGR_PLL_SCR);
		break;
	case Half_HSE:
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
}

Void RCC_VoidEnableClock(u8 Copy_u8BusID, u8 Copy_u8PeripheralID)
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
Void RCC_VoidDisableClock(u8 Copy_u8BusID, u8 Copy_u8PeripheralID)
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
Void RCC_VoidMcoClk(u8 Copy_u8McoClkSource)
{
	RCC_CFGR_REG = (RCC_CFGR_REG & 0xF8FFFFFF) | (Copy_u8McoClkSource << RCC_CFGR_MCO_0);
}

Void RCC_VoidEnableClockSecuirtySys(Void)
{
	SET_BIT(RCC_CR_REG, RCC_CR_CSSON);
}