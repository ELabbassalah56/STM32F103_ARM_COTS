/*********************************************************/
/*************** AUTHOR   :ELabbas salah  ****************/
/*************** DATE     : 10 NOV 2020   ****************/
/*************** SWC      :   ARM_RCC_SWC ****************/
/*************** VERSION  :    V1.0       ****************/
/*********************************************************/
#ifndef RCC_INTERFACE_H_
#define RCC_INTERFACE_H_

#define RCC_AHB    0
#define RCC_APB1	 1
#define RCC_APB2	 2
/* CLK INPUT IN PLL*/
#define HALF_HSI         0
#define HALF_HSE         1
#define HSE              3

/*                 Peripheral Clock Enable For AHB Bus                */

#define    DMA1_RCC         0
#define    DMA2_RCC         1
#define    SRAM_RCC         2
#define    FLITF_RCC        4
#define    CRC_RCC          6
#define    FSMC_RCC         8
#define    SDIO_RCC         10



/*                 Peripheral Clock Enable For APB2 Bus               */


#define    AFIO_RCC         0
#define    GPIOA_RCC        2
#define    GPIOB_RCC        3
#define    GPIOC_RCC        4
#define    GPIOD_RCC        5
#define    GPIOE_RCC        6
#define    GPIOF_RCC        7
#define    GPIOG_RCC        8
#define    ADC1_RCC         9
#define    ADC2_RCC         10
#define    TIM1_RCC         11
#define    SPI1_RCC         12
#define    TIM8_RCC         13
#define    USART1_RCC       14
#define    ADC3_RCC         15
#define    TIM9_RCC         19
#define    TIM10_RCC        20
#define    TIM11_RCC        21



/*                 Peripheral Clock Enable For APB1 Bus               */

#define    TIM2_RCC         0
#define    TIM3_RCC         1
#define    TIM4_RCC         2
#define    TIM5_RCC         3
#define    TIM6_RCC         4
#define    TIM7_RCC         5
#define    TIM12_RCC        6
#define    TIM13_RCC        7
#define    TIM14_RCC        8
#define    WWDG_RCC         11
#define    SPI2_RCC         14
#define    SPI3_RCC         15
#define    USART2_RCC       17
#define    USART3_RCC       18
#define    UART4_RCC        19
#define    UART5_RCC        20
#define    I2C1_RCC         21
#define    I2C2_RCC         22
#define    USB_RCC          23
#define    CAN_RCC          25
#define    BKP_RCC          27
#define    PWR_RCC          28
#define    DAC_RCC          29

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
#define  PLL_INPUT_CLOCK2x16    15

/* OPTIION MCO CLK SRC*/
 
#define  MCO_NO_CLK       	          	  0
#define	 MCO_SYS_CLK_SEL 		              4
#define  MCO_HSI_CLK_SEL		              5
#define  MCO_HSE_CLK_SEL		              6	
#define  MCO_PLL_CLK_DIV_BY_2_SEL         7 

/* Sel  of CSS0N */
#define RCC_CSS_OFF    0
#define RCC_CSS_ON     1

// Advanced high perforamnce bus 
#define RCC_AHBENR_DMA1_EN     0  // direct memmory access 1
#define RCC_AHBENR_DMA2_EN     1  // direct memmory access 2
#define RCC_AHBENR_SRAM_EN     2  // SRAM Interface Enable 
#define RCC_AHBENR_FLITF_EN    3  // FLITF clk  Interface enable  flash memmory interface 
#define RCC_AHBENR_CRC_EN      6  //  cyclic redundancy check interface enable 
#define RCC_AHBENR_FSMC_EN     8  //  Flexible static memory controller  interface enable
#define RCC_AHBENR_SDIO_EN     8  //  Secure digital input/output interface  enable

// Advanced Peripheral 2 bus
#define RCC_APB2_AFIO_EN        0  // Alternate function I/O and debug configuration interface enable
#define RCC_APB2_IOPA_EN        2  // PORTA I/O interface enable
#define RCC_APB2_IOPB_EN        3  // PORTB I/O interface enable
#define RCC_APB2_IOPC_EN        4  // PORTC I/O interface enable
#define RCC_APB2_ADC1_EN        9  // ADC1 interface enable
#define RCC_APB2_ADC2_EN        10 // ADC2 interface enable
#define RCC_APB2_TIM1_EN        11 // TIM1 interface enable
#define RCC_APB2_SPI1_EN        12 // SPI1 interface enable
#define RCC_APB2_TIM8_EN        13 // TIM1 interface enable
#define RCC_APB2_USART1_EN      14 // TIM1 interface enable
#define RCC_APB2_ADC3_EN        15 // ADC3 interface enable
#define RCC_APB2_TIM9_EN        19 // TIM9 interface enable
#define RCC_APB2_TIM10_EN       20 // TIM10 interface enable
#define RCC_APB2_TIM11_EN       21 // TIM11 interface enable

