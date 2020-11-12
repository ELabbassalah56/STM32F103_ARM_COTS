/*********************************************************/
/*************** AUTHO#define ELab_INPUT_CLOCK*************/
/*************** DATE #define  10 _INPUT_CLOCK*************/
/*************** SWC  #define    A_INPUT_CLOCK*************/
/*************** VERSI#define     _INPUT_CLOCK*************/
/*********************************************************/
#ifndef RCC_INTERFACE_H_
#define RCC_INTERFACE_H_

#define RCC_AHB          0
#define RCC_APB1	 1
#define RCC_APB2	 2
/* CLK INPUT IN PLL*/
#define HALF_HSI         0
#define HALF_HSE         1
#define HSE              3

/* CLK MULTI INPUT FACTOR */

#define  PLL_INPUT_CLOCKx2      0
#define  PLL_INPUT_CLOCKx3      1
#define  PLL_INPUT_CLOCKx4      2
#define  PLL_INPUT_CLOCKx5      3
#define  PLL_INPUT_CLOCKx6      4
#define  PLL_INPUT_CLOCKx7      5
#define  PLL_INPUT_CLOCKx8      6 
#define  PLL_INPUT_CLOCKx9      7
#define  PLL_INPUT_CLOCKx10     8
#define  PLL_INPUT_CLOCKx11     9
#define  PLL_INPUT_CLOCKx12     10
#define  PLL_INPUT_CLOCKx13     11
#define  PLL_INPUT_CLOCKx14     12
#define  PLL_INPUT_CLOCKx15     13
#define  PLL_INPUT_CLOCKx16     14
#define  PLL_INPUT_CLOCKx16     15

/* OPTIION MCO CLK SRC*/
 
#define  MCO_NO_CLK       		  0
#define	 MCO_SYS_CLK_SEL 		  4
#define  MCO_HSI_CLK_SEL		  5
#define  MCO_HSE_CLK_SEL		  6	
#define  MCO_PLL_CLK_DIV_BY_2_SEL         7 

/* Sel  of CSS0N */
#define RCC_CSS_OFF    0
#define RCC_CSS_ON     1


/* void RCC_VoidMcoClk(u8 Copy_u8McoClkSource)
 * Function Description: Select specific clock to be generated
   by MCO pin.
 * Parameters(In) : - Copy_u8McoClkSource --> The clock source to
   the MCO.
 * There are three options for Copy_u8McoClkSource:
    - MCO_No_clock
    - MCO_System_clock_selected
    - MCO_HSI_clock_selected
    - MCO_HSE_clock_selected
    - MCO_PLL_clock_divided_by_2_selected
 * Parameters(Out) : None.
 * */

Void RCC_VoidMcoClk(u8 Copy_u8McoClkSource);


/* void RCC_VoidEnableHSI(void)
 * Function Description: Configure RCC module to operate in
   HSI(High Speed Internal) mode.
 * Processor operate by the internal RC oscillator of the uC.
 * Internal oscillator Has a Frequency of 8MHz.
 * Parameters(In) : None.
 * Parameters(Out) : None.
 *
 */

Void RCC_VoidEnableHSI(Void);

/* void RCC_VoidEnableHSE(void)
 * Function Description: Configure RCC module to operate in
   HSE(High Speed External) mode.
 * User has to connect External oscillator.
 * External oscillator Has a range 4MHz:16MHz.
 * Parameters(In) : None.
 * Parameters(Out) : None.
 * */

Void RCC_VoidEnableHSE(Void);

/* void RCC_VoidEnablePLL(u8 Copy_u8PllClkSource, u8 copy_u8PllValue)
 * Function Description: Configure RCC module to operate in
   PLL(Phase Locked Loop) mode.
 * User can operate on either External oscillator, External
   oscillator divided by 2 or the Internal RC oscillator
   divided by 2.
 * External oscillator Has a range 4MHz:16MHz.
 * Internal oscillator Has a Frequency of 8MHz.
 * Parameters(In) : - Copy_u8PllClkSource --> The clock source to
   the PLL.
    - PLL_Value --> the values that are used to choose the PLL
      Multiplication factor.
 * There are three options for Copy_u8PllClkSource:
    - Half_HSI
    - Half_HSE
    - HSE
 * There are multiple options for copy_u8PllValue:
    - PLL_input_clock_x2
    - PLL_input_clock_x3
    - PLL_input_clock_x4
    - PLL_input_clock_x5
    - PLL_input_clock_x6
    - PLL_input_clock_x7
    - PLL_input_clock_x8
    - PLL_input_clock_x9
    - PLL_input_clock_x10
    - PLL_input_clock_x11
    - PLL_input_clock_x12
    - PLL_input_clock_x13
    - PLL_input_clock_x14
    - PLL_input_clock_x15
    - PLL_input_clock_x16
 * Parameters(Out) : None.
 * */

Void RCC_VoidEnablePLL(u8 Copy_u8PllClkSource, u8 copy_u8PllValue);

/*  void RCC_VoidEnableClockSecuirtySys(Void)
    function discribtion :  enable the clock security system. When CSSON is set, the
clock detector is enabled by hardware when the HSE oscillator is ready, and disabled by
hardware if a HSE clock failure is detected.

         - RCC_CSS_ON      //  NOTE THAT BIT JUST ENABLED WITH RCC_HSE 
         - RCC_CSS_OFF
*/
Void RCC_VoidEnableClockSecuirtySys(Void);


Void RCC_VoidEnableClock(u8 Copy_u8BusID,u8 Copy_u8PeripheralID);

Void RCC_VoidDisableClock(u8 Copy_u8BusID,u8 Copy_u8PeripheralID);





#endif