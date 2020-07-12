#ifndef _GPIO_H
#define _GPIO_H

#include <avr/io.h>

class GPIO{
    private:
    private:
    public:
    public:
        GPIO();
        void set_input(volatile uint8_t* DIRECTION_REGISTER, uint8_t PIN);
        bool input_status(volatile uint8_t* PORT_REGISTER, uint8_t PIN);
        void set_output(volatile uint8_t* DIRECTION_REGISTER, uint8_t PIN);
        void set_high(volatile uint8_t* PORT_REGISTER, uint8_t PIN);
        void set_low(volatile uint8_t* PORT_REGISTER, uint8_t PIN);
        void toggle_pin(volatile uint8_t* PORT_REGISTER, uint8_t PIN);
        ~GPIO();
};


#endif //_GPIO_H