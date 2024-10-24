## Timers/Counters
- Counting peripheral circuits that perform this task (counting) independently of the CPU
![Timers](https://www.arxterra.com/wp-content/uploads/2018/08/3_AVRcpuBlockDiagram-e1541572879179.jpg)

- Generation of periodic signals/events
- Event count
- Capture and compare functions

There are 3 timers/counters
- 8 bits
  - Calculating range: $[0,(2^{8}-1)]$
  - Range: $[0,255]$
- 16 bits 
  - Calculating range: $[0,(2^{16}-1)]$
  - Range: $[0, 65535]$ 

|                                        Timer/Counter 0 (TC0)                                       |                          Timer/Counter 2 (TC2)                          |
|:--------------------------------------------------------------------------------------------------:|:-----------------------------------------------------------------------:|
|                                               8 bits                                               |                     Caracteristicas similares ao TC0                    |
|                                   Fonte de clock interna/externa                                   | Funçao adicional: contagem precisa de 1s com clock externo de 32,768kHz |
|                      Divisor de clock para contagem de ate 10 bits (prescaler)                     |               Gerador de 2 sinais PWM (pinos OC0A e OC0B)               |
|                                    2 comparadores independentes                                    |                                                                         |
|                             Gerador de 2 sinais PWM (pinos OC0A e OC0B)                            |                                                                         |
|                                Gerador de frequencia (onda quadrada)                               |                                                                         |
| 3 fontes independentes de interrupçao: Por estouro (TOV0) e igualdades de comparaçao (OCF0A/OCF0B) |                                                                         |


|                                  Timer/Counter 1 (TC1)                                  |
|:---------------------------------------------------------------------------------------:|
|                                         16 bits                                         |
|                              Fonte de clock interna/externa                             |
|                Divisor de clock para contagem de ate 10 bits (prescaler)                |
|                               2 comparadores independentes                              |
| Gerador de 2 sinais PWM (pinos OC1A e OC1B) com inumeras possibilidades de configuraçao |
|                          Gerador de frequencia (onda quadrada)                          |
|      4 fontes independentes de interrupçao: Por estouro e igualdades de comparaçao      |
|                                                                                         |


Modos de Operação
- Modo normal
  - O TCn conta continuamente de forma crescente;
  - A contagem se dá de 0 até $(2^{x-1})$ voltando a 0, num ciclo contínuo;
  - O valor da contagem é armazenado no registrador TCNTn;
  - Quando a contagem estoura, o bit sinalizador de estouro (TOVn) é setado para 1. Se habilitada, uma interrupção é gerada (TIMERn OVF)

<p float="left">
  <img src="https://github.com/petrucior/ucontrolador/blob/main/lecture3/midia/normalmodeoperating.png?raw=true" width="50%" />
  <img src="https://user-images.githubusercontent.com/3810960/201368641-8922d0b8-a877-45b8-bbc6-1c0044385f0c.png" width="40%" /> 
</p>

$T_{overflow} = (2^{x})/f_{clk} = (2^{x}) * T_{clk}$

- Modo CTC (Clear Time on Compare)
  - O contador é zerado quando o valor de TCNTn é igual a OCRnA;
  - Uma interrupão pode ser gerada cada vez que o contador atinge o valor de comparação (OCRnA/OCRnB);
  - Permite geração de ondas quadradas nos pinos (OCnA/OCnB)

<p float="left">
  <img src="http://2.bp.blogspot.com/-W3Ww1bLBt8g/UfayQviq4nI/AAAAAAAACFE/Z5oP4mdIh0M/s640/avr_timer0.png" width="50%" />
  <!--img src="https://www.electronicwings.com/storage/PlatformSection/TopicContent/56/description/wave%20generation%20normal%20mode1.png" width="40%" /-->
  <!--img src="https://garretlab.web.fc2.com/en/arduino/inside/hardware/arduino/avr/cores/arduino/wiring_analog.c/fast_pwm1.en.png" width="40%" /-->
  <img src="https://www.electronicwings.com/storage/PlatformSection/TopicContent/56/description/ttimer%20compare%20mode.png" width="40%" />
</p>

$T_{OCRnA} = (OCRnA+1)/f_{clk} = (OCRnA + 1) * T_{clk}$

<!-- ![counters](https://reso-nance.org/wiki/lib/exe/fetch.php?tok=aebab0&media=http%3A%2F%2Farcfn.com%2Fimages%2Fpwm2.gif) -->

![prescaler](https://github.com/petrucior/ucontrolador/blob/main/lecture3/midia/prescaler.png)

## Registers

<h3 id="timers">Timer/Counter Control n Register A (TCCRnA)</h3>
- Configurando modo de operação
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
      <td style="text-align: left">TCCR0A</td>
      <td style="text-align: left">COM0A1</td>
      <td style="text-align: left">COM0A0</td>
      <td style="text-align: left">COM0B1</td>
      <td style="text-align: left">COM0B0</td>
      <td style="text-align: left">-</td>
      <td style="text-align: left">-</td>
      <td style="text-align: left">WGM01</td>
      <td style="text-align: left">WGM00</td>
    </tr>
  </tbody>
</table>

<table><thead>
  <tr>
    <th colspan="3">Modo CTC</th>
  </tr></thead>
<tbody>
  <tr>
    <td>COM0A1</td>
    <td>COM0A0</td>
    <td>Descrição</td>
  </tr>
  <tr>
    <td>0</td>
    <td>0</td>
    <td>Operação normal do pino, OC0A desconectado.</td>
  </tr>
  <tr>
    <td>0</td>
    <td>1</td>
    <td>Mudança do estado de OC0A na igualdade de<br>comparação.</td>
  </tr>
  <tr>
    <td>1</td>
    <td>0</td>
    <td>OC0A é limpo na igualdade de comparação.</td>
  </tr>
  <tr>
    <td>1</td>
    <td>1</td>
    <td>OC0A é ativo na igualdade de comparação.</td>
  </tr>
</tbody>
</table>

<table><thead>
  <tr>
    <th>Modo</th>
    <th>WGM02</th>
    <th>WGM01</th>
    <th>WGM00</th>
    <th>Modo de <br>Operação <br>TC</th>
    <th>TOP</th>
    <th>Atualização <br>de OCR0A</th>
    <th>Sinalização <br>do bit TOV0</th>
  </tr></thead>
<tbody>
  <tr>
    <td>0</td>
    <td>0</td>
    <td>0</td>
    <td>0</td>
    <td>Normal</td>
    <td>0xFF</td>
    <td>Imediata</td>
    <td>0xFF</td>
  </tr>
  <tr>
    <td>1</td>
    <td>0</td>
    <td>0</td>
    <td>1</td>
    <td>PWM com <br>fase corrigida</td>
    <td>0xFF</td>
    <td>0xFF</td>
    <td>0x00</td>
  </tr>
  <tr>
    <td>2</td>
    <td>0</td>
    <td>1</td>
    <td>0</td>
    <td>CTC</td>
    <td>OCR0A</td>
    <td>Imediata</td>
    <td>0xFF</td>
  </tr>
  <tr>
    <td>3</td>
    <td>0</td>
    <td>1</td>
    <td>1</td>
    <td>PWM rápido</td>
    <td>0xFF</td>
    <td>0x00</td>
    <td>0xFF</td>
  </tr>
  <tr>
    <td>4</td>
    <td>0</td>
    <td>1</td>
    <td>1</td>
    <td>Reservado</td>
    <td>-</td>
    <td>-</td>
    <td>-</td>
  </tr>
  <tr>
    <td>5</td>
    <td>1</td>
    <td>0</td>
    <td>1</td>
    <td>PWM com<br>fase corrigida</td>
    <td>OCR0A<br></td>
    <td>OCR0A<br></td>
    <td>0x00</td>
  </tr>
  <tr>
    <td>6</td>
    <td>1</td>
    <td>1</td>
    <td>0</td>
    <td>Reservado</td>
    <td>-</td>
    <td>-</td>
    <td>-</td>
  </tr>
  <tr>
    <td>7</td>
    <td>1</td>
    <td>1</td>
    <td>1</td>
    <td>PWM rápido</td>
    <td>OCR0A<br></td>
    <td>0x00</td>
    <td>OCR0A</td>
  </tr>
</tbody>
</table>

<!-- ![modos](https://github.com/petrucior/ucontrolador/blob/main/lecture3/midia/modos.png) -->

<h3 id="timers">Timer/Counter Control n Register B (TCCRnB)</h3>
- Definir preescaler
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
      <td style="text-align: left">TCCR0B</td>
      <td style="text-align: left">FOC0A</td>
      <td style="text-align: left">FOC0B</td>
      <td style="text-align: left">-</td>
      <td style="text-align: left">-</td>
      <td style="text-align: left">WGM02</td>
      <td style="text-align: left">CS02</td>
      <td style="text-align: left">CS01</td>
      <td style="text-align: left">CS00</td>
    </tr>
  </tbody>
</table>

**Bits 7:6 – FOC0A:B – Force Output Compare A e B**
- Estes bits são ativos somente para os modos não-PWM. Quando em 1, uma
comparação é forçada no módulo gerador de onda.

<table><thead>
  <tr>
    <th colspan="4">Seleção do CLOCK para o TC0</th>
  </tr></thead>
<tbody>
  <tr>
    <td>CS02</td>
    <td>CS01</td>
    <td>CS00</td>
    <td>Descrição</td>
  </tr>
  <tr>
    <td>0</td>
    <td>0</td>
    <td>0</td>
    <td>Sem fonte de clock (TC0 parado)</td>
  </tr>
  <tr>
    <td>0</td>
    <td>0</td>
    <td>1</td>
    <td>clock/1 (prescaler=1) - sem prescaler</td>
  </tr>
  <tr>
    <td>0</td>
    <td>1</td>
    <td>0</td>
    <td>clock/8 (prescaler = 8)</td>
  </tr>
  <tr>
    <td>0</td>
    <td>1</td>
    <td>1</td>
    <td>clock/64 (prescaler = 64)</td>
  </tr>
  <tr>
    <td>1</td>
    <td>0</td>
    <td>0</td>
    <td>clock/256 (prescaler = 256)</td>
  </tr>
  <tr>
    <td>1</td>
    <td>0</td>
    <td>1</td>
    <td>clock/1024 (prescaler = 1024)</td>
  </tr>
  <tr>
    <td>1</td>
    <td>1</td>
    <td>0</td>
    <td>clock externo no pino T0. Contagem<br>na borda de descida.</td>
  </tr>
  <tr>
    <td>1</td>
    <td>1</td>
    <td>1</td>
    <td>clock externo no pino T0. Contagem<br>na borda de subida.</td>
  </tr>
</tbody></table>

<!-- ![pscaler](https://github.com/petrucior/ucontrolador/blob/main/lecture3/midia/registerprescaler.png) -->

- Alguns registradores dos contadores
<!-- ![registersdatapath](https://github.com/petrucior/ucontrolador/blob/main/lecture3/midia/regsdatapath.png)-->

**TCNT0 – Timer/Counter 0 Register**
- Registrador de 8 bits onde é realizada a contagem do TC0, pode ser lido ou escrito a qualquer tempo.

**OCR0A – Output Compare 0 Register A**
- Registrador de comparação A de 8 bits, possui o valor que é continuamente comparado com o valor do contador (TCNT0). A igualdade pode ser utilizada
para gerar uma interrupção ou uma forma de onda no pino OC0A.

**OCR0B – Output Compare 0 Register B**
- Registrador de comparação B de 8 bits, possui o valor que é continuamente comparado com o valor do contador (TCNT0). A igualdade pode ser utilizada para
gerar uma interrupção ou uma forma de onda no pino OC0B.

- Registradores para interrupções
![interrupt](https://github.com/petrucior/ucontrolador/blob/main/lecture3/midia/interrupcoes.png)

- Flags de erros
![flags](https://github.com/petrucior/ucontrolador/blob/main/lecture3/midia/flagserrors.png)
