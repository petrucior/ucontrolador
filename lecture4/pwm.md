## Pulse Width Modulation (PWM)

 <table style="float:right">
  <tr>
    <td>
      <ul>
        <li>Sinal Periódico;</li>
        <li>Binário</li>
        <li>Normalmente o período é fixo;</li>
        <math>
        <b>Duty cycle</b> (ciclo de trabalho) = t<sub>high</sub> / t<sub>high</sub> + t<sub>low</sub>
        </math>
        <li>Duty cycle variável implica no valor médio variável</li>
      </ul> 
    </td>
    <td>
     <img src="https://static.wixstatic.com/media/d63230_2efb8fc9651d4bfeaf816600ec662eb1~mv2.gif" alt="signal" width="100%" height="100%" style="vertical-align:middle">
    </td>
  </tr>
</table> 

## Modo de Operação do TCN: Modo PWM Rápido
<table style="float:right">
  <tr>
    <td>
     <img src="https://blogger.googleusercontent.com/img/b/R29vZ2xl/AVvXsEiU2S4JqB4NH_HpJ_yAoV54W4Gx7bHmvx5dVqaPvyWLoYrDGTOaDezWeToiUx3QiziC5_r_FxA1Prxcee0dFBLKeli2dvOw-8XMn2RM7McwpyTR1mvk38bfxvCYGqeMjRmEWjPMfRQSRUY/s1600/12.png" alt="signal" width="100%" height="100%" style="vertical-align:middle">
   </td>
   <td>
      <ul>
        <li>O TCn conta continuamente de forma crescente;</li>
        <li>A contagem se dá de 0 até $2^{x}-1$ voltando a 0, num ciclo contínuo;</li>
        <li>O valor da contagem é armazenado no registrador TCNTn;</li>
      </ul>
     <img src="https://www.electronicwings.com/storage/PlatformSection/TopicContent/55/description/timer%20value.png" alt="signal" width="50%" height="50%" style="vertical-align:middle">
    </td>
  </tr>
</table>

## Modos de Operação do PWM Rápido
<table style="float:right">
  <tr>
    <td>
     <img src="https://github.com/petrucior/ucontrolador/blob/main/lecture4/midia/ondas.png?raw=true" alt="signal" width="100%" height="100%" style="vertical-align:middle">
   </td>
   <td>
      <ul>
        <li><b>Saída não-invertida</b>: O pino OCnA/B é zerado na igualdade entre o TCNTn e OCRnA/B, e colocado em nível lógico alto (1) no valor mínimo do contador;</li>
        <li><b>Saída invertida</b>: O pino OCnA/B é ativado na igualdade entre o TCNTn e OCRnA/B, e zerado no valor mínimo do contador;</li>
        <li> <math>T<sub>PWM</sub> = (2<sup>x</sup>) * prescaler * T<sub>clk</sub></math> </li>
        <li> <math>f<sub>PWM</sub> = f<sub>clk</sub> / (2<sup>x</sup>) * prescaler </math> </li>
        <li> <math> <b>Prescaler</b> = {1, 8, 64, 256, 1024} </math> </li>
      </ul>
    </td>
  </tr>
</table>

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
    <th colspan="3">Modo PWM rápido</th>
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
    <td>WGM02 = 0: operação normal do pino, OC0A<br>desconectado.<br><br>WGM02 = 1: troca de estado do OC0A na<br>igualdade de comparação.</td>
  </tr>
  <tr>
    <td>1</td>
    <td>0</td>
    <td>OC0A é limpo na igualdade de comparação,<br>OC0A ativo no valor do TC mínimo (modo não<br>invertido).</td>
  </tr>
  <tr>
    <td>1</td>
    <td>1</td>
    <td>OC0A é ativo na igualdade de comparação e<br>limpo no valor do TC mínimo (modo invertido).</td>
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

<!--
- Configurando o modo de operação
![modo](https://github.com/petrucior/ucontrolador/blob/main/lecture3/midia/modos.png?raw=true)

![modos](https://www.arxterra.com/wp-content/uploads/2018/05/arduino_128.png) -->

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

<!-- 
- Definindo prescaler
![prescaler](https://github.com/petrucior/ucontrolador/blob/main/lecture3/midia/registerprescaler.png?raw=true) -->

### Alguns registradores dos contadores
<!-- ![registersdatapath](https://github.com/petrucior/ucontrolador/blob/main/lecture3/midia/regsdatapath.png)-->

**TCNT0 – Timer/Counter 0 Register**
- Registrador de 8 bits onde é realizada a contagem do TC0, pode ser lido ou escrito a qualquer tempo.

**OCR0A – Output Compare 0 Register A**
- Registrador de comparação A de 8 bits, possui o valor que é continuamente comparado com o valor do contador (TCNT0). A igualdade pode ser utilizada
para gerar uma interrupção ou uma forma de onda no pino OC0A.

**OCR0B – Output Compare 0 Register B**
- Registrador de comparação B de 8 bits, possui o valor que é continuamente comparado com o valor do contador (TCNT0). A igualdade pode ser utilizada para
gerar uma interrupção ou uma forma de onda no pino OC0B.

<!-- 
- Alguns registradores do Datapath
![regdatapath](https://github.com/petrucior/ucontrolador/blob/main/lecture4/midia/regdatpath.png?raw=true)
-->

## Pinos capazes de gerar PWM por hardware
![pinout](https://www.usinainfo.com.br/blog/wp-content/uploads/2018/03/Untitled-1.jpg)
