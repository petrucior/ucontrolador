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
  - A contagem se dá de 0 até $2^{x-1}$ voltando a 0, num ciclo contínuo;
  - O valor da contagem é armazenado no registrador TCNTn;
  - Quando a contagem estoura, o bit sinalizador de estouro (TOVn) é setado para 1. Se habilitada, uma interrupção é gerada (TIMERn OVF)

- Modo CTC (Clear Time on Compare)
  - O contador é zerado quando o valor de TCNTn é igual a OCRnA;
  - Uma interrupão pode ser gerada cada vez que o contador atinge o valor de comparação (OCRnA/OCRnB);
  - Permite geração de ondas quadradas nos pinos (OCnA/OCnB)

![timers](http://2.bp.blogspot.com/-W3Ww1bLBt8g/UfayQviq4nI/AAAAAAAACFE/Z5oP4mdIh0M/s640/avr_timer0.png)

![counter](https://i0.wp.com/embedds.com/wp-content/uploads/2010/12/250_counts_normal_mode.png)

$T_{overflow} = 2^{x-1}/f_{clk} = 2^{x-1} * T_{clk}$

![counter2](https://www.electronicwings.com/images/user_images/images/ATmega_20160622/ATmega_Comapre(CTC%20mode)/wave%20generation%20normal%20mode1.png)

$T_{OCRnA} = (OCRnA+1)/f_{clk} = (OCRnA + 1) * T_{clk}$

![prescaler](https://github.com/petrucior/ucontrolador/blob/main/lecture3/midia/prescaler.png)

## Registers

- Configurando modo de operação
![modos](https://github.com/petrucior/ucontrolador/blob/main/lecture3/midia/modos.png)

- Definindo preescaler
![pscaler](https://github.com/petrucior/ucontrolador/blob/main/lecture3/midia/registerprescaler.png)

- Alguns registradores do datapath
![registersdatapath](https://github.com/petrucior/ucontrolador/blob/main/lecture3/midia/regsdatapath.png)

- Registradores para interrupções
![interrupt](https://github.com/petrucior/ucontrolador/blob/main/lecture3/midia/interrupcoes.png)

- Flags de erros
![flags](https://github.com/petrucior/ucontrolador/blob/main/lecture3/midia/flagserrors.png)
