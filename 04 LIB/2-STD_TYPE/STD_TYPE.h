/********************************************************/
/*************** AUTHOR   :ELabbas salah ****************/
/*************** DATE     :  10 NOV 2020 ****************/
/*************** SWC      :  ARM STDTYPE ****************/
/*************** VERSION  :    V1.1      ****************/
/********************************************************/
#ifndef  STD_TYPE_H_
#define  STD_TYPE_H_
//boolleen

#define FALSE       0

#define TRUE        1


#define NULL      ((void *)0)

/* Void */ 

typedef   void    Void;


/* Typedef opertor */

#define  __SIZEOF(DataType)            sizeof(DataType)    

/* unsigned Type */
typedef   unsigned char             u8;      // 0 ...... 255//
typedef   unsigned short int       u16;      // 0 ...... 65536 //
typedef   unsigned long int        u32;      // 0 ...... 4294967296 //
typedef   unsigned long long int   u64;      // 0 ...... 18446744073709551615 //
typedef   float                   f32;      //4 Byte 
typedef   double                  f64;      //8 Byte

/* signed Type */
typedef   signed char               s8;      // -128 ...... +127 //
typedef   signed short int         s16;      // -32768 ...... +32767 //
typedef   signed long int          s32;      // -2147483648 ...... +2147483647     //
typedef   signed long long int     s64;      // -9223372037709551618 ...... +9223372037709551617 //

/* ERROR STATUS CHECK */

typedef enum{ 
	          ERROR_POSITIVE= 0,
              ERROR_NEGATIVE= -1
            }CheckError;
        

#endif