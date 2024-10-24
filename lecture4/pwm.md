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

## Registradores
- Configurando o modo de operação
![modo](https://github.com/petrucior/ucontrolador/blob/main/lecture3/midia/modos.png?raw=true)

![modos](https://www.arxterra.com/wp-content/uploads/2018/05/arduino_128.png)

- Definindo prescaler
![prescaler](https://github.com/petrucior/ucontrolador/blob/main/lecture3/midia/registerprescaler.png?raw=true)

- Alguns registradores do Datapath
![regdatapath](https://github.com/petrucior/ucontrolador/blob/main/lecture4/midia/regdatpath.png?raw=true)

## Pinos capazes de gerar PWM por hardware
![pinout](https://www.usinainfo.com.br/blog/wp-content/uploads/2018/03/Untitled-1.jpg)
