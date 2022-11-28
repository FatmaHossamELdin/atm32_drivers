/*
 * int.c
 *
 * Created: 08/11/2022 3:57:21 AM
 *  Author: mac
 */ 
#include "interrupt.h"

errorState INT_init(void)
{
	errorState errorReturn = OK;
	//enable general int
	SET_BIT(SREG,7);
	return errorReturn;
}
errorState EXT_INT_init(extInt_type extInt, intSenseControl_type intSenseContol)
{
	errorState errorReturn = OK;
	switch (extInt)
	{
		case INT0:
		//clear int0 interrupt sense bits
		MCUCR &= 0b11111100;
		//set int0 sense control bits
		MCUCR |= intSenseContol;
		//enable int0
		SET_BIT(GICR,6);
		break;
		
		case INT1:
		//clear int1 interrupt sense bits
		MCUCR &= 0b11110011;
		//set int1 sense control bits
		MCUCR |= (intSenseContol<<2);
		//enable int1
		SET_BIT(GICR,7);
		break;
		
		case INT2:
		//clear int2 interrupt sense bit
		CLEAR_BIT(MCUCSR,6);
		//set int2 sense control bit
		MCUCSR |= (intSenseContol<<6);
		//enable int2
		SET_BIT(GICR,5);
		break;
		
		default:
		errorReturn = NOT_OK;
		break;
	}
	return errorReturn;
}