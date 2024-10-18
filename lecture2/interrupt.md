## Interrupt
![interruption](https://4.bp.blogspot.com/-vCBigov2SLc/V7YlXikbjaI/AAAAAAAABJY/lRSiYIU59L0rE5-jkhE_w_NfCyecsHuoQCLcB/s1600/Int-fig1.jpg)

![priority](https://i.pinimg.com/736x/42/b1/65/42b16572039efbebca0deb8ff7386c84.jpg)

- Single address for interrupt (vector)
- Individually enabled/disabled (maskable)
<!-- - Bit 1 of SREG = 0 while interrupt is being handled
- Bit 1 of SREG = 1 when interrupt ends -->

<!-- ## ![PIN CONFIGURATIONS - ATMEGA328p (28-pins)](https://ww1.microchip.com/downloads/en/DeviceDoc/Atmel-7810-Automotive-Microcontrollers-ATmega328P_Datasheet.pdf)

![pinsatmega](https://microcontrollerslab.com/wp-content/uploads/2019/12/ATMEGA328P-Pin-Configuration-Diagram.png)

![pinout](https://cdn.shopify.com/s/files/1/0452/2564/0087/files/Pinout_of_ARDUINO_Board_and_ATMega328PU_Kobee.png?v=1629648438) -->

### Interrupções

| **Endereço** 	| **Fonte** 	|    **Definição de Interrupção**   	|                 **Descrição**                 	|
|:------------:	|:---------:	|:---------------------------------:	|:---------------------------------------------:	|
|     0x01     	|    INT0   	|       Interrupção Externa 0       	|      Subida, descida ou nivel do pino PD2     	|
|     0x02     	|    INT1   	|       Interrupção Externa 1       	|      Subida, descida ou nivel do pino PD3     	|
|     0x03     	|   PCINT0  	| Interrupção 0 por mudança de pino 	| Mudança de estado em qualquer pino da porta B 	|
|     0x04     	|   PCINT1  	| Interrupção 1 por mudança de pino 	| Mudança de estado em qualquer pino da porta C 	|
|     0x05     	|   PCINT2  	| Interrupção 2 por mudança de pino 	| Mudança de estado em qualquer pino da porta D 	|

![INTs](https://ouilogique.com/files/2016-10-21-interruptions/images/ATmega328-INTx.jpg)

<h3 id="external-interrupt-control-register-a">External Interrupt Control Register A (EICRA)</h3>
<h4> Configuração das interrupções externas INT0 e INT1 </h4>

<table>
  <thead>
    <tr>
      <th style="text-align: left"> </th>
      <th style="text-align: left">7 bit</th>
      <th style="text-align: left">6 bit</th>
      <th style="text-align: left">5 bit</th>
      <th style="text-align: left">4 bit</th>
      <th style="text-align: left">3 bit</th>
      <th style="text-align: left">2 bit</th>
      <th style="text-align: left">1 bit</th>
      <th style="text-align: left">0 bit</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td style="text-align: left">EICRA</td>
      <td style="text-align: left">-</td>
      <td style="text-align: left">-</td>
      <td style="text-align: left">-</td>
      <td style="text-align: left">-</td>
      <td style="text-align: left">ISC11</td>
      <td style="text-align: left">ISC10</td>
      <td style="text-align: left">ISC01</td>
      <td style="text-align: left">ISC00</td>
    </tr>
  </tbody>
</table>

<h3 id="isc-bit-settings">ISC Bit Settings</h3>

<table>
  <thead>
    <tr>
      <th style="text-align: left">ISCx1</th>
      <th style="text-align: left">ISCx0</th>
      <th style="text-align: left">DESCRIPTION</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td style="text-align: left">0</td>
      <td style="text-align: left">0</td>
      <td style="text-align: left">Low level of INTx generates an interrupt request</td>
    </tr>
    <tr>
      <td style="text-align: left">0</td>
      <td style="text-align: left">1</td>
      <td style="text-align: left">Any logic change on INTx generates an interrupt request</td>
    </tr>
    <tr>
      <td style="text-align: left">1</td>
      <td style="text-align: left">0</td>
      <td style="text-align: left">The falling edge of INTx generates an interrupt request</td>
    </tr>
    <tr>
      <td style="text-align: left">1</td>
      <td style="text-align: left">1</td>
      <td style="text-align: left">The rising edge of INTx generates an interrupt request</td>
    </tr>
  </tbody>
</table>

<h3 id="external-interrupt-mask-register">External Interrupt Mask Register (EIMSK)</h3>
<h4> Habilita as interrupções externas INT0 e INT1 </h4>

<table>
  <thead>
    <tr>
      <th style="text-align: left"> </th>
      <th style="text-align: left">7 bit</th>
      <th style="text-align: left">6 bit</th>
      <th style="text-align: left">5 bit</th>
      <th style="text-align: left">4 bit</th>
      <th style="text-align: left">3 bit</th>
      <th style="text-align: left">2 bit</th>
      <th style="text-align: left">1 bit</th>
      <th style="text-align: left">0 bit</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td style="text-align: left">EIMSK</td>
      <td style="text-align: left">-</td>
      <td style="text-align: left">-</td>
      <td style="text-align: left">-</td>
      <td style="text-align: left">-</td>
      <td style="text-align: left">-</td>
      <td style="text-align: left">-</td>
      <td style="text-align: left">INT1</td>
      <td style="text-align: left">INT0</td>
    </tr>
  </tbody>
</table>

<h3 id="external-interrupt-flag-register">External Interrupt Flag Register (EIFR)</h3>
<h4> Contém os dois bits sinalizadores que indicam se alguma interrupção externa ocorreu</h4>

- Bit = 1, enquanto a interrupção não é tratada.

- Bit = 0, quando a interrupção finaliza
<table>
  <thead>
    <tr>
      <th style="text-align: left"> </th>
      <th style="text-align: left">7 bit</th>
      <th style="text-align: left">6 bit</th>
      <th style="text-align: left">5 bit</th>
      <th style="text-align: left">4 bit</th>
      <th style="text-align: left">3 bit</th>
      <th style="text-align: left">2 bit</th>
      <th style="text-align: left">1 bit</th>
      <th style="text-align: left">0 bit</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td style="text-align: left">EIFR</td>
      <td style="text-align: left">-</td>
      <td style="text-align: left">-</td>
      <td style="text-align: left">-</td>
      <td style="text-align: left">-</td>
      <td style="text-align: left">-</td>
      <td style="text-align: left">-</td>
      <td style="text-align: left">INTF1</td>
      <td style="text-align: left">INTF0</td>
    </tr>
  </tbody>
</table>

## [Interrupt handler functions](https://www.nongnu.org/avr-libc/user-manual/group__avr__interrupts.html)

<div class="language-c++ highlighter-rouge"><div class="highlight"><pre class="highlight"><code>
<span class="cp">#include</span> <span class="cpf">&lt;avr/io.h&gt;</span><span class="cp">
#include</span> <span class="cpf">&lt;avr/interrupt.h&gt;</span><span class="cp">
</span>
<span class="kt">int</span> <span class="nf">main</span><span class="p">(</span><span class="kt">void</span><span class="p">)</span>
<span class="p">{</span>
  <span class="n">DDRD</span> <span class="o">&amp;=</span> <span class="o">~</span><span class="p">(</span><span class="mi">1</span> <span class="o">&lt;&lt;</span> <span class="n">DDD2</span><span class="p">);</span>     <span class="c1">// Clear the PD2 pin</span>
  <span class="c1">// PD2 (PCINT0 pin) is now an input</span>

  <span class="n">PORTD</span> <span class="o">|=</span> <span class="p">(</span><span class="mi">1</span> <span class="o">&lt;&lt;</span> <span class="n">PORTD2</span><span class="p">);</span>    <span class="c1">// turn On the Pull-up</span>
  <span class="c1">// PD2 is now an input with pull-up enabled</span>

  <span class="n">EICRA</span> <span class="o">|=</span> <span class="p">(</span><span class="mi">1</span> <span class="o">&lt;&lt;</span> <span class="n">ISC00</span><span class="p">);</span>    <span class="c1">// set INT0 to trigger on ANY logic change</span>
  <span class="n">EIMSK</span> <span class="o">|=</span> <span class="p">(</span><span class="mi">1</span> <span class="o">&lt;&lt;</span> <span class="n">INT0</span><span class="p">);</span>     <span class="c1">// Turns on INT0</span>

  <span class="n">sei</span><span class="p">();</span>                    <span class="c1">// turn on interrupts</span>

  <span class="k">while</span><span class="p">(</span> <span class="mi">1</span> <span class="p">)</span>
  <span class="p">{</span>
    <span class="cm">/*main program loop here */</span>
  <span class="p">}</span>
<span class="p">}</span>

<span class="n">ISR</span><span class="p">(</span> <span class="n">INT0_vect</span> <span class="p">)</span>
<span class="p">{</span>
  <span class="cm">/* interrupt code here */</span>
<span class="p">}</span>
</code></pre></div></div>


## [Interrupt handler functions](https://www.nongnu.org/avr-libc/user-manual/group__avr__interrupts.html)

![pinout_interrupt](https://i0.wp.com/portal.vidadesilicio.com.br/wp-content/uploads/2017/05/UNOMAP2-1024x614-1024x614.png)

### PCICR (Pin Change Interrupt Control Register): The register is responsible for enabling interrupt on a given PORT when the respective PCIEx bit is set to 1.
![pcicr](https://i0.wp.com/portal.vidadesilicio.com.br/wp-content/uploads/2017/05/pcicr.png)

### PCMSK (Pin Change Mask Register): This register is responsible for enabling the interrupt of a pin on a given PORT. So, there are 3 registers of this type PCMSK0, PCMSK1 and PCMSK2 referring to PORTS B, C and D respectively.

![pcmsk0](https://i0.wp.com/portal.vidadesilicio.com.br/wp-content/uploads/2017/05/pcmsk0.png)

![pcmsk1](https://i0.wp.com/portal.vidadesilicio.com.br/wp-content/uploads/2017/05/pcmks1.png)

![pcmsk2](https://i0.wp.com/portal.vidadesilicio.com.br/wp-content/uploads/2017/05/pcmsk2.png)

<div class="language-c++ highlighter-rouge"><div class="highlight"><pre class="highlight"><code><span class="cp">#include</span> <span class="cpf">&lt;avr/io.h&gt;</span><span class="cp">
#include</span> <span class="cpf">&lt;avr/interrupt.h&gt;</span><span class="cp">
</span>

<span class="kt">int</span> <span class="nf">main</span><span class="p">(</span><span class="kt">void</span><span class="p">)</span>
<span class="p">{</span>
    <span class="n">DDRB</span> <span class="o">&amp;=</span> <span class="o">~</span><span class="p">(</span><span class="mi">1</span> <span class="o">&lt;&lt;</span> <span class="n">DDB0</span><span class="p">);</span>     <span class="c1">// Clear the PB0 pin</span>
    <span class="c1">// PB0 (PCINT0 pin) is now an input</span> 
    <span class="n">PORTB</span> <span class="o">|=</span> <span class="p">(</span><span class="mi">1</span> <span class="o">&lt;&lt;</span> <span class="n">PORTB0</span><span class="p">);</span>    <span class="c1">// turn On the Pull-up</span>
    <span class="c1">// PB0 is now an input with pull-up enabled</span>
    <span class="n">PCICR</span> <span class="o">|=</span> <span class="p">(</span><span class="mi">1</span> <span class="o">&lt;&lt;</span> <span class="n">PCIE0</span><span class="p">);</span>    <span class="c1">// set PCIE0 to enable PCMSK0 scan</span>
    <span class="n">PCMSK0</span> <span class="o">|=</span> <span class="p">(</span><span class="mi">1</span> <span class="o">&lt;&lt;</span> <span class="n">PCINT0</span><span class="p">);</span>  <span class="c1">// set PCINT0 to trigger an interrupt on state change</span>
    <span class="n">sei</span><span class="p">();</span>                    <span class="c1">// turn on interrupts</span>
    <span class="k">while</span><span class="p">(</span><span class="mi">1</span><span class="p">)</span>
    <span class="p">{</span>
        <span class="cm">/*main program loop here */</span>
    <span class="p">}</span>
<span class="p">}</span>



<span class="n">ISR</span> <span class="p">(</span><span class="n">PCINT0_vect</span><span class="p">)</span>
<span class="p">{</span>
    <span class="cm">/* interrupt code here */</span>
<span class="p">}</span>
</code></pre></div></div>

### SREG – Global Interrupt Flag
- sei(); // Enable all interrupts
- cli(); // Disable all interrupts

![review](https://i0.wp.com/portal.vidadesilicio.com.br/wp-content/uploads/2017/05/PCINTESQUEMA.png)

<!-- ## External interrupts
![INT0_1](https://startingelectronics.org/tutorials/AVR-8-microcontrollers/ATtiny2313-tutorial/P5-pin-alternate-functions/ATtiny2313-int0-int1.png)

![externalinterrupts](http://www.ermicro.com/blog/wp-content/uploads/2013/09/motor_cnt15.jpg) -->
