## EEPROM (Electrically-Erasable Programmable Read-Only Memory)

 <table style="float:right">
  <tr>
    <td>
      <ul>
        <li>Memória não volátil;</li>
        <li>Escrita e Leitura</li>
        <li>Número limitado de operações de escrita;</li>
        <li>Normalmente usado para armazenar configurações</li>
      </ul> 
    </td>
    <td>
     <figure>
     <img src="https://http2.mlstatic.com/D_NQ_NP_779811-MLB43560663837_092020-O.webp" alt="signal" width="100%" height="100%" style="vertical-align:middle">
     <figcaption>Chip EEPROM I2C - 256 kbits.</figcaption>
      </figure>
    </td>
  </tr>
</table> 

## Periférico EEPROM no Atmega328p
<table style="float:right">
  <tr>
    <td>
     <img src="https://www.arnabkumardas.com/blog/wp-content/uploads/2021/04/avrbus.png" alt="signal" width="100%" height="100%" style="vertical-align:middle">
   </td>
   <td>
      <ul>
        <li>Armazenamento de 1Kbyte;</li>
        <li>Escrita/Leitura de bytes individuais;</li>
        <li>100000 ciclos de escrita;</li>
        <li>Garantir a tensão mínima de escrita para evitar corrupção dos dados</li>
      </ul>
    </td>
  </tr>
</table>


## Registradores
- Registrador de endereços da memória EEPROM - varia linearmente entre $[0,1023]$
![enderecos](https://github.com/petrucior/ucontrolador/blob/main/lecture5/midia/dados.png?raw=true)

- Registrador de dados: contém o dado a ser escrito/lido em uma operação de **write**/**read**. 
![prescaler](https://github.com/petrucior/ucontrolador/blob/main/lecture5/midia/enderecos.png?raw=true)

- Registrador de controle de como acontece a escrita, interrupção e flags para habilitar/desabilitar a escrita/leitura.
![controle](https://github.com/petrucior/ucontrolador/blob/main/lecture5/midia/controle.png?raw=true)

## [EEPROM Library](https://www.nongnu.org/avr-libc/user-manual/group__avr__eeprom.html)

```c
void eepromWrite( unsigned int uiAddress, unsigned char ucData ){
 /* Wait for completion of previous write */
 while (EECR & (1 << EEPE));
 /* Set up address and Data Registers */
 EEAR = uiAddress;
 EEDR = ucData;
 /* Write logical one to EEMPE - Master Write Enable */
 EECR |= (1 << EEMPE);
 /* Start eeprom write by setting EEPE - Write Enable */
 EECR |= (1 << EEPE);
}
```

```c
unsigned char eepromRead( unsigned int uiAddress ){
 /* Wait for completion of previous write */
 while (EECR & (1 << EEPE));
 /* Set up address register */
 EEAR = uiAddress;
 /* Start eeprom read by writing EERE */
 EECR |= (1 << EERE);
 /* Return data from Data Register */
 return EEDR;
}
```
