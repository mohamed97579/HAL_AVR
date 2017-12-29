#ifndef KEYPAD_PRIVATE_H_
#define KEYPAD_PRIVATE_H_

//atmega32 address
#define _PORTA *(volatile unsigned char *)(0x3B)
#define _DDRA *(volatile unsigned char *)(0x3A)
#define _PINA *(volatile unsigned char *)(0x39)

#define _PORTB *(volatile unsigned char *)(0x38)
#define _DDRB *(volatile unsigned char *)(0x37)
#define _PINB *(volatile unsigned char *)(0x36)

#define _PORTC *(volatile unsigned char *)(0x35)
#define _DDRC *(volatile unsigned char *)(0x34)
#define _PINC *(volatile unsigned char *)(0x33)

#define _PORTD *(volatile unsigned char *)(0x32)
#define _DDRD *(volatile unsigned char *)(0x31)
#define _PIND *(volatile unsigned char *)(0x30) 

#endif /* KEYPAD_PRIVATE_H_ */
