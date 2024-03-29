# AVR-BRIDGE SOFTWARE STACK
This is a software stack optimized for the Atmega328p to enable it be used as an I/O and ADC expander via USART.

## How it works
The software stack uses "CROSS" commands to exchange data across the "BRIDGE". This is simillar to how we use "AT" commands with most of the available wireless modules. This enables increased number of GPIO, ADCs and other periferals to other microcontrollers with limited I/O e.g ESP8266.

Both configuration and control is attained using the "CROSS" commands listed in the "commands.h" file. For example to toggle an I/O pin on the atmaga, the process would be configured as shown below. This sample was implemented using the ESP8266.
        /**
        * This code is uploaded onto the ESP8266
        */
        
        #include <Arduino.h>

        void setup(){
            /* Set communication baudrate */
            Serial.begin(9600);
            /* Configure Pin B0 as output, The Atmega will respond with "OK" if the process was successful */
            Serial.println("CROSS+OUTPUT_B0");
            /* This delay allows time for the Atmega to process the Instruction and respond */
            delay(5);
            
        }

        void loop(){
            /* Set the pin High */
            Serial.println("CROSS+HIGH_B0");
            delay(1000);
            Serial.println("CROSS+LOW_B0);
            delay(1000);
                    
        }
        
To obtain 10 bit ADC value from Atmega328p ADC0.

        /**
        * This code is uploaded onto the ESP8266
        */
        
        #include <Arduino.h>

        void setup(){
            /* Set communication baudrate */
            Serial.begin(9600);
            /* Configure Pin B0 as output, The Atmega will respond with "OK" if the process was successful */
            Serial.println("CROSS+ADC0");
            /* This delay allows time for the Atmega to process the Instruction and respond */
            delay(5);
            /* Check if there is any serial data available */
            while(Serial.available() > 0){
                /* Store the received ADC value */
                String ADC_value = Serial.readString();
             }
            
            
        }

        void loop(){
            
        }


The software stack also supports obtaining ADC values and Digital Input. The process is as easy as sending a Serial Command and receiving the response serially via USART.

## Testing setup
The system testing circuit board that contains both the ESP8266 and the Atmega328p designed using KiCAD can be found at https://github.com/MCLEANS/AVR-BRIDGE-ATMEGA328P-PCB (The hardware is open-source and open to use).

![circuit board](https://pbs.twimg.com/media/EdUHqd8WoAE1fRa?format=jpg&name=medium)

## How to set up the compilation environment.
### Installing Make
Linux

    $ sudo apt install make

Mac OS 

    $ brew install make

### Installing avr-gcc
Linux 

    $ sudo apt install gcc-avr binutils avr-libc

Mac OS

    $ brew install gcc-avr binutils avr-libc

### Installing avrdude 
Linux 

    $ sudo apt install avrdude

Mac OS

    $ brew install avrdude

## Installing for Windows
The installation procesure for the AVR build environment for windows can be found here https://www.newbiehack.com/MicrocontrollerProgrammingEnvironmentWinAVRInstall.aspx

## Compiling the software

    $ make

## To flash onto your microcontroller
The flash command is configured for the USBasp but can be optimized for other programmers

    $ make flash



        
