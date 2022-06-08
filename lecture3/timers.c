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
#define F_CPU 16000000 UL // Defining clock

#include <avr/io.h> // Including library avr
#include <avr/interrupt.h> // Including library interrupt

// Extern interrupt function
ISR( TIMER0_OVF_vect ){
  // 
  PORTB ^= (1 << 5); // Toggle Pin B5
}

int main( void ){

  cli(); // Disable global interrupt

  // Set pin b5 registers as output ( DDRxn --> DDRx )
                      //        7654_3210
  DDRB |= (1 << 5);   // binary xxxx_x1xx
  // Cleaning PB5 and enable pull-ups in all pins don't used  
  PORTB = 0b11011111;

  // Defining normal mode
  TCCR0A = 0b00000000; // TC0 (normal operating)
  TCCR0B = 0b00000001; // TC0 without prescaler. Overflow every 16us = 256/16Mhz
  TIMSK0 = 0b00000001; // Enabling interrupt TC0 
  

  sei(); // Enable global interrupt

  // The program is branched to interrupt at each overflow of TC0
  // Infinity loop
  while ( 1 ){;;}
  
  return 0;
}
