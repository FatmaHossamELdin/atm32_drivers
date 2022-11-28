/*
 * adc.h
 *
 * Created: 08/11/2022 2:30:58 AM
 *  Author: mac
 */ 


#ifndef ADC_H_
#define ADC_H_

#include "../../utilities/registers.h"
#include "../../utilities/bit_manipulation.h"
#include "../DIO/dio.h"

void ADC_init(void);
void ADC_read(uint8_t adcChannel,uint16_t* adcRead);



#endif /* ADC_H_ */