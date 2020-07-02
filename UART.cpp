#include "UART.h"

UART::UART(){
	buffer_position = 0;
	is_endline = false;
}

void UART::set_baudrate(uint32_t baud){
	switch(F_CPU){
		case 1000000UL:
			switch(baud){
				case 9600:
					UBRRL = 6;
					break;
				case 4800:
					UBRRL = 12;
					break;
				default:
					break;
				}
		case 8000000UL:
			switch(baud){
				case 115200:
					UBRRL = 3;
					break;
				case 9600:
					UBRRL = 51;
					break;
				case 4800:
					UBRRL = 207;
					break;
				default:
					break;
			}
		
		case 16000000UL:
			switch(baud){
				case 115200:
					 UBRRL = 8;
					 break;
				case 9600:
					UBRRL = 103;
					break;
				case 4800:
					UBRRL = 207;
					break;
				default:
					break;
					
			}
		default:
			break;
			
	}
}

void UART::init(uint32_t baudrate){
	set_baudrate(baudrate);
	//Enable RECEIVER and TRANSMITER
	UCSRB |= (1<<RXEN) | (1<<TXEN);
	//Enable receiver complete Interrupt;
	UCSRB |= (1<<RXCIE);
	//set character size to 8 bits
	UCSRC |= (1<<UCSZ0) | (1<<UCSZ1);
	//set Asynchronous mode
	UCSRC &= ~(1<<UMSEL);
	
	//enable global Interrupt
	sei();
	
}

void UART::send_char(char data){
	while(!(UCSRA & (1<<UDRE))){}
	UDR = data;
}

void UART::send_string(char *data){
	for(;*data;data++) send_char(*data);
}

char UART::receive_char(void) const{
	return UDR;

}

void UART::flush_buffer(){
	for(int i = 0; i < BUFFER_SIZE; i++){
		receive_buffer[i] = 0x00;
	}
	buffer_position = 0;
}