#ifndef _ADC_H
#define _ADC_H

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

struct ADC_channel_value{
    uint16_t channel_0;
    uint16_t channel_1;
    uint16_t channel_2;
    uint16_t channel_3;
    uint16_t channel_4;
    uint16_t channel_5;
    uint16_t channel_6;
    uint16_t channel_7;
    uint16_t channel_8;
    uint16_t channel_9;
    uint16_t channel_10;
    uint16_t channel_11;
    uint16_t channel_12;
    uint16_t channel_13;
    uint16_t channel_14;
    uint16_t channel_15;
};

class _ADC {
    private:
    private:
    public:
        uint16_t value;
    public:
        _ADC();
        void init();
        uint16_t get_value();
        void convert();
};



#endif //_ADC_H