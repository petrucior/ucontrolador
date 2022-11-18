/**
 * \file pwm.c 
 *
 * \brief This file generates Pulse Width Modulation (PWM) using fast mode (14) to control servo motor
 *
 * \author 
 * Petrucio Ricardo Tavares de Medeiros \n
 * Universidade Federal Rural do Semi-Árido \n
 * Departamento de Computacao e Automacao Industrial \n
 * petrucior at gmail (dot) com
 * 
 * \version 0.1
 * \date nov 2022
 */
#define F_CPU 16000000UL // Defining clock

#include <avr/io.h> // Including library avr
#include <util/delay.h> // Including library delay

int main( void ){
  
  // Set pin PB1 (OC1A) and PB2 (OC1B) registers as output ( DDRxn --> DDRx ) 
                          //        7654_3210
  DDRD |= (1 << 6);       // binary xxxx_x11x

  // TIMER TC1
  // Enabling Fast PWM mode using ICR1, prescaler 8 and F_PWM = 50hz
  // TOP = (F_CPU / (Prescaler * F_PWM)) - 1 = (16MHz / (8 * 50Hz)) - 1 = 39999
  ICR1 = 39999; // Setting T = 20 ms
  TCCR1A = 0b10100010; // PWM not inverted in OC1A and OC1B using ICR1 (TOP) 
  TCCR1B = 0b00011010; // Prescaler = 8

  OCR1A = 4000; // PWM active duty cycle control (OC1A - PB1) --> 2 ms (10%)  
  OCR1B = 2000; // PWM active duty cycle control (OC1B - PB2) --> 1 ms (5%)
  
  // Infinity loop
  while ( 1 ){
    
    // OCR0A += 10; // Increasing +10 until overflow and to start again
    // _delay_ms( 50 ); // waiting 50ms
    
  }
  
  return 0;
}
