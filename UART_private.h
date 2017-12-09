

#ifndef UART_PRIVATE_H_
#define UART_PRIVATE_H_

#include "UART_types.h"

#define _UCSRA	*(volatile unsigned char*)(0x2B)
#define _UCSRB	*(volatile unsigned char*)(0x2A)
#define _UCSRC	*(volatile unsigned char*)(0x40)
#define _UDR	*(volatile unsigned char*)(0x2C)
#define _UBRRL	*(volatile unsigned char*)(0x29)
#define _UBRRH	*(volatile unsigned char *)(0x40)

//UCSRC bits
#define _URSEL 7
#define _UMSEL 6
#define _UPM1 5
#define _UPM0 4
#define _USBS 3
#define _UCSZ1 2
#define _UCSZ0 1
#define _UCPOL 0


//UCSRA
#define _RXC 7
#define _TXC 6
#define _UDRE 5
#define _FE 4
#define _DOR 3
#define _PE 2
#define _U2X 1
#define _MPCM 0

//UCSRB
#define _RXCIE 7
#define _TXCIE 6
#define _UDRIE 5
#define _RXEN  4
#define _TXEN  3
#define _UCSZ2 2
#define _RXB8  1
#define _TXB8  0



#endif /* UART_PRIVATE_H_ */