/*********************************************************/
/*************** AUTHOR   :ELabbas salah  ****************/
/*************** DATE     : 10 NOV 2020   ****************/
/*************** SWC      :   ARMBIT_MATH ****************/
/*************** VERSION  :    V1.1       ****************/
/*********************************************************/

#ifndef   BIT_MATH_H_
#define   BIT_MATH_H_
//BIT OPERATION
#define SET_BIT(Reg, BitNum) (Reg |= (1 << BitNum))
#define CLEAR_BIT(Reg, BitNum) (Reg &= ~(1 << BitNum))
#define TOGGLE_BIT(Reg, BitNum) (Reg ^= (1 << BitNum))
#define GET_BIT_V0(Reg, BitNum) ((Reg >> BitNum) & 1)
#define GET_BIT_V1(Reg, BitNum) (!!(Reg & (1 << BitNum)))

#endif