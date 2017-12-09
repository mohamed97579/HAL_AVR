/*
 * uart.h
 *
 * Created: 24/03/2017 11:15:41 ص
 *  Author: alhamd2017
 */

#ifndef _UART_H_
#define _UART_H_


#include "UART_def.h"
#include "UART_types.h"

/*
 * @func_name : UART_init
 * @return : void
 * @description : this function set baudRate for UART modeule in AVR
 * @argument : the argument must be in this format _BBBB_F_ while B is baudRate and F is frequncy in Mhz (ex : for 9600 baudRate and 8 MHz the argument must be _9600_8_)
 *			   this function set UART module to (NO_PARITY , ONE_STOP_BIT , 8_BIT_CHARACTER_SIZE)
*/
extern void UART_init(uint16 bR);

/*
 * @func_name : UART_transmittByte
 * @return : void
 * @description : this function transmit byte using UART  
 * @argument : the argument is the byte to be sent
*/
extern void UART_transmittByte(uint8 byte);


/*
 * @func_name : UART_transmittString
 * @return : void
 * @description : this function transmit string using UART  
 * @argument : the argument is the string to be sent
*/
extern void UART_transmittString(sint8* string);

/*
 * @func_name : UART_reciveByte
 * @return : the byte to be recived
 * @description : this function recive byte using UART  
 * @argument : void
*/
extern uint8 UART_reciveByte(void);

/*
 * @func_name : UART_reciveByte
 * @return : void
 * @description : this function recive byte using UART  
 * @argument : pointer to string which the function must be saved
*/
extern void UART_reciveString(sint8_p);

extern uint8 UART_isData();
extern uint8 UART_stringAvalibal();

#endif /* UART_H_ */
