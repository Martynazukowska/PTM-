#define F_CPU 16000000L // predkosc micropc

#include<avr/io.h>
#include<util/delay.h>
#include <avr/interrupt.h>

#define ZERO 0x3F
#define ONE 0x06
#define TWO 0x5B
#define THREE 0x4F
#define FOUR 0x66
#define FIVE 0x6D
#define SIX 0x7D
#define SEVEN 0x07
#define EIGHT 0x7F
#define NINE 0x6F

int timer;
int stop = 0;
int start = 0;

void init_7_seg()
{
  DDRB = 0x7F;
  PORTB = 0X00;
}
void clear_display()
{
	PORTB = 0X00;
}

void display_number(int no)
{
  switch(no)
  {
	case 0:
		PORTB = ZERO;
		break;
	case 1:
		PORTB = ONE;
		break;
	case 2:
		PORTB = TWO;
		break;
	case 3:
		PORTB = THREE;
		break;
	case 4:
		PORTB = FOUR;
		break;
	case 5:
		PORTB = FIVE;
		break;
	case 6:
		PORTB = SIX;
		break;
	case 7:
		PORTB = SEVEN;
		break;
	case 8:
		PORTB = EIGHT;
		break;
	case 9:
		PORTB = NINE;
		break;
	}
}


int Pomiar(void)
{
	ADCSRA |= (1<<ADSC); // START KONWERSJI
	while(ADCSRA & (1<<ADSC));
	return ADC;
}

ISR(INT0_vect)

{
	stop = 0;
	start = 1;
	
}

ISR(INT1_vect)

{
	stop = 1;
	start = 0;
	PORTA &= ~(1<<PA0);
	
}

ISR(TIMER0_OVF_vect)
{	
	static int counter = 250;
	TCNT0 = 5;
	if(!counter--)
	{
		if(start&&timer)
			timer--;
		counter=250;
		
		if(timer==0&&start==1&&stop==0)
		{
			stop = 1;
			start = 0;
			PORTA |= 1<<PA0;
		}
		
	}	
}


int main()
{
	int a,b,c;
	
	ADMUX |= (1<< REFS0); //ustawienie napiecia ref na napiecie zasilania
	ADMUX |= ((1<< MUX0) | (1<< MUX1) | (1<< MUX2)); //WYBOR KANA�U ADC -> ADC7

	ADCSRA |= (1<<ADEN); //URUCHOMIENIE PRZETWORNIKA ADC
	ADCSRA |= ((1<<ADPS0) | (1<<ADPS1)); // USTAWIENIE PRESKALERA NA 8 
	
	sei(); //SREG
	
	MCUCR |= (1<<ISC01); //zbocze opadaj�ce - wyzwolenie przerwania
	GICR |= (1<<INT0); //aktywacja przerwania
	
	MCUCR |= (1<<ISC11); //zbocze opadaj�ce - wyzwolenie przerwania
	GICR |= (1<<INT1); //aktywacja przerwania
	
	DDRA |= 1 << PA0;
	DDRC |= 0x0F;
	
	TCCR0 |= (1<<CS02);	//preskaler na 256
	TCNT0 = 5;				//warto�� pocz�tkowa licznika na 5 (liczymy o 5 do 255)
	TIMSK |= (1<<TOIE0);	//w��czenie przerwa�	
	
	init_7_seg();

	while(1)
	{
		if(!start)
		{
			timer = Pomiar()/10; 
			if(timer>100)
			{
				timer=100;
			}
		}
		
		a = timer/100; 
		b = (timer-a*100)/10; 
		c = timer % 10; 
		
		PORTC |= 1<<PC3;
		display_number(a);
		_delay_ms(16);
		clear_display();
		PORTC &= ~(1<<PC3);
		
		PORTC |= 1<<PC2;
		display_number(b);
		_delay_ms(16);
		clear_display();
		PORTC &= ~(1<<PC2);
		
		PORTC |= 1<<PC1;
		display_number(c);
		_delay_ms(16);
		clear_display();
		PORTC &= ~(1<<PC1);
	}
	return 0;
	
}
