#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

/*
//ejercicio 1: mostrar frecuencia de 500Hz en osciloscopio con 1ms y 5V
void config_timer(void){
  TCCR0A|=(1<<WGM01);
  TCCR0B|=(1<<CS01)|(1<<CS00);
  OCR0A=250;
}

void pausa_1ms(void){
  TCNT0=0;
  while(!(TIFR0&(1<<OCF0A)));
  TIFR0|=(1<<OCF0A);
}

int main(void){
  config_timer();
  DDRB|=(1<<PB0);
  PORTB&=~(1<<PB0);
  while(1){
    PORTB^=0x01;
    pausa_1ms();
  }
}
*/
//ejercicio 2: tarea cancion mario bros
void config_timer(void){
  TCCR0A|=(1<<WGM01);
  TCCR0B|=(1<<CS02);
}

void DO(void){
  OCR0A=118;
  TCNT0=0;
  while(!(TIFR0&(1<<OCF0A)));
  TIFR0|=(1<<OCF0A);
}

void MI(void){
  OCR0A=94;
  TCNT0=0;
  while(!(TIFR0&(1<<OCF0A)));
  TIFR0|=(1<<OCF0A);
}

void SOL(void){
  OCR0A=79;
  TCNT0=0;
  while(!(TIFR0&(1<<OCF0A)));
  TIFR0|=(1<<OCF0A);
}

void SOL_(void){
  OCR0A=159;
  TCNT0=0;
  while(!(TIFR0&(1<<OCF0A)));
  TIFR0|=(1<<OCF0A);
}

int main(void){
  config_timer();
  DDRB|=(1<<PB0);
  PORTB&=~(1<<PB0);
  while(1){
    for(int i=0;i<83;i++){
      PORTB^=0x01;
      MI();
    }
    PORTB&=~(0x01);
    _delay_ms(1);
    for(int i=0;i<83;i++){
      PORTB^=0x01;
      MI();
    }
    PORTB&=~(0x01);
    _delay_ms(150);
    for(int i=0;i<83;i++){
      PORTB^=0x01;
      MI();
    }
    _delay_ms(250);
    for(int i=0;i<65;i++){
      PORTB^=0x01;
      DO();
    }
    PORTB&=~(0x01);
    _delay_ms(1);
    for(int i=0;i<83;i++){
      PORTB^=0x01;
      MI();
    }
    PORTB&=~(0x01);
    _delay_ms(150);
    for(int i=0;i<392;i++){
      PORTB^=0x01;
      SOL();
    }
    PORTB&=~(0x01);
    _delay_ms(1);
    for(int i=0;i<392;i++){
      PORTB^=0x01;
      SOL_();
    }
    PORTB&=~(0x01);
    _delay_ms(1000);
  }
  return 0;
}