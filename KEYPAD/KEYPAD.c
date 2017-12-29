#include "KEYPAD_private.h"
#include "KEYPAD_config.h"


//the right shift used to read the pin state one or zero
#define A ((KEYPAD_PIN & 1<<0)>>0)
#define B ((KEYPAD_PIN & 1<<1)>>1)
#define C ((KEYPAD_PIN & 1<<2)>>2)
#define D ((KEYPAD_PIN & 1<<3)>>3)

void KEYPAD_init()
{
	KEYPAD_DDR  = 0xF0;
	KEYPAD_PORT = 0xFF;
}

KEYPAD_defualt_dataType KEYPAD_read()
{
		KEYPAD_PORT = 0xEF;
		if(!A & B & C & D){//1
			return KEYPAD_11_value;
		}else if(A & !B & C & D){//4
			return KEYPAD_21_value;
		}else if(A & B & !C & D){//7
			return KEYPAD_31_value;
		}else if(A & B & C & !D){//*
			return KEYPAD_41_value;
		}
		KEYPAD_PORT = 0xDF;
		
		if(!A & B & C & D){//2
			return KEYPAD_12_value;
		}else if(A & !B & C & D){//5
			return KEYPAD_22_value;
		}else if(A & B & !C & D){//8
			return KEYPAD_32_value;
		}else if(A & B & C & !D){//0
			return KEYPAD_42_value;
		}
		
		KEYPAD_PORT = 0b10111111;
		if(!A & B & C & D){//3
			return KEYPAD_13_value;
		}else if(A & !B & C & D){//6
			return KEYPAD_23_value;
		}else if(A & B & !C & D){//9
			return KEYPAD_33_value;
		}else if(A & B & C & !D){//#
			return KEYPAD_43_value;
		}
		
		KEYPAD_PORT = 0b01111111;
		if(!A & B & C & D){//A
			return KEYPAD_14_value;
		}else if(A & !B & C & D){//B
			return KEYPAD_24_value;
		}else if(A & B & !C & D){//C
			return KEYPAD_34_value;
		}else if(A & B & C & !D){//D
			return KEYPAD_44_value;
	}
	return KEYPAD_defualt_value;
}
