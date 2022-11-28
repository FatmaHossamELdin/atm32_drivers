/*
 * int.h
 *
 * Created: 08/11/2022 3:57:08 AM
 *  Author: mac
 */ 


#ifndef INT_H_
#define INT_H_

#include "../../utilities/registers.h"
#include "../../utilities/bit_manipulation.h"
#include "../DIO/dio.h"

#define RESET_INT					__vector_0
#define EXT_INT_0					__vector_1
#define EXT_INT_1					__vector_2
#define EXT_INT_2					__vector_3
#define TIMER2__INT_COMP			__vector_4
#define TIMER2__INT_OVF 	 		__vector_5
#define TIMER1_INT_CAPT				__vector_6
#define TIMER1_INT_COMPA			__vector_7
#define TIMER1_INT_COMPB			__vector_8
#define TIMER1_INT_OVF				__vector_9
#define TIMER0_INT_COMP				__vector_10
#define TIMER0_INT_OVF				__vector_11
#define SPI_STC_INT					__vector_12
#define USART_RXC_INT				__vector_13
#define USART_UDRE_INT				__vector_14
#define USART_TXC_INT				__vector_15
#define ADC_INT						__vector_16
#define EE_RDY_INT					__vector_17
#define ANA_COMP_INT				__vector_18
#define TWI_INT						__vector_19
#define SPM_RDY_INT					__vector_20


#define ISR(INT_VECT) void INT_VECT(void)__attribute__((signal,used));\
void INT_VECT(void)

#define EXT_INT_0_PORT PORT_D
#define EXT_INT_1_PORT PORT_D
#define EXT_INT_2_PORT PORT_B

#define EXT_INT_0_PIN 2
#define EXT_INT_1_PIN 3
#define EXT_INT_2_PIN 2
typedef enum
{
	INT0 = 0,
	INT1,
	INT2
}extInt_type;

typedef enum
{
	LOW_LEVEL = 0,
	ANY_CHANGE,
	FALLING_EDGE,
	RISING_EDGE,
	INT2_FALLING_EDGE = 0,
	INT2_RISING_EDGE
}intSenseControl_type;


	
errorState INT_init(void);
errorState EXT_INT_init(extInt_type extInt, intSenseControl_type intSenseContol);





#endif /* INT_H_ */