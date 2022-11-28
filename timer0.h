/*
 * timer0.h
 *
 * Created: 05/11/2022 2:28:05 AM
 *  Author: mac
 */ 


#ifndef TIMER0_H_
#define TIMER0_H_

#include "../../utilities/bit_manipulation.h"
#include "../../utilities/registers.h"
#include "../../utilities/data_types.h"
#include "../INT/interrupt.h"

#define NUMBER_OF_OVERFLOWS 80
#define TIMER0_INIT_VALUE   12

typedef enum
{
	TMR0_NORMAL_MODE = 0,
	TMR0_PWM_PHASE_CORRECT,
	TMR0_CTC,
	TMR0_FAST_PWM
}tmr0_mode_type;
	
typedef enum
{
	OC0_NORMAL = 0,
	OC0_TOGGLE,
	OC0_CLEAR,
	OC0_SET
}oc0_mode_type;

typedef enum
{
	NO_CLOCK = 0,
	NO_PRESCALER,
	PRESCALER_8,
	PRESCALER_64,
	PRESCALER_256,
	PRESCALER_1024,
	EXTERNAL_CLOCK_FALLING_EDGE,
	EXTERNAL_CLOCK_RISING_EDGE
}clock_select_type;
	
errorState TIMER0_init(tmr0_mode_type tmr0Mode, oc0_mode_type oc0Mode);
errorState TIMER0_start(clock_select_type clockType);
errorState TIMER0_stop(void);
errorState TIMER0_getState(uint8_t* state);
errorState TIMER0_setValue(uint8_t value);
errorState TIMER0_getValue(uint8_t* value);
errorState TIMER0_setCompareValue(uint8_t value);



#endif /* TIMER0_H_ */