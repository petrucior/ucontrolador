#
# Makefile
#
FILENAME   = led
PORT       = /dev/cu.usbserial-A600BOBB
DEVICE     = atmega328p
PROGRAMMER = arduino
# BAUD can be 115200, 74888, 57600
BAUD       = 57600
COMPILE    = avr-gcc -Wall -Os -mmcu=$(DEVICE)

default: compile upload clean

compile:
	$(COMPILE) -c $(FILENAME).c -o $(FILENAME).o
	$(COMPILE) -o $(FILENAME).elf $(FILENAME).o
	avr-objcopy -j .text -j .data -O ihex $(FILENAME).elf $(FILENAME).hex
	avr-size --format=avr --mcu=$(DEVICE) $(FILENAME).elf

upload:
	avrdude -v -p $(DEVICE) -c $(PROGRAMMER) -P $(PORT) -b $(BAUD) -U flash:w:$(FILENAME).hex:i

clean:
	rm $(FILENAME).o
	rm $(FILENAME).elf
	rm $(FILENAME).hex
