#ifndef UART_CONFIG_H_
#define UART_CONFIG_H_

/*
	in this file we will set default configuration for the module
*/
#define USE_BUFFER
#define BUFFER_SIZE 4

/* 
	set configuration for UART (uncomment one of each group)
*/

#define PARITY NO_PARITY
//#define PARITY ODD_PARITY
//#define PARITY EVEN_PARITY

#define MODE ASYN
//#define MODE SYN

#define STOP ONE_STOP
//#define STOP TWO_STOP

//#define CHARACTER _9
#define CHARACTER _8
//#define CHARACTER _7
//#define CHARACTER _6
//#define CHARACTER _5

/***********************************************************************/

#endif /* UART_CONFIG_H_ */