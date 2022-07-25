#include <avr/io.h>
#include <util/delay.h>

#define INIT_LED1 	DDRA |= (1<<PA0)  //output - wyjœcie bo nim sterujemy (DDRx gdzie x to nazwa postu)
#define LED_ON1 		PORTA |= (1<<PA0)
#define LED_OFF1 	PORTA &= ~(1<<PA0)

#define INIT_SW1  	DDRB &= ~(1<<PB0) // nie ma rezystora wiec pull-up
#define PULLUP_SW1 	PORTB |= (1<<PB0)

#define INIT_LED2 	DDRA |= (1<<PA1)  //output - wyjœcie bo nim sterujemy (DDRx gdzie x to nazwa postu)
#define LED_ON2 		PORTA |= (1<<PA1)
#define LED_OFF2 	PORTA &= ~(1<<PA1)

#define INIT_SW2  	DDRB &= ~(1<<PB1) // nie ma rezystora wiec pull-up
#define PULLUP_SW2 	PORTB |= (1<<PB1)

#define INIT_LED3 	DDRA |= (1<<PA2)  //output - wyjœcie bo nim sterujemy (DDRx gdzie x to nazwa postu)
#define LED_ON3 		PORTA |= (1<<PA2)
#define LED_OFF3 	PORTA &= ~(1<<PA2)

#define INIT_SW3  	DDRB &= ~(1<<PB2) // nie ma rezystora wiec pull-up
#define PULLUP_SW3 	PORTB |= (1<<PB2)

#define INIT_LED4 	DDRA |= (1<<PA3)  //output - wyjœcie bo nim sterujemy (DDRx gdzie x to nazwa postu)
#define LED_ON4 		PORTA |= (1<<PA3)
#define LED_OFF4 	PORTA &= ~(1<<PA3)

#define INIT_SW4  	DDRB &= ~(1<<PB3) // nie ma rezystora wiec pull-up
#define PULLUP_SW4 	PORTB |= (1<<PB3)

#define INIT_LED5 	DDRA |= (1<<PA4)  //output - wyjœcie bo nim sterujemy (DDRx gdzie x to nazwa postu)
#define LED_ON5 		PORTA |= (1<<PA4)
#define LED_OFF5 	PORTA &= ~(1<<PA4)

#define INIT_SW5  	DDRB &= ~(1<<PB4) // nie ma rezystora wiec pull-up
#define PULLUP_SW5 	PORTB |= (1<<PB4)

#define INIT_LED6 	DDRA |= (1<<PA5)  //output - wyjœcie bo nim sterujemy (DDRx gdzie x to nazwa postu)
#define LED_ON6 		PORTA |= (1<<PA5)
#define LED_OFF6 	PORTA &= ~(1<<PA5)

#define INIT_SW6  	DDRB &= ~(1<<PB5) // nie ma rezystora wiec pull-up
#define PULLUP_SW6 	PORTB |= (1<<PB5)

#define INIT_LED7 	DDRA |= (1<<PA6)  //output - wyjœcie bo nim sterujemy (DDRx gdzie x to nazwa postu)
#define LED_ON7 		PORTA |= (1<<PA6)
#define LED_OFF7 	PORTA &= ~(1<<PA6)

#define INIT_SW7  	DDRB &= ~(1<<PB6) // nie ma rezystora wiec pull-up
#define PULLUP_SW7 	PORTB |= (1<<PB6)

#define INIT_LED8 	DDRA |= (1<<PA7)  //output - wyjœcie bo nim sterujemy (DDRx gdzie x to nazwa postu)
#define LED_ON8 		PORTA |= (1<<PA7)
#define LED_OFF8 	PORTA &= ~(1<<PA7)

#define INIT_SW8  	DDRB &= ~(1<<PB7) // nie ma rezystora wiec pull-up
#define PULLUP_SW8 	PORTB |= (1<<PB7)

#define INIT_SW9  	DDRD &= ~(1<<PD0) // nie ma rezystora wiec pull-up
#define PULLUP_SW9 	PORTD |= (1<<PD0)

