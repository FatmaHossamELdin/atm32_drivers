/*
 * timer0.c
 *
 * Created: 05/11/2022 2:27:41 AM
 *  Author: mac
 */ 

#include "timer0.h"


uint32_t overflowCounter = 0;
errorState timer0SetValueError = OK;

ISR(TIMER0_INT_OVF)
{
	timer0SetValueError = TIMER0_setValue(TIMER0_INIT_VALUE);
	
	if (overflowCounter < NUMBER_OF_OVERFLOWS)
	{
		overflowCounter++;
	}
}

errorState TIMER0_init(tmr0_mode_type tmr0Mode, oc0_mode_type oc0Mode)
{
	errorState errorRetun = OK;
	switch (tmr0Mode)
	{
		case TMR0_NORMAL_MODE:
		//set mode
		CLEAR_BIT(TCCR0,3);
		CLEAR_BIT(TCCR0,6);
		
		//enable ovf interrupt
		SET_BIT(TIMSK,0);
		break;
		
		case TMR0_PWM_PHASE_CORRECT:
		//set mode
		CLEAR_BIT(TCCR0,3);
		SET_BIT(TCCR0,6);
		
		//enable ovf interrupt
		SET_BIT(TIMSK,0);
		break;
		
		case TMR0_CTC:
		//set mode
		SET_BIT(TCCR0,3);
		CLEAR_BIT(TCCR0,6);
		
		//enable compare match interrupt
		SET_BIT(TIMSK,1);
		break;
		
		case TMR0_FAST_PWM:
		//set mode
		SET_BIT(TCCR0,3);
		SET_BIT(TCCR0,6);
		
		//enable ovf interrupt
		SET_BIT(TIMSK,0);
		break;
		
		default:
		errorRetun = NOT_OK;
		break;
	}
	
	switch (oc0Mode)
	{
		case OC0_NORMAL:
		// set oc0 mode
		CLEAR_BIT(TCCR0,4);
		CLEAR_BIT(TCCR0,5);
		
		break;
		
		case OC0_TOGGLE:
		// set oc0 mode
		SET_BIT(TCCR0,4);
		CLEAR_BIT(TCCR0,5);
		
		//set oc0 as output
		SET_BIT(DDRB,3);
		break;
		
		case OC0_CLEAR:
		// set oc0 mode
		CLEAR_BIT(TCCR0,4);
		SET_BIT(TCCR0,5);
		//set oc0 as output
		SET_BIT(DDRB,3);
		break;
		
		case OC0_SET:
		// set oc0 mode
		SET_BIT(TCCR0,4);
		SET_BIT(TCCR0,5);
		//set oc0 as output
		SET_BIT(DDRB,3);
		break;
		
		default:
		errorRetun = NOT_OK;
		break;
	}
	return errorRetun;
}

errorState TIMER0_start(clock_select_type clockType)
{
	errorState errorReturn = OK;
	//clear 1st 3 bits 
	TCCR0 &= 0b11111000;
	//set clock type
	TCCR0 |= clockType;
	
	return errorReturn;
}
errorState TIMER0_stop(void)
{
	errorState errorReturn = OK;
	//stop clock
	TCCR0 &= 0b11111000;
	return errorReturn;
}
errorState TIMER0_getState(uint8_t* state)
{
	errorState errorReturn = OK;
	*state = (GET_BIT(TIFR,0)) | (GET_BIT(TIFR,1) <<1);
	return errorReturn;
}
errorState TIMER0_setValue(uint8_t value)
{
	errorState errorReturn = OK;
	TCNT0 = value;
	return errorReturn;
}
errorState TIMER0_getValue(uint8_t* value)
{
	errorState errorReturn = OK;
	*value = TCNT0;	
	return errorReturn;
}
errorState TIMER0_setCompareValue(uint8_t value)
{
	errorState errorReturn = OK;
	OCR0 = value;
	return errorReturn;
}
