## Setting microcontroller registers
- 8-bit register
```
      7654_3210
REG = xxxx_xxxx
```
1. Or table (turn on bit)
```
      OR 
--------------
0  |  0  =  0
0  |  1  =  1
1  |  0  =  1
1  |  1  =  1
```
```
prev | 0 = prev
prev | 1 = 1
```
- 1-bit
```
xxxx_xxxx | 0000_1000 ---> xxxx_1xxx
xxxx_xxxx | 0000_1010 ---> xxxx_1x1x
```
- C code sintax (1-bit)
```
REG = REG | 0b0000_1000; // REG = xxxx_1xxx
REG |= 0b0000_1000;      // REG = xxxx_1xxx
REG |= 0x08;             // REG = xxxx_1xxx
REG |= (1 << 3);         // REG = xxxx_1xxx
```
- 2-bit
```
(1 << 1)                        ---> 0000_0010
(1 << 3)                        ---> 0000_1000
(1 << 1) | (1 << 3)             ---> 0000_1010
xxxx_xxxx | (1 << 1) | (1 << 3) ---> xxxx_1x1x
```
- C code sintax (2-bit)
```
REG |= (1 << 1) | (1 << 3); // REG = xxxx_1x1x
```

2. And table (turn off bit)
```
      And 
--------------
0  &  0  =  0
0  &  1  =  0
1  &  0  =  0
1  &  1  =  1
```
```
prev & 0 = 0
prev & 1 = prev
```
- 1-bit
```
xxxx_xxxx & 1111_0111    ---> xxxx_0xxx
xxxx_xxxx & ~(0000_1000) ---> xxxx_0xxx
xxxx_xxxx & ~(0000_1010) ---> xxxx_0x0x
```
- C code sintax (1-bit)
```
REG = REG & ~(0b0000_1000); // REG = xxxx_0xxx
REG &= ~(0b0000_1000);      // REG = xxxx_0xxx
REG &= ~(0x08);             // REG = xxxx_0xxx
REG &= ~(1 << 3);           // REG = xxxx_0xxx
```
- 2-bit
```
(1 << 1)                           ---> 0000_0010
(1 << 3)                           ---> 0000_1000
(1 << 1) | (1 << 3)                ---> 0000_1010
xxxx_xxxx & ~((1 << 1) | (1 << 3)) ---> xxxx_0x0x
```
- C code sintax (2-bit)
```
REG &= ~((1 << 1) | (1 << 3));  // REG = xxxx_0x0x
```

3. Xor table (toggle bit)
```
      XOR 
--------------
0  ^  0  =  0
0  ^  1  =  1
1  ^  0  =  1
1  ^  1  =  0
```
```
prev ^ 0 = prev
prev ^ 1 = ~prev
```
- 1-bit
```
xxxx_1x0x ^ 0000_1000 ---> xxxx_0x0x
xxxx_1x0x ^ 0000_1010 ---> xxxx_0x1x
```
- C code sintax (1-bit)
```
REG = REG ^ 0b0000_1000;  // REG = xxxx_~xxxx
REG ^= 0b0000_1000);      // REG = xxxx_~xxxx
REG ^= 0x08;              // REG = xxxx_~xxxx
REG ^= (1 << 3);          // REG = xxxx_~xxxx
```
- 2-bit
```
(1 << 1)                           ---> 0000_0010
(1 << 3)                           ---> 0000_1000
(1 << 1) | (1 << 3)                ---> 0000_1010
xxxx_xxxx ^ ((1 << 1) | (1 << 3))  ---> xxxx_~xx~xx
```
- C code sintax (2-bit)
```
REG ^= ((1 << 1) | (1 << 3));  // REG = xxxx_~xx~xx
```

Appendix
- Shift left (<<)
```
1                     ---> 0000_0001

               bin         dec  hex
1 << 0 ---> 0000_0001  //   1    01
1 << 1 ---> 0000_0010  //   2    02
1 << 2 ---> 0000_0100  //   4    04
1 << 3 ---> 0000_1000  //   8    08
1 << 4 ---> 0001_0000  //  16    10
1 << 5 ---> 0010_0000  //  32    20
1 << 6 ---> 0100_0000  //  64    40
1 << 7 ---> 1000_0000  // 128    80
```

## [PIN CONFIGURATIONS - ATMEGA328p (28-pins)](https://ww1.microchip.com/downloads/en/DeviceDoc/Atmel-7810-Automotive-Microcontrollers-ATmega328P_Datasheet.pdf)

![pinsatmega](https://microcontrollerslab.com/wp-content/uploads/2019/12/ATMEGA328P-Pin-Configuration-Diagram.png)

![pinschematics](https://i.stack.imgur.com/mIA54.png)

![pinregister](https://www.arnabkumardas.com/blog/wp-content/uploads/2018/12/image-1.png)
1. DDRxn
   - The DDxn bit in the DDRx register selects the direction of this pin. If DDxn is written logic one, Pxn is configured as an output
pin. If DDxn is written logic zero, Pxn is configured as an input pin.
2. PORTxn
   - If PORTxn is written logic one when the pin is configured as an input pin, the pull-up resistor is activated. To switch the
pull-up resistor off, PORTxn has to be written logic zero or the pin has to be configured as an output pin.
   - If PORTxn is written logic one when the pin is configured as an output pin, the port pin is driven high (one). If PORTxn is
written logic zero when the pin is configured as an output pin, the port pin is driven low (zero).
3. PINx
   - This register is used to read the data from the port pins. Before reading the data from the port pins, the ports needs to be configured as Inputs. 

<!-- ![registers](https://www.arxterra.com/wp-content/uploads/2018/08/EE444-Lecture-3-IO-port-pin-configurations.jpg) -->

