/**
 * \file led.c 
 *
 * \brief This file configures and turn on led according to the press of a button without interrupt..
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
#define F_CPU 16000000UL // Defining clock

#include <avr/io.h> // Including library avr
#include <util/delay.h> // Including library delay

int main( void ){
  
  // Set pin c2 registers as output ( DDRxn --> DDRx )
                      //        7654_3210
  DDRC |= (1 << 2);   // binary xxxx_x1xx
  // Set pin d2 register as input ( DDRxn --> DDRx )
  DDRD &= ~(1 << 2);  // binary xxxx_x0xx
  PORTD |= (1 << 2);  // Pull-up on Pin D2

  // Infinity loop
  while ( 1 ){
    if (! ( PIND & (1 << 2)) ){
      PORTC |= (1 << 2);
    }
    else {
      PORTC &= ~(1 << 2);
    }
    _delay_ms(100); // 100 ms
  }
  
  return 0;
}
