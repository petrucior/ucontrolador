/**
 * \file pwm.c 
 *
 * \brief This file generates Pulse Width Modulation (PWM) using fast mode
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
  
  // Set pin PD6 and PD5 registers as output ( DDRxn --> DDRx )
                                     //        7654_3210
  DDRD |= (1 << 6) | (1 << 5);       // binary x11x_xxxx
  
  // Enabling Fast PWM mode, TOP = 0xFF, and OC0A e OC0B
  TCCR0A = 0b10100011; // PWM not inverted in OC0A and OC0B 
  TCCR0B = 0b00000011; // Turn on TC0, prescaler = 64, fpwm = fosc / (2^{x} * prescaler) = 16Mhz / ( 256 * 64 ) = 976 Hz
  OCR0A = 200;         // PWM active cycle control (OC0A - PD6) --> duty cycle = 200/256 = 78.13%
  //OCR0B = 50;          // PWM active cycle control (OC0B - PD5) --> duty cycle = 50/256 = 19.53%
  
  // Infinity loop
  while ( 1 ){;;}
  
  return 0;
}
