/*
 * dio.h
 *
 * Created: 02/11/2022 11:49:36 PM
 *  Author: mac
 */ 


#ifndef DIO_H_
#define DIO_H_

#include "../../utilities/registers.h"
#include "../../utilities/bit_manipulation.h"
#include "../INT/interrupt.h"

//internal driver typedefs
 
//driver macros
#define PORT_A 'A'
#define PORT_B 'B'
#define PORT_C 'C'
#define PORT_D 'D'

//pins macros
#define PIN0	0	
#define PIN1	1
#define PIN2	2
#define PIN3	3
#define PIN4	4
#define PIN5	5
#define PIN6	6
#define PIN7	7

//direction defines
#define INPUT 0
#define OUTPUT 1

//value defines
#define LOW 0
#define HIGH 1

//driver functions prototype
errorState DIO_init(uint8_t pinNumber, uint8_t portNumber, uint8_t direction); //initialize dio direction
errorState DIO_write(uint8_t pinNumber, uint8_t portNumber, uint8_t value); //write data to dio
errorState DIO_toggle(uint8_t pinNumber, uint8_t portNumber); //toggle dio
errorState DIO_read(uint8_t pinNumber, uint8_t portNumber, uint8_t* value); //read dio



#endif /* DIO_H_ */