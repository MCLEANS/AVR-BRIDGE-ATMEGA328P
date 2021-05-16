/*
MIT License

Copyright (c) 2021 JACK MCLEANS

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/

#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include <stdlib.h>
#include <string.h>

#include "UART.h"
#include "ADC.h"
#include "commands.h"
#include "GPIO.h"


UART uart;
_ADC adc;
GPIO gpio;

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
		}

		/*******************************************************************************************
		 *  SET INPUT PIN
		 * *****************************************************************************************/
		else if(strncmp(uart.receive_buffer,PINB0_INPUT,(sizeof(PINB0_INPUT)/sizeof(char))-1) == 0){
			gpio.set_input(&DDRB,PIN0);
			uart.send_string(default_reply);
			uart.send_char(new_line);
			uart.flush_buffer();
		}
		else if(strncmp(uart.receive_buffer,PINB1_INPUT,(sizeof(PINB1_INPUT)/sizeof(char))-1) == 0){
			gpio.set_input(&DDRB,PIN1);
			uart.send_string(default_reply);
			uart.send_char(new_line);
			uart.flush_buffer();
		}
		else if(strncmp(uart.receive_buffer,PINB2_INPUT,(sizeof(PINB2_INPUT)/sizeof(char))-1) == 0){
			gpio.set_input(&DDRB,PIN2);
			uart.send_string(default_reply);
			uart.send_char(new_line);
			uart.flush_buffer();
		}
		else if(strncmp(uart.receive_buffer,PINB3_INPUT,(sizeof(PINB3_INPUT)/sizeof(char))-1) == 0){
			gpio.set_input(&DDRB,PIN3);
			uart.send_string(default_reply);
			uart.send_char(new_line);
			uart.flush_buffer();
		}
		else if(strncmp(uart.receive_buffer,PINB4_INPUT,(sizeof(PINB4_INPUT)/sizeof(char))-1) == 0){
			gpio.set_input(&DDRB,PIN4);
			uart.send_string(default_reply);
			uart.send_char(new_line);
			uart.flush_buffer();
		}
		else if(strncmp(uart.receive_buffer,PINB5_INPUT,(sizeof(PINB5_INPUT)/sizeof(char))-1) == 0){
			gpio.set_input(&DDRB,PIN5);
			uart.send_string(default_reply);
			uart.send_char(new_line);
			uart.flush_buffer();
		}
		else if(strncmp(uart.receive_buffer,PINB6_INPUT,(sizeof(PINB6_INPUT)/sizeof(char))-1) == 0){
			gpio.set_input(&DDRB,PIN6);
			uart.send_string(default_reply);
			uart.send_char(new_line);
			uart.flush_buffer();
		}
		else if(strncmp(uart.receive_buffer,PINB7_INPUT,(sizeof(PINB7_INPUT)/sizeof(char))-1) == 0){
			gpio.set_input(&DDRB,PIN7);
			uart.send_string(default_reply);
			uart.send_char(new_line);
			uart.flush_buffer();
		}
		
		else if(strncmp(uart.receive_buffer,PIND0_INPUT,(sizeof(PIND0_INPUT)/sizeof(char))-1) == 0){
			gpio.set_input(&DDRD,PIN0);
			uart.send_string(default_reply);
			uart.send_char(new_line);
			uart.flush_buffer();
		}
		else if(strncmp(uart.receive_buffer,PIND1_INPUT,(sizeof(PIND1_INPUT)/sizeof(char))-1) == 0){
			gpio.set_input(&DDRD,PIN1);
			uart.send_string(default_reply);
			uart.send_char(new_line);
			uart.flush_buffer();
		}
		else if(strncmp(uart.receive_buffer,PIND2_INPUT,(sizeof(PIND2_INPUT)/sizeof(char))-1) == 0){
			gpio.set_input(&DDRD,PIN2);
			uart.send_string(default_reply);
			uart.send_char(new_line);
			uart.flush_buffer();
		}
		else if(strncmp(uart.receive_buffer,PIND3_INPUT,(sizeof(PIND3_INPUT)/sizeof(char))-1) == 0){
			gpio.set_input(&DDRD,PIN3);
			uart.send_string(default_reply);
			uart.send_char(new_line);
			uart.flush_buffer();
		}
		else if(strncmp(uart.receive_buffer,PIND4_INPUT,(sizeof(PIND4_INPUT)/sizeof(char))-1) == 0){
			gpio.set_input(&DDRD,PIN4);
			uart.send_string(default_reply);
			uart.send_char(new_line);
			uart.flush_buffer();
		}
		else if(strncmp(uart.receive_buffer,PIND5_INPUT,(sizeof(PIND5_INPUT)/sizeof(char))-1) == 0){
			gpio.set_input(&DDRD,PIN5);
			uart.send_string(default_reply);
			uart.send_char(new_line);
			uart.flush_buffer();
		}
		else if(strncmp(uart.receive_buffer,PIND6_INPUT,(sizeof(PIND6_INPUT)/sizeof(char))-1) == 0){
			gpio.set_input(&DDRD,PIN6);
			uart.send_string(default_reply);
			uart.send_char(new_line);
			uart.flush_buffer();
		}
		else if(strncmp(uart.receive_buffer,PIND7_INPUT,(sizeof(PIND7_INPUT)/sizeof(char))-1) == 0){
			gpio.set_input(&DDRD,PIN7);
			uart.send_string(default_reply);
			uart.send_char(new_line);
			uart.flush_buffer();
		}
		/*******************************************************************************************
		 * GET PIN INPUT STATUS
		 * *****************************************************************************************/
		else if(strncmp(uart.receive_buffer,PINB0_INPUT_STATUS,(sizeof(PINB0_INPUT_STATUS)/sizeof(char))-1) == 0){
			bool status = gpio.input_status(&PORTB,PIN0);
			if(status) uart.send_string(input_high);
			else if(!status) uart.send_string(input_low);
			uart.send_char(new_line);
			uart.flush_buffer();
		}
		else if(strncmp(uart.receive_buffer,PINB1_INPUT_STATUS,(sizeof(PINB1_INPUT_STATUS)/sizeof(char))-1) == 0){
			bool status = gpio.input_status(&PORTB,PIN1);
			if(status) uart.send_string(input_high);
			else if(!status) uart.send_string(input_low);
			uart.send_char(new_line);
			uart.flush_buffer();
		}
		else if(strncmp(uart.receive_buffer,PINB2_INPUT_STATUS,(sizeof(PINB2_INPUT_STATUS)/sizeof(char))-1) == 0){
			bool status = gpio.input_status(&PORTB,PIN2);
			if(status) uart.send_string(input_high);
			else if(!status) uart.send_string(input_low);
			uart.send_char(new_line);
			uart.flush_buffer();
		}
		else if(strncmp(uart.receive_buffer,PINB3_INPUT_STATUS,(sizeof(PINB3_INPUT_STATUS)/sizeof(char))-1) == 0){
			bool status = gpio.input_status(&PORTB,PIN3);
			if(status) uart.send_string(input_high);
			else if(!status) uart.send_string(input_low);
			uart.send_char(new_line);
			uart.flush_buffer();
		}
		else if(strncmp(uart.receive_buffer,PINB4_INPUT_STATUS,(sizeof(PINB4_INPUT_STATUS)/sizeof(char))-1) == 0){
			bool status = gpio.input_status(&PORTB,PIN4);
			if(status) uart.send_string(input_high);
			else if(!status) uart.send_string(input_low);
			uart.send_char(new_line);
			uart.flush_buffer();
		}
		else if(strncmp(uart.receive_buffer,PINB5_INPUT_STATUS,(sizeof(PINB5_INPUT_STATUS)/sizeof(char))-1) == 0){
			bool status = gpio.input_status(&PORTB,PIN5);
			if(status) uart.send_string(input_high);
			else if(!status) uart.send_string(input_low);
			uart.send_char(new_line);
			uart.flush_buffer();
		}
		else if(strncmp(uart.receive_buffer,PINB6_INPUT_STATUS,(sizeof(PINB6_INPUT_STATUS)/sizeof(char))-1) == 0){
			bool status = gpio.input_status(&PORTB,PIN6);
			if(status) uart.send_string(input_high);
			else if(!status) uart.send_string(input_low);
			uart.send_char(new_line);
			uart.flush_buffer();
		}
		else if(strncmp(uart.receive_buffer,PINB7_INPUT_STATUS,(sizeof(PINB7_INPUT_STATUS)/sizeof(char))-1) == 0){
			bool status = gpio.input_status(&PORTB,PIN7);
			if(status) uart.send_string(input_high);
			else if(!status) uart.send_string(input_low);
			uart.send_char(new_line);
			uart.flush_buffer();
		}

		else if(strncmp(uart.receive_buffer,PIND0_INPUT_STATUS,(sizeof(PIND0_INPUT_STATUS)/sizeof(char))-1) == 0){
			bool status = gpio.input_status(&PORTD,PIN0);
			if(status) uart.send_string(input_high);
			else if(!status) uart.send_string(input_low);
			uart.send_char(new_line);
			uart.flush_buffer();
		}
		else if(strncmp(uart.receive_buffer,PIND1_INPUT_STATUS,(sizeof(PIND1_INPUT_STATUS)/sizeof(char))-1) == 0){
			bool status = gpio.input_status(&PORTD,PIN1);
			if(status) uart.send_string(input_high);
			else if(!status) uart.send_string(input_low);
			uart.send_char(new_line);
			uart.flush_buffer();
		}
		else if(strncmp(uart.receive_buffer,PIND2_INPUT_STATUS,(sizeof(PIND2_INPUT_STATUS)/sizeof(char))-1) == 0){
			bool status = gpio.input_status(&PORTD,PIN2);
			if(status) uart.send_string(input_high);
			else if(!status) uart.send_string(input_low);
			uart.send_char(new_line);
			uart.flush_buffer();
		}
		else if(strncmp(uart.receive_buffer,PIND3_INPUT_STATUS,(sizeof(PIND3_INPUT_STATUS)/sizeof(char))-1) == 0){
			bool status = gpio.input_status(&PORTD,PIN3);
			if(status) uart.send_string(input_high);
			else if(!status) uart.send_string(input_low);
			uart.send_char(new_line);
			uart.flush_buffer();
		}
		else if(strncmp(uart.receive_buffer,PIND4_INPUT_STATUS,(sizeof(PIND4_INPUT_STATUS)/sizeof(char))-1) == 0){
			bool status = gpio.input_status(&PORTD,PIN4);
			if(status) uart.send_string(input_high);
			else if(!status) uart.send_string(input_low);
			uart.send_char(new_line);
			uart.flush_buffer();
		}
		else if(strncmp(uart.receive_buffer,PIND5_INPUT_STATUS,(sizeof(PIND5_INPUT_STATUS)/sizeof(char))-1) == 0){
			bool status = gpio.input_status(&PORTD,PIN5);
			if(status) uart.send_string(input_high);
			else if(!status) uart.send_string(input_low);
			uart.send_char(new_line);
			uart.flush_buffer();
		}
		else if(strncmp(uart.receive_buffer,PIND6_INPUT_STATUS,(sizeof(PIND6_INPUT_STATUS)/sizeof(char))-1) == 0){
			bool status = gpio.input_status(&PORTD,PIN6);
			if(status) uart.send_string(input_high);
			else if(!status) uart.send_string(input_low);
			uart.send_char(new_line);
			uart.flush_buffer();
		}
		else if(strncmp(uart.receive_buffer,PIND7_INPUT_STATUS,(sizeof(PIND7_INPUT_STATUS)/sizeof(char))-1) == 0){
			bool status = gpio.input_status(&PORTD,PIN7);
			if(status) uart.send_string(input_high);
			else if(!status) uart.send_string(input_low);
			uart.send_char(new_line);
			uart.flush_buffer();
		}

		/*******************************************************************************************
		 *  SET OUTPUT PIN
		 * *****************************************************************************************/
		else if(strncmp(uart.receive_buffer,PINB0_OUTPUT,(sizeof(PINB0_OUTPUT)/sizeof(char))-1) == 0){
			gpio.set_output(&DDRB,PIN0);
			uart.send_string(default_reply);
			uart.send_char(new_line);
			uart.flush_buffer();
		}
		else if(strncmp(uart.receive_buffer,PINB1_OUTPUT,(sizeof(PINB1_OUTPUT)/sizeof(char))-1) == 0){
			gpio.set_output(&DDRB,PIN1);
			uart.send_string(default_reply);
			uart.send_char(new_line);
			uart.flush_buffer();
		}
		else if(strncmp(uart.receive_buffer,PINB2_OUTPUT,(sizeof(PINB2_OUTPUT)/sizeof(char))-1) == 0){
			gpio.set_output(&DDRB,PIN2);
			uart.send_string(default_reply);
			uart.send_char(new_line);
			uart.flush_buffer();
		}
		else if(strncmp(uart.receive_buffer,PINB3_OUTPUT,(sizeof(PINB3_OUTPUT)/sizeof(char))-1) == 0){
			gpio.set_output(&DDRB,PIN3);
			uart.send_string(default_reply);
			uart.send_char(new_line);
			uart.flush_buffer();
		}
		else if(strncmp(uart.receive_buffer,PINB4_OUTPUT,(sizeof(PINB4_OUTPUT)/sizeof(char))-1) == 0){
			gpio.set_output(&DDRB,PIN4);
			uart.send_string(default_reply);
			uart.send_char(new_line);
			uart.flush_buffer();
		}
		else if(strncmp(uart.receive_buffer,PINB5_OUTPUT,(sizeof(PINB5_OUTPUT)/sizeof(char))-1) == 0){
			gpio.set_output(&DDRB,PIN5);
			uart.send_string(default_reply);
			uart.send_char(new_line);
			uart.flush_buffer();
		}
		else if(strncmp(uart.receive_buffer,PINB6_OUTPUT,(sizeof(PINB6_OUTPUT)/sizeof(char))-1) == 0){
			gpio.set_output(&DDRB,PIN6);
			uart.send_string(default_reply);
			uart.send_char(new_line);
			uart.flush_buffer();
		}
		else if(strncmp(uart.receive_buffer,PINB7_OUTPUT,(sizeof(PINB7_OUTPUT)/sizeof(char))-1) == 0){
			gpio.set_output(&DDRB,PIN7);
			uart.send_string(default_reply);
			uart.send_char(new_line);
			uart.flush_buffer();
		}

		else if(strncmp(uart.receive_buffer,PIND0_OUTPUT,(sizeof(PIND0_OUTPUT)/sizeof(char))-1) == 0){
			gpio.set_output(&DDRD,PIN0);
			uart.send_string(default_reply);
			uart.send_char(new_line);
			uart.flush_buffer();
		}
		else if(strncmp(uart.receive_buffer,PIND1_OUTPUT,(sizeof(PIND1_OUTPUT)/sizeof(char))-1) == 0){
			gpio.set_output(&DDRD,PIN1);
			uart.send_string(default_reply);
			uart.send_char(new_line);
			uart.flush_buffer();
		}
		else if(strncmp(uart.receive_buffer,PIND2_OUTPUT,(sizeof(PIND2_OUTPUT)/sizeof(char))-1) == 0){
			gpio.set_output(&DDRD,PIN2);
			uart.send_string(default_reply);
			uart.send_char(new_line);
			uart.flush_buffer();
		}
		else if(strncmp(uart.receive_buffer,PIND3_OUTPUT,(sizeof(PIND3_OUTPUT)/sizeof(char))-1) == 0){
			gpio.set_output(&DDRD,PIN3);
			uart.send_string(default_reply);
			uart.send_char(new_line);
			uart.flush_buffer();
		}
		else if(strncmp(uart.receive_buffer,PIND4_OUTPUT,(sizeof(PIND4_OUTPUT)/sizeof(char))-1) == 0){
			gpio.set_output(&DDRD,PIN4);
			uart.send_string(default_reply);
			uart.send_char(new_line);
			uart.flush_buffer();
		}
		else if(strncmp(uart.receive_buffer,PIND5_OUTPUT,(sizeof(PIND5_OUTPUT)/sizeof(char))-1) == 0){
			gpio.set_output(&DDRD,PIN5);
			uart.send_string(default_reply);
			uart.send_char(new_line);
			uart.flush_buffer();
		}
		else if(strncmp(uart.receive_buffer,PIND6_OUTPUT,(sizeof(PIND6_OUTPUT)/sizeof(char))-1) == 0){
			gpio.set_output(&DDRD,PIN6);
			uart.send_string(default_reply);
			uart.send_char(new_line);
			uart.flush_buffer();
		}
		else if(strncmp(uart.receive_buffer,PIND7_OUTPUT,(sizeof(PIND7_OUTPUT)/sizeof(char))-1) == 0){
			gpio.set_output(&DDRD,PIN7);
			uart.send_string(default_reply);
			uart.send_char(new_line);
			uart.flush_buffer();
		}

		/*******************************************************************************************
		 *  SET  PIN HIGH
		 * *****************************************************************************************/
		else if(strncmp(uart.receive_buffer,PINB0_HIGH,(sizeof(PINB0_HIGH)/sizeof(char))-1) == 0){
			gpio.set_high(&PORTB,PIN0);
			uart.send_string(default_reply);
			uart.send_char(new_line);
			uart.flush_buffer();
		}
		else if(strncmp(uart.receive_buffer,PINB1_HIGH,(sizeof(PINB1_HIGH)/sizeof(char))-1) == 0){
			gpio.set_high(&PORTB,PIN1);
			uart.send_string(default_reply);
			uart.send_char(new_line);
			uart.flush_buffer();
		}
		else if(strncmp(uart.receive_buffer,PINB2_HIGH,(sizeof(PINB2_HIGH)/sizeof(char))-1) == 0){
			gpio.set_high(&PORTB,PIN2);
			uart.send_string(default_reply);
			uart.send_char(new_line);
			uart.flush_buffer();
		}
		else if(strncmp(uart.receive_buffer,PINB3_HIGH,(sizeof(PINB3_HIGH)/sizeof(char))-1) == 0){
			gpio.set_high(&PORTB,PIN3);
			uart.send_string(default_reply);
			uart.send_char(new_line);
			uart.flush_buffer();
		}
		else if(strncmp(uart.receive_buffer,PINB4_HIGH,(sizeof(PINB4_HIGH)/sizeof(char))-1) == 0){
			gpio.set_high(&PORTB,PIN4);
			uart.send_string(default_reply);
			uart.send_char(new_line);
			uart.flush_buffer();
		}
		else if(strncmp(uart.receive_buffer,PINB5_HIGH,(sizeof(PINB5_HIGH)/sizeof(char))-1) == 0){
			gpio.set_high(&PORTB,PIN5);
			uart.send_string(default_reply);
			uart.send_char(new_line);
			uart.flush_buffer();
		}
		else if(strncmp(uart.receive_buffer,PINB6_HIGH,(sizeof(PINB6_HIGH)/sizeof(char))-1) == 0){
			gpio.set_high(&PORTB,PIN6);
			uart.send_string(default_reply);
			uart.send_char(new_line);
			uart.flush_buffer();
		}
		else if(strncmp(uart.receive_buffer,PINB7_HIGH,(sizeof(PINB7_HIGH)/sizeof(char))-1) == 0){
			gpio.set_high(&PORTB,PIN7);
			uart.send_string(default_reply);
			uart.send_char(new_line);
			uart.flush_buffer();
		}

		else if(strncmp(uart.receive_buffer,PIND0_HIGH,(sizeof(PIND0_HIGH)/sizeof(char))-1) == 0){
			gpio.set_high(&PORTD,PIN0);
			uart.send_string(default_reply);
			uart.send_char(new_line);
			uart.flush_buffer();
		}
		else if(strncmp(uart.receive_buffer,PIND1_HIGH,(sizeof(PIND1_HIGH)/sizeof(char))-1) == 0){
			gpio.set_high(&PORTD,PIN1);
			uart.send_string(default_reply);
			uart.send_char(new_line);
			uart.flush_buffer();
		}
		else if(strncmp(uart.receive_buffer,PIND2_HIGH,(sizeof(PIND2_HIGH)/sizeof(char))-1) == 0){
			gpio.set_high(&PORTD,PIN2);
			uart.send_string(default_reply);
			uart.send_char(new_line);
			uart.flush_buffer();
		}
		else if(strncmp(uart.receive_buffer,PIND3_HIGH,(sizeof(PIND3_HIGH)/sizeof(char))-1) == 0){
			gpio.set_high(&PORTD,PIN3);
			uart.send_string(default_reply);
			uart.send_char(new_line);
			uart.flush_buffer();
		}
		else if(strncmp(uart.receive_buffer,PIND4_HIGH,(sizeof(PIND4_HIGH)/sizeof(char))-1) == 0){
			gpio.set_high(&PORTD,PIN4);
			uart.send_string(default_reply);
			uart.send_char(new_line);
			uart.flush_buffer();
		}
		else if(strncmp(uart.receive_buffer,PIND5_HIGH,(sizeof(PIND5_HIGH)/sizeof(char))-1) == 0){
			gpio.set_high(&PORTD,PIN5);
			uart.send_string(default_reply);
			uart.send_char(new_line);
			uart.flush_buffer();
		}
		else if(strncmp(uart.receive_buffer,PIND6_HIGH,(sizeof(PIND6_HIGH)/sizeof(char))-1) == 0){
			gpio.set_high(&PORTD,PIN6);
			uart.send_string(default_reply);
			uart.send_char(new_line);
			uart.flush_buffer();
		}
		else if(strncmp(uart.receive_buffer,PIND7_HIGH,(sizeof(PIND7_HIGH)/sizeof(char))-1) == 0){
			gpio.set_high(&PORTD,PIN7);
			uart.send_string(default_reply);
			uart.send_char(new_line);
			uart.flush_buffer();
		}

		/*******************************************************************************************
		 *  SET PIN LOW
		 * *****************************************************************************************/
		else if(strncmp(uart.receive_buffer,PINB0_LOW,(sizeof(PINB0_LOW)/sizeof(char))-1) == 0){
			gpio.set_low(&PORTB,PIN0);
			uart.send_string(default_reply);
			uart.send_char(new_line);
			uart.flush_buffer();
		}
		else if(strncmp(uart.receive_buffer,PINB1_LOW,(sizeof(PINB1_LOW)/sizeof(char))-1) == 0){
			gpio.set_low(&PORTB,PIN1);
			uart.send_string(default_reply);
			uart.send_char(new_line);
			uart.flush_buffer();
		}
		else if(strncmp(uart.receive_buffer,PINB2_LOW,(sizeof(PINB2_LOW)/sizeof(char))-1) == 0){
			gpio.set_low(&PORTB,PIN2);
			uart.send_string(default_reply);
			uart.send_char(new_line);
			uart.flush_buffer();
		}
		else if(strncmp(uart.receive_buffer,PINB3_LOW,(sizeof(PINB3_LOW)/sizeof(char))-1) == 0){
			gpio.set_low(&PORTB,PIN3);
			uart.send_string(default_reply);
			uart.send_char(new_line);
			uart.flush_buffer();
		}
		else if(strncmp(uart.receive_buffer,PINB4_LOW,(sizeof(PINB4_LOW)/sizeof(char))-1) == 0){
			gpio.set_low(&PORTB,PIN4);
			uart.send_string(default_reply);
			uart.send_char(new_line);
			uart.flush_buffer();
		}
		else if(strncmp(uart.receive_buffer,PINB5_LOW,(sizeof(PINB5_LOW)/sizeof(char))-1) == 0){
			gpio.set_low(&PORTB,PIN5);
			uart.send_string(default_reply);
			uart.send_char(new_line);
			uart.flush_buffer();
		}
		else if(strncmp(uart.receive_buffer,PINB6_LOW,(sizeof(PINB6_LOW)/sizeof(char))-1) == 0){
			gpio.set_low(&PORTB,PIN6);
			uart.send_string(default_reply);
			uart.send_char(new_line);
			uart.flush_buffer();
		}
		else if(strncmp(uart.receive_buffer,PINB7_LOW,(sizeof(PINB7_LOW)/sizeof(char))-1) == 0){
			gpio.set_low(&PORTB,PIN7);
			uart.send_string(default_reply);
			uart.send_char(new_line);
			uart.flush_buffer();
		}
		
		else if(strncmp(uart.receive_buffer,PIND0_LOW,(sizeof(PIND0_LOW)/sizeof(char))-1) == 0){
			gpio.set_low(&PORTD,PIN0);
			uart.send_string(default_reply);
			uart.send_char(new_line);
			uart.flush_buffer();
		}
		else if(strncmp(uart.receive_buffer,PIND1_LOW,(sizeof(PIND1_LOW)/sizeof(char))-1) == 0){
			gpio.set_low(&PORTD,PIN1);
			uart.send_string(default_reply);
			uart.send_char(new_line);
			uart.flush_buffer();
		}
		else if(strncmp(uart.receive_buffer,PIND2_LOW,(sizeof(PIND2_LOW)/sizeof(char))-1) == 0){
			gpio.set_low(&PORTD,PIN2);
			uart.send_string(default_reply);
			uart.send_char(new_line);
			uart.flush_buffer();
		}
		else if(strncmp(uart.receive_buffer,PIND3_LOW,(sizeof(PIND3_LOW)/sizeof(char))-1) == 0){
			gpio.set_low(&PORTD,PIN3);
			uart.send_string(default_reply);
			uart.send_char(new_line);
			uart.flush_buffer();
		}
		else if(strncmp(uart.receive_buffer,PIND4_LOW,(sizeof(PIND4_LOW)/sizeof(char))-1) == 0){
			gpio.set_low(&PORTD,PIN4);
			uart.send_string(default_reply);
			uart.send_char(new_line);
			uart.flush_buffer();
		}
		else if(strncmp(uart.receive_buffer,PIND5_LOW,(sizeof(PIND5_LOW)/sizeof(char))-1) == 0){
			gpio.set_low(&PORTD,PIN5);
			uart.send_string(default_reply);
			uart.send_char(new_line);
			uart.flush_buffer();
		}
		else if(strncmp(uart.receive_buffer,PIND6_LOW,(sizeof(PIND6_LOW)/sizeof(char))-1) == 0){
			gpio.set_low(&PORTD,PIN6);
			uart.send_string(default_reply);
			uart.send_char(new_line);
			uart.flush_buffer();
		}
		else if(strncmp(uart.receive_buffer,PIND7_LOW,(sizeof(PIND7_LOW)/sizeof(char))-1) == 0){
			gpio.set_low(&PORTD,PIN7);
			uart.send_string(default_reply);
			uart.send_char(new_line);
			uart.flush_buffer();
		}
		else{
			uart.flush_buffer();
		}

		uart.is_endline = false;
	}
}

//This timer is used to blink the status LEDs
void timer_init(){
	//SET PRESCALER TO 256
	TCCR1B |= (1<<CS12);
	//ENABLE CTC MODE
	TCCR1B |= (1<<WGM12);
	//SET THE COMPARE VALUE
	OCR1A = 15624;
	//ENABLE OUTPUT COMPARE INTERRUPT
	TIMSK1 |= (1<<OCIE1A);
	//ENABLE GLOBAL INTERRUPTS
	sei();
}

ISR(TIMER1_COMPA_vect){
	//toggle leds every 250ms
	gpio.toggle_pin(&DDRD,PIN6);
	gpio.toggle_pin(&DDRD,PIN7);
}

void set_inital_status_LED_state(){
	//SET PD6 AND PD7 TOU OUTPUT
	gpio.set_output(&DDRD,PIN6);
	gpio.set_output(&DDRD,PIN7);
	
	//SET PD6 LOW AND PD7 HIGH
	gpio.set_low(&DDRD,PIN6);
	gpio.set_high(&DDRD,PIN7);
}

int main(void)
{
	uart.init(9600);
	adc.init();
	timer_init();
	
	set_inital_status_LED_state();

	while(1) {
		listen();
	}
}
