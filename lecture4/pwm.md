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
     <img src="https://camo.githubusercontent.com/af981948d8175551de6fa5fd964931c54f266f4a67a33f7a56247428bead7972/687474703a2f2f322e62702e626c6f6773706f742e636f6d2f2d5733577731624c427438672f5566617951766971346e492f41414141414141414346452f5a356f50346d644968304d2f733634302f6176725f74696d6572302e706e67" alt="signal" width="100%" height="100%" style="vertical-align:middle">
   </td>
   <td>
      <ul>
        <li>O TCn conta continuamente de forma crescente;</li>
        <li>A contagem se dá de 0 até $2^{x}-1$ voltando a 0, num ciclo contínuo;</li>
        <li>O valor da contagem é armazenado no registrador TCNTn;</li>
      </ul>
     <img src="https://camo.githubusercontent.com/22816112a3b1c144d471747e54f15c68fb81060fad753ed5a719693f8e452d20/68747470733a2f2f69302e77702e636f6d2f656d62656464732e636f6d2f77702d636f6e74656e742f75706c6f6164732f323031302f31322f3235305f636f756e74735f6e6f726d616c5f6d6f64652e706e67" alt="signal" width="100%" height="100%" style="vertical-align:middle">
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

- Definindo prescaler
![prescaler](https://github.com/petrucior/ucontrolador/blob/main/lecture3/midia/registerprescaler.png?raw=true)

- Alguns registradores do Datapath
![regdatapath](https://github.com/petrucior/ucontrolador/blob/main/lecture4/midia/regdatpath.png?raw=true)

## Pinos capazes de gerar PWM por hardware
![pinout](https://www.usinainfo.com.br/blog/wp-content/uploads/2018/03/Untitled-1.jpg)
