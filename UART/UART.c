#include "UART_private.h"
#include "UART_def.h"
#include "UART_config.h"
#include <avr/interrupt.h>

/********************************************************************/
static void sUART_reciveIE(){
	_UCSRB |= 1<<_RXCIE;
}

static void sUART_baudRate(uint16 br)
{
	
	_UBRRH &=(1<<_URSEL);
	_UBRRL = (uint8)br;
	_UBRRH = (uint8)(br>>8);
}

static void sUART_setParity(uint8 status)
{
	//enable writing to UCSRC
	_UCSRC |=1<<_URSEL;
	switch(status)
	{
		case EVEN_PARITY ://even parity
		_UCSRC |=(1<<_UPM1);
		_UCSRC &=~(1<<_UPM0);
		break;
		case ODD_PARITY  : //odd parity
		_UCSRC |=1<<_UPM1;
		_UCSRC |=(1<<_UPM0);
		break;
		default://no parity
		_UCSRC &=~(1<<_UPM1);
		_UCSRC &=~(1<<_UPM0);
		break;
	}
}

void sUART_setMode(uint8 status)
{
	//enable writing to UCSRC
	_UCSRC |=1<<_URSEL;
	if(status == SYN){//syncronuce
		_UCSRC |=1<<_UMSEL;
		}else{//Asyncronuce
		_UCSRC &=~(1<<_UMSEL);
	}
}

void sUART_setStopBits(uint8 status)
{
	//enable writing to UCSRC
	_UCSRC |=1<<_URSEL;
	if(status == TWO_STOP)//two stop bit
	{
		_UCSRC |=1<<_USBS;
		}else{//one stop bit and default
		_UCSRC &=~(1<<_USBS);
	}
}

static void sUART_setCharSize(uint8 size)
{
	//enable writing to UCSRC
	_UCSRC |=1<<_URSEL;
	switch(size)
	{
		case _5://5_bits
		_UCSRC &=~(1<<_UCSZ0);
		_UCSRC &=~(1<<_UCSZ1);
		_UCSRB &=~(1<<_UCSZ2);
		break;
		case _6://6_bits
		_UCSRC |=(1<<_UCSZ0);
		_UCSRC &=~(1<<_UCSZ1);
		_UCSRB &=~(1<<_UCSZ2);
		break;
		case _7://7_bits
		_UCSRC &=~(1<<_UCSZ0);
		_UCSRC |=(1<<_UCSZ1);
		_UCSRB &=~(1<<_UCSZ2);
		break;
		case _9://9_bits
		_UCSRC |=(1<<_UCSZ0);
		_UCSRC |=(1<<_UCSZ1);
		_UCSRB |=(1<<_UCSZ2);
		break;
		default://8_bits
		_UCSRC |=(1<<_UCSZ0);
		_UCSRC |=(1<<_UCSZ1);
		_UCSRB |=(1<<_UCSZ2);
		break;
	}
}

static void sUART_transmitt(uint8 status)
{
	if(status == ENABLE)//enable transmitting
	{
		_UCSRB |=1<<_TXEN;
		}else{//disable transmitting
		_UCSRB &=~(1<<_TXEN);
	}
}

static void sUART_recive(uint8 status)
{
	if(status == ENABLE)//enable transmitting
	{
		_UCSRB |=1<<_RXEN;
		}else{//disable transmitting
		_UCSRB &=~(1<<_RXEN);
	}
}
/********************************************************************/
/********************************************************************/
/********************************************************************/


void UART_init(uint16 baudRate)
{
	sUART_baudRate(baudRate);
	sei();
	//default init	
	sUART_transmitt(ENABLE);
	sUART_recive(ENABLE);
	
	#ifdef USE_BUFFER
		sUART_reciveIE();//used to recive string
	#endif
	
	sUART_setParity(NO_PARITY);
	sUART_setStopBits(ONE_STOP);
	sUART_setMode(ASYN);
	sUART_setCharSize(_8);
}

void UART_transmittByte(uint8 byte)
{
	while(!(_UCSRA & (1<<_UDRE)));//stay here untill UDR transmitt become empty
	_UDR = byte;
}

void UART_transmittString(sint8 *string){
	uint8 i=0;
	while(string[i])
	{
		UART_transmittByte(string[i++]);
	}
}


static uint8 data[BUFFER_SIZE];
static uint8 index=0;//where are we in the buffer
static uint8 isData =0;


uint8 UART_isData()
{
	return isData;
}

uint8 UART_reciveByte()
{
	uint8 j=data[index];
	index=0;
	isData = 0;
	return j;
}



#ifdef USE_BUFFER
	
	static void emptyBuffer()
	{
		uint8 i=0;
		for (i=0;i<BUFFER_SIZE;i++)
		{
			data[i] = '\0';
		}
	}
	
	//or simply reciveBuffer
	void UART_reciveString(sint8_p str)
	{
		uint8 i=0;
		for (i=0;i<BUFFER_SIZE;i++)
		{
			str[i] = data[i];
		}
		index =0;
		isData =0;
	}
		
	uint8 UART_stringAvalibal()
	{
		if(index == BUFFER_SIZE)
		{
			return 1;
			}else{
			return 0;
		}
	}
	
	
	ISR(USART_RXC_vect)
	{
		if(index < BUFFER_SIZE)
		{
			data[index]= UDR;
			index++;
			}else{
			index =0;
		}
		isData=1;
	}
#endif

