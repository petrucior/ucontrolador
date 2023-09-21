/**
 * \file led.c 
 *
 * \brief This file configures and turn on led according to the press of a button using interrupt.
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
#include <avr/interrupt.h> // Including library interrupt

// Extern interrupt function
ISR( INT0_vect ){
  PORTC ^= (1 << 2); // Toggle Pin C2
}

int main( void ){

  cli(); // Disable global interrupt

  // Set pin c2 registers as output ( DDRxn --> DDRx )
                      //        7654_3210
  DDRC |= (1 << 2);   // binary xxxx_x1xx
  // Set pin d2 register as input ( DDRxn --> DDRx )
  DDRD &= ~(1 << 2);  // binary xxxx_x0xx
  PORTD |= (1 << 2);  // Pull-up on Pin D2

  // Set interrupt
  EICRA |= (1 << 1); // external interrupt int0 - falling edge
  EIMSK |= (1 << 0); // Enable external interrupt INT0

  sei(); // Enable global interrupt

  // Infinity loop
  while ( 1 ){;;}
  return 0;
}
