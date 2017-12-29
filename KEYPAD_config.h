#ifndef KEYPAD_CONFIG_H_
#define KEYPAD_CONFIG_H_

//define connected port to keypad
#define KEYPAD_PORT _PORTD
#define KEYPAD_DDR  _DDRD
#define KEYPAD_PIN  _PIND

//configuration for 4*4 KEYPAD in formate KEYPAD_xy_value(where x : is the row , y : is the column ,, one indexed ! zero index)
// the default configuration is for 4 * 4 KEYPAD with the following shape
/*
	1	2	3	A
	4	5	3	B
	7	8	3	C
	*	0	#	D
*/
#define KEYPAD_11_value '1'
#define KEYPAD_21_value '4'
#define KEYPAD_31_value '7'
#define KEYPAD_41_value '*'

#define KEYPAD_12_value '2'
#define KEYPAD_22_value '5'
#define KEYPAD_32_value '8'
#define KEYPAD_42_value '0'

#define KEYPAD_13_value '3'
#define KEYPAD_23_value '6'
#define KEYPAD_33_value '9'
#define KEYPAD_43_value '#'

#define KEYPAD_14_value 'A'
#define KEYPAD_24_value 'B'
#define KEYPAD_34_value 'C'
#define KEYPAD_44_value 'D'

#define KEYPAD_defualt_value '?'

//this line must be configured the same as at "KEYPAD.h"
typedef  unsigned char KEYPAD_defualt_dataType;


#endif /* KEYPAD_CONFIG_H_ */