#define INIT_SW10  	DDRD &= ~(1<<PD1) // nie ma rezystora wiec pull-up
#define PULLUP_SW10 	PORTD |= (1<<PD1)


int main(void)
{
	INIT_LED1;
	INIT_LED2;
	INIT_LED3;
	INIT_LED4;
	INIT_LED5;
	INIT_LED6;
	INIT_LED7;
	INIT_LED8;
	
	INIT_SW1;
	INIT_SW2;
	INIT_SW3;
	INIT_SW4;
	INIT_SW5;
	INIT_SW6;
	INIT_SW7;
	INIT_SW8;
	INIT_SW9;
	INIT_SW10;

	PULLUP_SW1;
	PULLUP_SW2;
	PULLUP_SW3;
	PULLUP_SW4;
	PULLUP_SW5;
	PULLUP_SW6;
	PULLUP_SW7;
	PULLUP_SW8;
	PULLUP_SW9;
	PULLUP_SW10;
	
	
	while(1)
	{
		while(!(PINB & (1<<PB0))) //
		{	
			LED_ON1;
			LED_ON2;
			LED_ON3;
			LED_ON4;
			LED_ON5;
			LED_ON6;
			
			
		}
		LED_OFF1;
		LED_OFF2;
		LED_OFF3;
		LED_OFF4;
		LED_OFF5;
		LED_OFF6;
	
		while(!(PINB & (1<<PB1))) //
		{
			LED_ON2;
			LED_ON3;
		}
		LED_OFF2;
		LED_OFF3;
		
		while(!(PINB & (1<<PB2))) //
		{
			LED_ON1;
			LED_ON2;
			LED_ON4;
			LED_ON5;
			LED_ON7;
			
		}
		LED_OFF1;
		LED_OFF2;
		LED_OFF4;
		LED_OFF5;
		LED_OFF7;

		while(!(PINB & (1<<PB3))) //
		{
			LED_ON1;
			LED_ON2;
			LED_ON3;
			LED_ON4;
			LED_ON7;
			
		}
		LED_OFF1;
		LED_OFF2;
		LED_OFF3;
		LED_OFF4;
		LED_OFF7;
		
		while(!(PINB & (1<<PB4))) //
		{	
			LED_ON2;
			LED_ON3;
			LED_ON6;
			LED_ON7;
			
			
		}
		LED_OFF2;
		LED_OFF3;
		LED_OFF6;
		LED_OFF7;
		
		while(!(PINB & (1<<PB5))) //
		{	
			LED_ON1;
			LED_ON3;
			LED_ON4;
			LED_ON6;
			LED_ON7;
			
			
		}
		LED_OFF1;
		LED_OFF3;
		LED_OFF4;
		LED_OFF6;
		LED_OFF7;
		
		while(!(PINB & (1<<PB6))) //
		{	
			LED_ON1;
			LED_ON3;
			LED_ON4;
			LED_ON5;
			LED_ON6;
			LED_ON7;
			
			
		}
		
		LED_OFF1;
		LED_OFF3;
		LED_OFF4;
		LED_OFF5;
		LED_OFF6;
		LED_OFF7;
		
		while(!(PINB & (1<<PB7))) //
		{	
			LED_ON1;
			LED_ON2;
			LED_ON3;
			
			
		}
		LED_OFF1;
		LED_OFF2;
		LED_OFF3;
		
		while(!(PIND & (1<<PD0))) //
		{	
			LED_ON1;
			LED_ON2;
			LED_ON3;
			LED_ON4;
			LED_ON5;
			LED_ON6;
			LED_ON7;
			
			
		}
		LED_OFF1;
		LED_OFF2;
		LED_OFF3;
		LED_OFF4;
		LED_OFF5;
		LED_OFF6;
		LED_OFF7;
		while(!(PIND & (1<<PD1))) //
		{	
			LED_ON1;
			LED_ON2;
			LED_ON3;
			LED_ON4;
			LED_ON6;
			LED_ON7;
			
			
		}
		LED_OFF1;
		LED_OFF2;
		LED_OFF3;
		LED_OFF4;
		LED_OFF6;
		LED_OFF7;
	}
	return 0;

}