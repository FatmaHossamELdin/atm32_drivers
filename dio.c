/*
 * dio.c
 *
 * Created: 02/11/2022 11:49:47 PM
 *  Author: mac
 */ 

#include "dio.h"

uint8_t pedestrianFlag = 0;

ISR(EXT_INT_0)
{
	if (pedestrianFlag == 0)
	{
		pedestrianFlag = 1;
	}

}

errorState DIO_init(uint8_t pinNumber, uint8_t portNumber, uint8_t direction)
{
	errorState errorStateReturn = OK;
	switch (portNumber)
	{
		case PORT_A:
		if (direction == OUTPUT)
		{
			SET_BIT(DDRA,pinNumber); //pin out
		}
		else if(direction == INPUT)
		{
			CLEAR_BIT(DDRA,pinNumber);//pin input
		}
		else
		{
			//error handling
			errorStateReturn = NOT_OK;
		}
		break;
		
		case PORT_B:
		if (direction == OUTPUT)
		{
			SET_BIT(DDRB,pinNumber);//pin out
		}
		else if(direction == INPUT)
		{
			CLEAR_BIT(DDRB,pinNumber);//pin input
		}
		else
		{
			//error handling
			errorStateReturn = NOT_OK;
		}
		break;
		
		case PORT_C:
		if (direction == OUTPUT)
		{
			SET_BIT(DDRC,pinNumber);//pin out
		}
		else if(direction == INPUT)
		{
			CLEAR_BIT(DDRC,pinNumber);//pin input
		}
		else
		{
			//error handling
			errorStateReturn = NOT_OK;
		}
		break;
		
		case PORT_D:
		if (direction == OUTPUT)
		{
			SET_BIT(DDRD,pinNumber);//pin out
		}
		else if(direction == INPUT)
		{
			CLEAR_BIT(DDRD,pinNumber);//pin input
		}
		else
		{
			//error handling
			errorStateReturn = NOT_OK;
		}
		break;
		
		default:
		errorStateReturn = NOT_OK;
		break;
	}
	return errorStateReturn;
}
errorState DIO_write(uint8_t pinNumber, uint8_t portNumber, uint8_t value)
{
	errorState errorStateReturn = OK;
	switch (portNumber)
	{
		case PORT_A:
		if (value == HIGH)
		{
			SET_BIT(PORTA,pinNumber); //write 1
		}
		else if(value == LOW)
		{
			CLEAR_BIT(PORTA,pinNumber); //write 0
		}
		else
		{
			//error handling
			errorStateReturn = NOT_OK;
		}
		break;
	
		case PORT_B:
		if (value == HIGH)
		{
			SET_BIT(PORTB,pinNumber); //write 1
		}
		else if(value == LOW)
		{
			CLEAR_BIT(PORTB,pinNumber);  //write 0
		}
		else
		{
			//error handling
			errorStateReturn = NOT_OK;
		}
		break;
	
		case PORT_C:
		if (value == HIGH)
		{
			SET_BIT(PORTC,pinNumber); //write 1
		}
		else if(value == LOW)
		{
			CLEAR_BIT(PORTC,pinNumber);  //write 0
		}
		else
		{
			//error handling
			errorStateReturn = NOT_OK;
		}
		break;
	
		case PORT_D:
		if (value == HIGH)
		{
			SET_BIT(PORTD,pinNumber); //write 1
		}
		else if(value == LOW)
		{
			CLEAR_BIT(PORTD,pinNumber);  //write 0
		}
		else
		{
			//error handling
			errorStateReturn = NOT_OK;
		}
		break;
		
		default:
		errorStateReturn = NOT_OK;
		break;
	}
	return errorStateReturn;
}
errorState DIO_toggle(uint8_t pinNumber, uint8_t portNumber)
{
	errorState errorStateReturn = OK;
	switch (portNumber)
	{
		case PORT_A:
		TOGGLE_BIT(PORTA,pinNumber);
		break;
		
		case PORT_B:
		TOGGLE_BIT(PORTB,pinNumber);
		break;
		
		case PORT_C:
		TOGGLE_BIT(PORTC,pinNumber);
		break;
		
		case PORT_D:
		TOGGLE_BIT(PORTD,pinNumber);
		break;
		
		default:
		errorStateReturn = NOT_OK;
		break;
	}
		return errorStateReturn;
}
errorState DIO_read(uint8_t pinNumber, uint8_t portNumber, uint8_t* value)
{
	errorState errorStateReturn = OK;
	switch (portNumber)
	{
		//reading the value
		case PORT_A:
		*value = GET_BIT(PINA,pinNumber);
		break;
		
		case PORT_B:
		*value = GET_BIT(PINB,pinNumber);
		break;
		
		case PORT_C:
		*value = GET_BIT(PINC,pinNumber);
		break;
		
		case PORT_D:
		*value = GET_BIT(PIND,pinNumber);
		break;
		
		default:
		errorStateReturn = NOT_OK;
		break;
	}
	return errorStateReturn;
}