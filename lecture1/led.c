/**
 * \file led.c 
 *
 * \brief This file configures and turn on led.
 *
 * \author 
 * Petrucio Ricardo Tavares de Medeiros \n
 * Universidade Federal Rural do Semi-Árido \n
 * Departamento de Computacao e Automacao Industrial \n
 * petrucior at gmail (dot) com
 * 
 * \version 0.1
 * \date Jun 2022
 */
#define F_CPU 16000000 UL // Defining clock

#include <avr/io.h> // Including library avr

int main( void ){

  // Set pin registers as output ( DDRxn --> DDRx )
                  //        7654_3210
  DDRB |= 0x3F;   // binary xx11_1111
  DDRC |= 0x3F;   // binary xx11_1111
  DDRD |= 0xFF;   // binary 1111_1111

  // Set outputs High ( PORTxn --> PORTx )
  PORTB |= 0x3F;  // binary xx11_1111
  PORTC |= 0x3F;  // binary xx11_1111
  PORTD |= 0xFF;  // binary 1111_1111

  // Infinity loop
  while ( 1 ){;;}
  return 0;
}
