## Interrupt
![interruption](https://4.bp.blogspot.com/-vCBigov2SLc/V7YlXikbjaI/AAAAAAAABJY/lRSiYIU59L0rE5-jkhE_w_NfCyecsHuoQCLcB/s1600/Int-fig1.jpg)

![priority](https://i.pinimg.com/736x/42/b1/65/42b16572039efbebca0deb8ff7386c84.jpg)

- Single address for interrupt (vector)
- Individually enabled/disabled (maskable)
- Bit 1 of SREG = 0 while interrupt is being handled
- Bit 1 of SREG = 1 when interrupt ends

## ![PIN CONFIGURATIONS - ATMEGA328p (28-pins)](https://ww1.microchip.com/downloads/en/DeviceDoc/Atmel-7810-Automotive-Microcontrollers-ATmega328P_Datasheet.pdf)

![pinsatmega](https://microcontrollerslab.com/wp-content/uploads/2019/12/ATMEGA328P-Pin-Configuration-Diagram.png)

![pinout](https://cdn.shopify.com/s/files/1/0452/2564/0087/files/Pinout_of_ARDUINO_Board_and_ATMega328PU_Kobee.png?v=1629648438)

## [Interrupt handler functions](https://www.nongnu.org/avr-libc/user-manual/group__avr__interrupts.html)
![program](https://media-exp1.licdn.com/dms/image/C4D12AQFCa4rh7SZj3g/article-inline_image-shrink_1000_1488/0/1595232397509?e=1658361600&v=beta&t=gmwj9Aotpxvf6xbuocyqFJ-lXqG4BdQ4hM7CA8SgFIo)

![pinout_interrupt](https://i0.wp.com/portal.vidadesilicio.com.br/wp-content/uploads/2017/05/UNOMAP2-1024x614-1024x614.png)

### PCICR (Pin Change Interrupt Control Register): The register is responsible for enabling interrupt on a given PORT when the respective PCIEx bit is set to 1.
![pcicr](https://i0.wp.com/portal.vidadesilicio.com.br/wp-content/uploads/2017/05/pcicr.png)

### PCMSK (Pin Change Mask Register): This register is responsible for enabling the interrupt of a pin on a given PORT. So, there are 3 registers of this type PCMSK0, PCMSK1 and PCMSK2 referring to PORTS B, C and D respectively.

![pcmsk0](https://i0.wp.com/portal.vidadesilicio.com.br/wp-content/uploads/2017/05/pcmsk0.png)

![pcmsk1](https://i0.wp.com/portal.vidadesilicio.com.br/wp-content/uploads/2017/05/pcmks1.png)

![pcmsk2](https://i0.wp.com/portal.vidadesilicio.com.br/wp-content/uploads/2017/05/pcmsk2.png)

### SREG – Global Interrupt Flag
- sei(); // Enable all interrupts
- cli(); // Disable all interrupts

![review](https://i0.wp.com/portal.vidadesilicio.com.br/wp-content/uploads/2017/05/PCINTESQUEMA.png)

## External interrupts
![externalinterrupts](http://www.ermicro.com/blog/wp-content/uploads/2013/09/motor_cnt15.jpg)
