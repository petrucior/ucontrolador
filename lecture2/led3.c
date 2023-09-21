/**
 * \file semaphore.c 
 *
 * \brief This file configures and turn on led according with interruption PCINT2
 *
 * \author 
 * Petrucio Ricardo Tavares de Medeiros \n
 * Universidade Federal Rural do Semi-Árido \n
 * Departamento de Computacao e Automacao Industrial \n
 * petrucior at gmail (dot) com
 * 
 * \version 0.1
 * \date Set 2023
 */
#define F_CPU 16000000UL // Defining clock

#include <avr/io.h> // Including library avr
#include <avr/interrupt.h> // Including library interrupt
#include <util/delay.h>

ISR( PCINT2_vect ){
  if ( (PIND & (1 << 2)) == (1 << 2) ){
    PORTC ^= (1 << PORTC2);
    _delay_ms(10);
  }
}

int main( void ){

  cli(); // desabilito as interrupcoes
  
  DDRC |= (1 << 2); // configuro a saida PC2
  DDRD &= ~(1 << 2); // configuro a entrada PD2
  PORTD |= (1 << 2); // Pull-up

  PCICR |= (1 << PCIE2); // habilitando as interrupcoes na porta D
  PCMSK2 |= (1 << PCINT18); // habilitando a interrupção na porta PD2

  sei();
  
  while ( 1 ){  }

  return 0;
}
