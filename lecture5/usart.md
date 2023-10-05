## Comunicação: Serial x Paralela
 <table style="float:right">
  <tr>
    <td>
     <b>Serial</b>
      <ul>
        <li>Menor velocidade;</li>
        <li>Menor custo;</li>
        <li>Menos suceptível a ruídos;</li>
        <li>Longas distâncias;</li>
      </ul>
      <b>Paralelo</b>
      <ul>
        <li>Maior velocidade;</li>
        <li>Maior custo;</li>
        <li>Mais suceptível a ruídos;</li>
        <li>Curtas distâncias;</li>
      </ul>
    </td>
    <td>
     <img src="https://www.ccna.network/wp-content/uploads/2021/03/Comunicacao-em-serie.gif" alt="signal" width="100%" height="100%" style="vertical-align:middle">
    </td>
  </tr>
</table> 

## USART (Universal Synchronous and Asynchronous Receiver and Transceiver)
<table style="float:right">
  <tr>
    <td>
     <img src="https://deepbluembedded.com/wp-content/uploads/2020/06/UART-Hardware-Data-Flow-Control.png" alt="signal" width="100%" height="100%" style="vertical-align:middle">
   </td>
   <td>
     <img src="https://deepbluembedded.com/wp-content/uploads/2020/06/UART-Synchronous-Operation.png" alt="signal" width="100%" height="100%" style="vertical-align:middle">
    </td>
  </tr>
</table>

- Full Duplex: Capaz de transmitir e receber simultaneamente

## Formato do pacote USART
<table style="float:right">
  <tr>
     <img src="https://ozgurayik.files.wordpress.com/2020/10/adsiz.png" alt="package" width="100%" height="100%" style="vertical-align:middle">
  </tr>
</table>

## Exemplos
![exemplos](https://github.com/petrucior/ucontrolador/blob/main/lecture5/midia/exemplos.png?raw=true)

## USART no Atmega328p
- Operação full-duplex (registradores independentes de recepção e transmissão)
- Operação síncrona/assíncrona
- Operação síncrona com clock mestre/escravo
- Gerador de taxa de comunicação de alta resolução (Baud Rate Generator)
- Suporta frames seriais com 5, 6, 7, 8 ou 9 bits de dados e 1 ou 2 bits de parada
- Gerador de paridade par/ímpar e confere paridade por hardware
- Detecção de colisão de dados e erros de frames
- Filtro para ruído, incluindo bit de início falso e filtro digital passa baixa
- Três fontes separadas de interrupção (transmissão completa, recepção completa e esvaziamento do registrador de dados)
- Modo de comunicação assíncrono com velocidade duplicável
- Pode ser utilizada como interface SPI mestre

## Taxa de Transmissão
Baud Rate: A taxa de transmissão deve ser a mesma no transmissor e no receptor
![taxa](https://aws1.discourse-cdn.com/arduino/optimized/4X/1/0/e/10ead4311d296577cd162b9498c047df7574364f_2_690x273.png)

## Diagrama de Blocos
![diagrama](https://nikharris.com/content/images/2015/08/Screenshot-from-2015-08-08-15-57-18.png)

## Registradores
- Registrador que recebe/envia os dados
![dados](https://github.com/petrucior/ucontrolador/blob/main/lecture5/midia/regdata.png?raw=true)

- Registrador de flags que permite compreender como está a transmissão
![controle](https://github.com/petrucior/ucontrolador/blob/main/lecture5/midia/regcontrol.png?raw=true)

- Registrador que define as interrupções
![interrupcoes](https://github.com/petrucior/ucontrolador/blob/main/lecture5/midia/reginterrupt.png?raw=true)

- Configurando o modo
![modo](https://github.com/petrucior/ucontrolador/blob/main/lecture5/midia/regmodo.png?raw=true)

![modo2](https://github.com/petrucior/ucontrolador/blob/main/lecture5/midia/regmodo2.png?raw=true)

- Definindo a taxa de transmissão
![taxa](https://github.com/petrucior/ucontrolador/blob/main/lecture5/midia/taxatransmissao.png?raw=true)

## Pinos Rx, Tx, XCK
![pinout](https://camo.githubusercontent.com/4a9abc735ac471ba63035f24f465c177ac98fc25822f5d0076df58a096f8c53c/68747470733a2f2f63646e2e73686f706966792e636f6d2f732f66696c65732f312f303435322f323536342f303038372f66696c65732f50696e6f75745f6f665f41524455494e4f5f426f6172645f616e645f41544d65676133323850555f4b6f6265652e706e673f763d31363239363438343338)
