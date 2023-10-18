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
#define BAUD 9600 // Defining Baud Rate
#define _UBRR F_CPU/16/BAUD-1 // Calculating Baud Rate (normal mode)
#include <avr/io.h> // Including library avr
#include <avr/interrupt.h> // Including library interrupt
#include <util/delay.h> // Including library delay

// Define os pinos
#define pin_vsync   PB2
#define pin_hsync   PD3
#define pin_red     PD5
#define pin_green   PD6
#define pin_blue    PD7

// Comandos para facilitar a manipulação dos registradores
#define SET_BIT(PORT, PIN) PORT |= _BV(PIN)
#define CLR_BIT(PORT, PIN) PORT &= ~(_BV(PIN))

#define NOP asm ("nop\n\t")

// Parametros do padrão VGA
#define VGA_ALTURA              480
#define VGA_BACK_PORCH_VERTICAL 35


uint8_t video_exibido = 0;
volatile char back_porch_vertical_restante;
volatile int linha_atual;

// Delay com a instrução de não operação do microcontrolador                                                                                                                                                
void delay_nop(uint16_t tempo){
  for(uint16_t i=0; i<tempo; i++){
    NOP;
  }
}

int main( void ){
  // Define os pinos como saída
  SET_BIT(DDRB, pin_vsync);
  SET_BIT(DDRD, pin_hsync);
  SET_BIT(DDRD, pin_red);
  SET_BIT(DDRD, pin_green);
  SET_BIT(DDRD, pin_blue);

  // Desabilita o clock do timer0
  TCCR0B = 0;

  // Configura o timer 1 com prescaler de 1024, no modo fast PWM
  TCCR1A = _BV(WGM10) | _BV(WGM11) | _BV(COM1B1);
  TCCR1B = _BV(WGM12) | _BV(WGM13) | _BV(CS12) | _BV(CS10);
  OCR1A = 259; // Período de 16,64ms
  OCR1B = 0; // Largura de 64us (2 linhas)
  TIMSK1 = _BV(TOIE1); // Habilita interrupção por estouro

  // Configura o timer 2 com prescaler de 8, no modo fast PWM
  TCCR2A = _BV(WGM20) | _BV(WGM21) | _BV(COM2B1);
  TCCR2B = _BV(WGM22) | _BV(CS21);
  OCR2A = 63; // Período de 32us
  OCR2B = 7; // Largura de 4us (~96 pixels)
  TIMSK2 = _BV(TOIE2); // Habilita interrupção por estouro

  sei(); // Habilita as interrupções


  while(1) {
    // Se está na região do vídeo exibido
    if (video_exibido) {
      video_exibido = 0;
      
      // Desenha a imagem aqui
      if (linha_atual < VGA_ALTURA/3){
	SET_BIT(PORTD, pin_green);
      }
      else if (linha_atual < 2*VGA_ALTURA/3){
	SET_BIT(PORTD, pin_red);
      }
      else {
	SET_BIT(PORTD, pin_blue);
      }
      delay_nop(80); // Valor empirico para atrasar até o final da linha
    }
    // Após desenhar, limpa os canais de cores
    CLR_BIT(PORTD, pin_red);
    CLR_BIT(PORTD, pin_green);
    CLR_BIT(PORTD, pin_blue);
  }
  return 0;
}


// Interrupção que ocorre a cada inicio de tela
ISR(TIMER1_OVF_vect){
  // Reseta a posição da linha e do back porch vertical restante
  linha_atual = 0;
  back_porch_vertical_restante = VGA_BACK_PORCH_VERTICAL;
}

// Interrupção que ocorre a cada inicio de linha
ISR(TIMER2_OVF_vect){
  // Subtrai do back porch restante se ele for maior que 0
  if (back_porch_vertical_restante > 0) {
    back_porch_vertical_restante--;
  }
  // Caso contrário, soma a linha atual
  else{
    linha_atual++;
    // Se a linha atual estiver antes do front porch vertical, seta o video_exibido
    if (linha_atual < VGA_ALTURA){
      video_exibido = 1;
    }
  }
}
 
