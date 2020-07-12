#include "ADC.h"

_ADC::_ADC(){
    this->value = 0;
}

void _ADC::init(){
    //set ADC prescaler between 5 and 20 for 1MHz clock
	//Here set to 16
	ADCSRA |= (1<<ADPS2);
	//Enable ADC interrupt
	ADCSRA |= (1<<ADIE);
	//set ADC reference voltage
	ADMUX |= (1<<REFS0);
	//set ADC data to left adjusted
	ADMUX |= (1<<ADLAR);
    //enable global interrupts
    sei();
	//Enable ADC
	ADCSRA |= (1<<ADEN);
	//start first ADC conversion
	ADCSRA |= (1<<ADSC);
}

ADC_channel_value _ADC::get_value(){
	ADC_channel_value adc_values;

	switch(ADMUX){
		case 0x60:
			adc_values.channel_0 = ADCL >> 6;
			adc_values.channel_0 |= ADCH << 2;
			ADMUX = 0x61;
			break;
		case 0x61:
			adc_values.channel_1 = ADCL >> 6;
			adc_values.channel_1 |= ADCH << 2;
			ADMUX = 0x62;
			break;
		case 0x62:
			adc_values.channel_2 = ADCL >> 6;
			adc_values.channel_2 |= ADCH << 2;
			ADMUX = 0x63;
			break;
		case 0x63:
			adc_values.channel_3 = ADCL >> 6;
			adc_values.channel_3 |= ADCH << 2;
			ADMUX = 0x64;
			break;
		case 0x64:
			adc_values.channel_4 = ADCL >> 6;
			adc_values.channel_4 |= ADCH << 2;
			ADMUX = 0x65;
			break;
		case 0x65:
			adc_values.channel_5 = ADCL >> 6;
			adc_values.channel_5 |= ADCH << 2;
			ADMUX = 0x66;
			break;
		case 0x66:
			adc_values.channel_6 = ADCL >> 6;
			adc_values.channel_6 |= ADCH << 2;
			ADMUX = 0x67;
			break;
		case 0x67:
			adc_values.channel_7 = ADCL >> 6;
			adc_values.channel_7 |= ADCH << 2;
			ADMUX = 0x60;
			break;
		default:
			break;
	}

    convert();
    return adc_values;
}

void _ADC::convert(){
    //do an ADC conversion
    ADCSRA |= (1<<ADSC);
}