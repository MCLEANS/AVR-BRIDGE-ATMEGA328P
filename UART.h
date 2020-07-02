#ifndef _UART_H
#define _UART_H 

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

#define BUFFER_SIZE 256





class UART{

    private:
        
        
    private:
        void set_baudrate(uint32_t baud);
        void send_char(char data);
        
        

    public:
        uint8_t buffer_position;
        bool is_endline;
        char receive_buffer[BUFFER_SIZE];

    public:
        UART();
        void init(uint32_t baudrate);
        void send_string(char *data);
        char receive_char() const;
        void flush_buffer();
      


};


#endif //_UART_H