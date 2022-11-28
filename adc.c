/*
 * adc.c
 *
 * Created: 08/11/2022 2:31:13 AM
 *  Author: mac
 */ 

#include "adc.h"

void ADC_init(void)
{
	//enable ADC
	SET_BIT(ADCSRA,7);
	
	//disable interupt
	CLEAR_BIT(ADCSRA,3);
	
	//setting prescaller 128
	SET_BIT(ADCSRA,0);
	SET_BIT(ADCSRA,1);
	SET_BIT(ADCSRA,2);
	
	//setting vltage ref -> AVCC external
	CLEAR_BIT(ADMUX,7);
	SET_BIT(ADMUX,6);
	
	//right adjustment
	CLEAR_BIT(ADMUX,5);
}
void ADC_read(uint8_t adcChannel,uint16_t* adcRead)
{
	//clear channel bits
	ADMUX &=(0b11100000);
	//setting the channel
	ADMUX |= adcChannel;
	
	//start conversion
	SET_BIT(ADCSRA,6);
	
	//wait until conversion completes
	while(GET_BIT(ADCSRA,4) == 0);
	
	//reading the output value
	*adcRead = (uint16_t)(ADCH<<8) | (ADCL);
	
	//clearing the flag by setting the value to 1
	SET_BIT(ADCSRA,4);
}