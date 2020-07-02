#ifndef _ADC_H
#define _ADC_H

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

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