// Advanced Peripheral 1 bus
#define RCC_APB1_TIM2_EN         0  // TIM2 interface enable
#define RCC_APB1_TIM3_EN         1  // TIM3 interface enable
#define RCC_APB1_TIM4_EN         2  // TIM4 interface enable
#define RCC_APB1_TIM5_EN         3  // TIM5 interface enable
#define RCC_APB1_TIM6_EN         4  // TIM6 interface enable
#define RCC_APB1_TIM7_EN         5  // TIM7 interface enable
#define RCC_APB1_TIM12_EN        6  // TIM12 interface enable
#define RCC_APB1_TIM13_EN        7  // TIM13 interface enable
#define RCC_APB1_TIM14_EN        8  // TIM14 interface enable
#define RCC_APB1_WWDG_EN         11  // window watch dog clk  interface enable
#define RCC_APB1_SPI2_EN         14  // SPI2 interface enable
#define RCC_APB1_SPI3_EN         15  // SPI3 interface enable
#define RCC_APB1_USART2_EN       17  // USART2 interface enable
#define RCC_APB1_USART3_EN       18  // USART3 interface enable
#define RCC_APB1_USART4_EN       19  // USART4 interface enable
#define RCC_APB1_USART5_EN       20  // USART5 interface enable
#define RCC_APB1_I2C1_EN         21  // I2C1 interface enable
#define RCC_APB1_I2C2_EN         22  // I2C2 interface enable
#define RCC_APB1_USB_EN          23  // USB interface enable
#define RCC_APB1_CAN_EN          25  // CAN interface enable
#define RCC_APB1_BKP_EN          27  // BKP interface enable
#define RCC_APB1_PWR_EN          28  // PWR interface enable
#define RCC_APB1_DAC_EN          29  // DAC interface enable


/* void RCC_voidMcoClk(u8 Copy_u8McoClkSource)
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

void RCC_voidMcoClk(u8 Copy_u8McoClkSource);


/* void RCC_voidEnableHSI(void)
 * Function Description: Configure RCC module to operate in
   HSI(High Speed Internal) mode.
 * Processor operate by the internal RC oscillator of the uC.
 * Internal oscillator Has a Frequency of 8MHz.
 * Parameters(In) : None.
 * Parameters(Out) : None.
 *
 */

void RCC_voidEnableHSI(void);

/* void RCC_voidEnableHSE(void)
 * Function Description: Configure RCC module to operate in
   HSE(High Speed External) mode.
 * User has to connect External oscillator.
 * External oscillator Has a range 4MHz:16MHz.
 * Parameters(In) : None.
 * Parameters(Out) : None.
 * */

void RCC_voidEnableHSE(void);

/* void RCC_voidEnablePLL(u8 Copy_u8PllClkSource, u8 copy_u8PllValue)
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

void RCC_voidEnablePLL(u8 Copy_u8PllClkSource, u8 copy_u8PllValue);

/*  void RCC_voidEnableClockSecuirtySys(void)
    Function Description:  enable the clock security system. When CSSON is set,
                           the clock detector is enabled by hardware when
                           the HSE oscillator is ready, and disabled by
                           hardware if a HSE clock failure is detected.
     Inputs:
            1- RCC_CSS_ON      //  NOTE THAT BIT JUST ENABLED WITH RCC_HSE
            2- RCC_CSS_OFF
*/

void RCC_voidEnableClockSecuirtySys(void);

/*
    void RCC_voidEnableClock(u8 Copy_u8BusID,u8 Copy_u8PeripheralID)
    Function Description: Enable the bus needed to interface with other peripheral
    Inputs:
            1- Copy_u8BusID:
                           -> RCC_AHB
                           -> RCC_APB1
                           -> RCC_APB2

            2- Copy_u8PeripheralID:
                           -> blow

    Output: enable certain peripheral

*/

void RCC_voidEnableClock(u8 Copy_u8BusID,u8 Copy_u8PeripheralID);

/*
    void RCC_voidDisableClock(u8 Copy_u8BusID,u8 Copy_u8PeripheralID)
    Function Description: Disable the bus needed to interface with other peripheral
    Inputs:
            1- Copy_u8BusID:
                           -> RCC_AHB
                           -> RCC_APB1
                           -> RCC_APB2

            2- Copy_u8PeripheralID:
                            -> above

    Output: Enable certain peripheral

*/
void RCC_voidDisableClock(u8 Copy_u8BusID,u8 Copy_u8PeripheralID);

/*
 *  void RCC_voidInit(void)
 *  Function Description:function to init start_configuration which selected
 *  Input:
 *       ->NO input
 *  Output:
 *       ->No Return Value
 */
void RCC_voidInit(void);


#endif
