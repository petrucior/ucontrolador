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
REG = REG ^ 0b0000_1000;  // REG = xxxx_0x0x
REG ^= 0b0000_1000);      // REG = xxxx_0x0x
REG ^= 0x08;              // REG = xxxx_0x0x
REG ^= (1 << 3);          // REG = xxxx_0x0x
```
- 2-bit
```
(1 << 1)                           ---> 0000_0010
(1 << 3)                           ---> 0000_1000
(1 << 1) | (1 << 3)                ---> 0000_1010
xxxx_xxxx ^ ((1 << 1) | (1 << 3))  ---> xxxx_0x1x
```
- C code sintax (2-bit)
```
REG ^= ((1 << 1) | (1 << 3));  // REG = xxxx_0x1x
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

