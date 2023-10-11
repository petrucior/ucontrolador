/**
 * \file adc.c 
 *
 * \brief This file converts analog signals to digital
 *
 * \author 
 * Petrucio Ricardo Tavares de Medeiros \n
 * Universidade Federal Rural do Semi-Árido \n
 * Departamento de Computacao e Automacao Industrial \n
 * petrucior at gmail (dot) com
 * 
 * \version 0.1
 * \date Oct 2023
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
  // Enabling interrupt, transmitter and receiver
  UCSR0B = (1 << RXCIE0) | (1 << RXEN0) | (1 << TXEN0);
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

// Valor recebido do adc
uint16_t adc_value = 0;

ISR(ADC_vect){
  adc_value = ADC;
  usartSend( adc_value );
  _delay_ms(1000);
}

int main(){

  DDRC = 0x00; // Porta C como entrada -> Use o PC0
  PORTC = 0xFE; // Desabilita o pullup do PC0
  // Configura o ADC
  // REFS1 & REFS2 ! Setup
  //    0      0     aref
  //    0      1     avcc
  //    1      1     1.1 V
  ADMUX = 0b11000000; // Tensao interna de 1.1V, canal 0
  ADCSRA = 0b11101111; // Habilitando o AD, a interrupcao, modo de conversao continua, prescaler de 128
  ADCSRB = 0x00; // Conversao continua
  DIDR0 = 0b11111110; // Habilitar pino PC0 como entrada do ADC0

  // Setting usart
  usartInit( _UBRR );

  sei();

  while( 1 ){ ;; }

  return 0;
}
