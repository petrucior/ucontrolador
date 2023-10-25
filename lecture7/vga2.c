/**
 * \file vga.c 
 *
 * \brief This file shows an image using vga
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
#include <avr/io.h> // Including library avr
#include <avr/interrupt.h> // Including library interrupt
#include <util/delay.h> // Including library delay
#include <string.h> // Including library for manipulating arrays of chars


// Define os pinos
#define pin_vsync   PB2
#define pin_hsync   PD3

// Coloque todos os pinos de cores na mesma linha da protoboard
#define pin_output  PD2

#define nop asm ("nop \n")

// Largura e altura de impressao
#define SCREEN_W 40
#define SCREEN_H 30

char PXL_DATA [SCREEN_H][SCREEN_W];

int  lineCounter;
char skipLine;
char PXL_OUT;

ISR(TIMER1_OVF_vect){
  lineCounter = 0;
}

ISR(TIMER2_OVF_vect){
    sei();
    __asm__("sleep \n");
}

ISR(TIMER2_COMPB_vect)
{
  register char  columnCounter;
  register char* rowPtr;

  switch (PXL_OUT){
    case 1:
    rowPtr = &(PXL_DATA[(lineCounter - 35)>>4][0]);
    columnCounter = SCREEN_W;

    while(columnCounter--){
      PORTD = (*(rowPtr++)<<PD2);
      nop;
    }
    nop;
    nop;
    nop;
    PORTD = 0;
    break;
  }

  lineCounter++;
  skipLine = !skipLine;
  
  if ( skipLine && (lineCounter >= 35) && (lineCounter < 515) ){
    PXL_OUT = 1;
  }
  else{
    PXL_OUT = 0;
  }
}

int main( void ){
  // Define os pinos como saída
  DDRB |= ( 1 << pin_vsync );
  DDRD |= ( 1 << pin_hsync );
  DDRD |= ( 1 << pin_output );

  // Desabilita o clock do timer0
  TCCR0B = 0;
  
  // Configura o timer 1 com prescaler de 1024, no modo fast PWM
  TCCR1A = _BV(WGM10) | _BV(WGM11) | _BV(COM1B1);
  TCCR1B = _BV(WGM12) | _BV(WGM13) | _BV(CS12) | _BV(CS10);
  OCR1A = 259; // Período de 16,64ms
  OCR1B = 0; // Largura de 64us (2 linhas)
  TIMSK1 = _BV(TOIE1); // Habilita interrupção por estouro
  TIFR1 = _BV(TOV1); // Apagar a flag de overflow

  // Configura o timer 2 com prescaler de 8, no modo fast PWM
  TCCR2A = _BV(WGM20) | _BV(WGM21) | _BV(COM2B1);
  TCCR2B = _BV(WGM22) | _BV(CS21);
  OCR2A = 63; // Período de 32us
  OCR2B = 7; // Largura de 4us (~96 pixels)
  TIMSK2 = _BV(OCIE2B) | _BV(TOIE2); // Habilita interrupção por estouro
  TIFR2 = _BV(OCF2B) | _BV(TOV2); // Apagar flags de overflow

  SMCR = _BV(SE); // Ativando o modo sleep 
  memset(PXL_DATA, 0, sizeof(PXL_DATA)); // Calculando o tamanho para armazenar PXL_DATA
  lineCounter = 0; // Iniciando o contador

  sei(); // Habilita as interrupções


  while(1) {
    unsigned char r, c;
    for (r = 0; r < SCREEN_H; r++) {
      for (c = 0; c < SCREEN_W; c++) {
        PXL_DATA[r][c] = 1;
      }
    }
  }
  return 0;
}
