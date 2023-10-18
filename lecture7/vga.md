## VGA (Video Graphics Array)

 <table style="float:right">
  <tr>
    <td>
      <ul>
        <li>Padrão de vídeo;</li>
        <li>Comunicação entre PC e monitor</li>
        <li>Padrão VGA é de 640×480</li>
       <li>Modos de cores: 16 ou 256 cores</li>
      </ul> 
    </td>
    <td>
     <figure>
     <img src="https://i.gifer.com/origin/51/5129a4019d06ed1eeb0600b9f0c9ffd4_w200.gif" alt="signal" width="100%" height="100%" style="vertical-align:middle">
      </figure>
    </td>
    <td>
     <figure>
     <img src="https://ae01.alicdn.com/kf/S6eb42a164125461a8f3ef9fe2702152eW/DB15-Fio-De-Solda-Tipo-Adaptador-VGA-15-Furo-Pin-3-Linhas-Macho-e-F-mea.jpg" alt="signal" width="50%" height="50%" style="vertical-align:middle">
      </figure>
    </td>
  </tr>
</table> 

## Funcionamento
![funcionamento](https://embarcados.com.br/wp-content/uploads/2015/10/controlador-vga-varredura-quadro-vga.png)

## Sincronismo vertical
<table style="float:right">
  <tr>
    <td>
     <img src="https://mundoprojetado.com.br/wp-content/uploads/2019/10/VGA-sincronismo-vertical.png" alt="signal" width="100%" height="100%" style="vertical-align:middle">
   </td>
   <td>
      <ul>
        <li>Taxa de atualização de monitor: 60Hz;</li>
        <li>Atualização de 16,67ms (1/60)</li>
      </ul> 
    </td>
  </tr>
</table>

## Sincronismo horizontal
<table style="float:right">
  <tr>
    <td>
     <img src="https://mundoprojetado.com.br/wp-content/uploads/2019/10/VGA-sincronismo-horizontal.png" alt="signal" width="100%" height="100%" style="vertical-align:middle">
   </td>
   <td>
      <ul>
        <li>Deve repetir a cada linha;</li>
        <li>Deve possuir uma largura equivalente ao tempo para “escrever” 96 pixels</li>
      </ul> 
    </td>
  </tr>
</table>

## Estrutura do Vídeo
<table style="float:right">
  <tr>
   <td>
      <ul>
        <li>Back porch e Front porch serviam para atrasar o vídeo em monitores antigos;</li>
        <li>Informação enviada 800×525 (colunas x linhas);</li>
        <li>Tempo de linha: 16,67 ms / 525 = 31,75us;</li>
        <li>Tempo de cada pixel: 16,67 ms / (800 x 525) = 39,68ns;</li>
        <li>Exige um clock mínimo de 25,2MHz;</li>
      </ul> 
    </td>
    <td>
     <img src="https://mundoprojetado.com.br/wp-content/uploads/2019/10/VGA-Diagrama-de-pixelss-1024x697.png" alt="signal" width="50%" height="50%" style="vertical-align:middle">
   </td>
  </tr>
</table>


## VGA Pinout
<table style="float:right">
  <tr>
    <td>
     <img src="https://www.clubedohardware.com.br/uploads/attachments/monthly_03_2014/post-684451-0-48342800-1395974448_thumb.gif" alt="signal" width="100%" height="100%" style="vertical-align:middle">
   </td>
  </tr>
</table>

## Canais de Cores
Os 3 primeiros pinos servem para definir a cor de um pixel, sendo o primeiro responsável pela cor vermelha, o segundo pela verde e o terceiro pela azul (RGB). Estes devem receber tensões de 0 a 0,7V. E, a cor reproduzida no pixel será conforme:

- A intensidade da tensão, nos pinos.
Ex: 0.7V intensidade máxima da cor e 0V intensidade mínima.

- Somatória das cores nos três canais.

**Exemplo:** os 3 pinos em 0.7V produzem pixels brancos, pois a somatória das cores vermelho, verde e azul produz a cor branca. E, se os 3 estiverem em 0V, a cor resultante será preto (ausência das três cores). As demais combinações formam outras cores (amarelo, laranja, cinza etc).

