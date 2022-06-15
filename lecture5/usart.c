/**
 * \file usart.c 
 *
 * \brief This file create the usart comunication
 *
 * \author 
 * Petrucio Ricardo Tavares de Medeiros \n
 * Universidade Federal Rural do Semi-Árido \n
 * Departamento de Computacao e Automacao Industrial \n
 * petrucior at gmail (dot) com
 * 
 * \version 0.1
 * \date Jul 2022
 */
#define F_CPU 16000000UL // Defining clock
#define BAUD 9600 // Defining Baud Rate
#define _UBRR F_CPU/16/BAUD-1 // Calculating Baud Rate (normal mode)
#include <avr/io.h> // Including library avr
#include <avr/interrupt.h> // Including library interrupt
#include <util/delay.h> // Including library delay

// Setting USART
void usartInit( unsigned int ubrr ){
  // Adjusting baud rate
  UBRR0H = (unsigned char)(ubrr >> 8);
  UBRR0L = (unsigned char)(ubrr);
  // Enabling transmitter and receiver
  UCSR0B = (1 << RXEN0) | (1 << TXEN0);
  // Adjusting format frame ( data (8 bits) and 2 stops )
  UCSR0C = (1 << USBS0) | (3 << UCSZ00);
}

// Sending frame
void usartSend( unsigned char data ){
  // Waiting for transmission register to clear
  while ( !( UCSR0A & (1 << UDRE0 ) ) );
  UDR0 = data;
}

// Receive frame
unsigned char usartReceive( void ){
  // Waiting for data to be received
  while( !( UCSR0A & (1 << RXC0 ) ) );
  return UDR0;
}

// USART Interrupt
/*
ISR( USART_RX_vect ){
  // Sending the received data
  usartSend( usartReceive() );
}
*/

int main( void ){

  // Setting usart
  usartInit( _UBRR );

  // Enabling interrupt
  //sei();
  
  // Infinity loop
  while ( 1 ){
     
    usartSend('u');
    _delay_ms(200);
    usartSend('s');
    _delay_ms(200);
    usartSend('a');
    _delay_ms(200);
    usartSend('r');
    _delay_ms(200);
    usartSend('t');
    _delay_ms(200);
    usartSend(' ');
    _delay_ms(200);
    
    
    //usartSend( usartReceive() );
  }
  
  return 0;
}
