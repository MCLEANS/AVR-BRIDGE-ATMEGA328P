MCU = atmega32
TARGET = main
PROGRAMMER =  usbasp
PORT = usb
CC = avr-g++
CFLAGS = -Os -D F_CPU=1000000 -mmcu=$(MCU) 
LFLAGS = -D F_CPU=1000000 -mmcu=$(MCU) 



hex :
	$(CC) $(CFLAGS) -c $(TARGET).cpp  UART.cpp ADC.cpp
	$(CC) $(LFLAGS) -o $(TARGET).elf $(TARGET).o UART.o ADC.o
	avr-objcopy -O ihex $(TARGET).elf $(TARGET).hex
	avr-size --format=avr --mcu=$(MCU) $(TARGET).elf


flash :
	avrdude -c $(PROGRAMMER) -p m2560 -P $(PORT) -U flash:w:$(TARGET).hex

clean :
	rm *.hex *.o *.elf
	
