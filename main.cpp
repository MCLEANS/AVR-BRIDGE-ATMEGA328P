#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include <stdlib.h>
#include <string.h>

#include "UART.h"
#include "ADC.h"
#include "commands.h"


UART uart;
_ADC adc;

ADC_channel_value adc_values;

char response[5];

ISR (USART_RX_vect){
	uart.receive_buffer[uart.buffer_position] = uart.receive_char();
	
	if(uart.receive_buffer[uart.buffer_position] == '\n') {
	uart.is_endline = true;
    }
    
    uart.buffer_position++;
	
    if(uart.buffer_position > BUFFER_SIZE) uart.buffer_position = 0;
}



ISR(ADC_vect){
	adc_values = adc.get_value();	
}

void listen(){
	if(uart.is_endline){
		if(strncmp(uart.receive_buffer,FETCH_ADC0,(sizeof(FETCH_ADC0)/sizeof(char))-1) == 0){
			adc.convert();
			_delay_us(500);
			itoa(adc_values.channel_0,response,10);
			uart.send_string(response);
			uart.send_char(new_line);
			uart.flush_buffer();
		}
		else if(strncmp(uart.receive_buffer,FETCH_ADC1,(sizeof(FETCH_ADC1)/sizeof(char))-1) == 0){
			adc.convert();
			_delay_us(500);
			itoa(adc_values.channel_1,response,10);
			uart.send_string(response);
			uart.send_char(new_line);
			uart.flush_buffer();
		
		}
		else if(strncmp(uart.receive_buffer,FETCH_ADC2,(sizeof(FETCH_ADC2)/sizeof(char))-1) == 0){
			adc.convert();
			_delay_us(500);
			itoa(adc_values.channel_2,response,10);
			uart.send_string(response);
			uart.send_char(new_line);
			uart.flush_buffer();
		
		}
		else if(strncmp(uart.receive_buffer,FETCH_ADC3,(sizeof(FETCH_ADC3)/sizeof(char))-1) == 0){
			adc.convert();
			_delay_us(500);
			itoa(adc_values.channel_3,response,10);
			uart.send_string(response);
			uart.send_char(new_line);
			uart.flush_buffer();
		
		}
		else if(strncmp(uart.receive_buffer,FETCH_ADC4,(sizeof(FETCH_ADC4)/sizeof(char))-1) == 0){
			adc.convert();
			_delay_us(500);
			itoa(adc_values.channel_4,response,10);
			uart.send_string(response);
			uart.send_char(new_line);
			uart.flush_buffer();
		
		}
		else if(strncmp(uart.receive_buffer,FETCH_ADC5,(sizeof(FETCH_ADC5)/sizeof(char))-1) == 0){
			adc.convert();
			_delay_us(500);
			itoa(adc_values.channel_5,response,10);
			uart.send_string(response);
			uart.send_char(new_line);
			uart.flush_buffer();
		
		}
		else if(strncmp(uart.receive_buffer,FETCH_ADC6,(sizeof(FETCH_ADC6)/sizeof(char))-1) == 0){
			adc.convert();
			_delay_us(500);
			itoa(adc_values.channel_6,response,10);
			uart.send_string(response);
			uart.send_char(new_line);
			uart.flush_buffer();
		
		}
		else if(strncmp(uart.receive_buffer,FETCH_ADC7,(sizeof(FETCH_ADC7)/sizeof(char))-1) == 0){
			adc.convert();
			_delay_us(500);
			itoa(adc_values.channel_7,response,10);
			uart.send_string(response);
			uart.send_char(new_line);
			uart.flush_buffer();
		}

		else{
			uart.flush_buffer();
		}

		uart.is_endline = false;
	}
}



int main(void)
{
	uart.init(9600);
	adc.init();
	
    
    while (1) 
    {
		uart.send_char('M');
		listen();
    }
}