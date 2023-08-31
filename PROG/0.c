/*******************************************************
This program was created by the
CodeWizardAVR V3.12 Advanced
Automatic Program Generator
© Copyright 1998-2014 Pavel Haiduc, HP InfoTech s.r.l.
http://www.hpinfotech.com

Project : rotating led display
Version : 1
Date    : 2016/04/05
Author  : Esmaeill M
Company : IOElectro
Comments: https://github.com/ioelectro


Chip type               : ATmega32
Program type            : Application
AVR Core Clock frequency: 8.000000 MHz
Memory model            : Small
External RAM size       : 0
Data Stack size         : 512
*******************************************************/

#include <mega32.h>
#include <stdio.h>
#include <delay.h>

int i=0;

int ebna[]={
0,
2044,
2044,
1092,
1092,
1092,
1028,
0,
0,
2044,
2044,
1092,
1092,
2044,
952,
0,
0,
2044,
2044,
120,
224,
896,
2044,
2044,
0,
1536,
1984,
496,
316,
316,
496,
1984,
1536,
0,
0,
0,
0,
0,
768,
1952,
1184,
1184,
2016,
1984,
0,
2016,
2016,
96,
32,
2016,
1984,
0,
960,
2016,
1056,
1056,
2044,
2044,
0,
0,
0,
0,
0,
4,
4,
2044 ,
2044,
4,
4,
0,
1536,
1984,
496,
316,
316,
496 ,
1984 ,
1536 ,
0  ,
2044,
2044,
68  ,
68  ,
68  ,
2044,
1976 ,
0   ,
1536  ,
1984 ,
496  ,
316  ,
316 ,
496  ,
1984,
1536 ,
0   ,
568 ,
1660 ,
1092 ,
1092,
1996 ,
904 ,
0   ,
0   ,
2044,
2044 ,
64   ,
64   ,
64   ,
2044  ,
2044  ,
0    ,
0    ,
2044 ,
2044 ,
1092 ,
1092 ,
1092 ,
1028 ,
0    ,
0   ,
0

};



// Analog Comparator interrupt service routine
interrupt [ANA_COMP] void ana_comp_isr(void)
{
// Place your code here
i=122;

}

void main(void)
{
// Declare your local variables here

// Input/Output Ports initialization
// Port A initialization
// Function: Bit7=Out Bit6=Out Bit5=Out Bit4=Out Bit3=Out Bit2=Out Bit1=Out Bit0=Out 
DDRA=(1<<DDA7) | (1<<DDA6) | (1<<DDA5) | (1<<DDA4) | (1<<DDA3) | (1<<DDA2) | (1<<DDA1) | (1<<DDA0);
// State: Bit7=0 Bit6=0 Bit5=0 Bit4=0 Bit3=0 Bit2=0 Bit1=0 Bit0=0 
PORTA=(0<<PORTA7) | (0<<PORTA6) | (0<<PORTA5) | (0<<PORTA4) | (0<<PORTA3) | (0<<PORTA2) | (0<<PORTA1) | (0<<PORTA0);

// Port B initialization
// Function: Bit7=In Bit6=In Bit5=In Bit4=In Bit3=In Bit2=In Bit1=In Bit0=In 
DDRB=(0<<DDB7) | (0<<DDB6) | (0<<DDB5) | (0<<DDB4) | (0<<DDB3) | (0<<DDB2) | (0<<DDB1) | (0<<DDB0);
// State: Bit7=T Bit6=T Bit5=T Bit4=T Bit3=T Bit2=T Bit1=T Bit0=T 
PORTB=(0<<PORTB7) | (0<<PORTB6) | (0<<PORTB5) | (0<<PORTB4) | (0<<PORTB3) | (0<<PORTB2) | (0<<PORTB1) | (0<<PORTB0);

// Port C initialization
// Function: Bit7=Out Bit6=Out Bit5=Out Bit4=Out Bit3=Out Bit2=Out Bit1=Out Bit0=Out 
DDRC=(1<<DDC7) | (1<<DDC6) | (1<<DDC5) | (1<<DDC4) | (1<<DDC3) | (1<<DDC2) | (1<<DDC1) | (1<<DDC0);
// State: Bit7=0 Bit6=0 Bit5=0 Bit4=0 Bit3=0 Bit2=0 Bit1=0 Bit0=0 
PORTC=(0<<PORTC7) | (0<<PORTC6) | (0<<PORTC5) | (0<<PORTC4) | (0<<PORTC3) | (0<<PORTC2) | (0<<PORTC1) | (0<<PORTC0);

// Port D initialization
// Function: Bit7=In Bit6=In Bit5=In Bit4=In Bit3=In Bit2=In Bit1=In Bit0=In 
DDRD=(0<<DDD7) | (0<<DDD6) | (0<<DDD5) | (0<<DDD4) | (0<<DDD3) | (0<<DDD2) | (0<<DDD1) | (0<<DDD0);
// State: Bit7=T Bit6=T Bit5=T Bit4=T Bit3=T Bit2=T Bit1=T Bit0=T 
PORTD=(0<<PORTD7) | (0<<PORTD6) | (0<<PORTD5) | (0<<PORTD4) | (0<<PORTD3) | (0<<PORTD2) | (0<<PORTD1) | (0<<PORTD0);

// USART initialization
// Communication Parameters: 8 Data, 1 Stop, No Parity
// USART Receiver: On
// USART Transmitter: On
// USART Mode: Asynchronous
// USART Baud Rate: 9600
UCSRA=(0<<RXC) | (0<<TXC) | (0<<UDRE) | (0<<FE) | (0<<DOR) | (0<<UPE) | (0<<U2X) | (0<<MPCM);
UCSRB=(0<<RXCIE) | (0<<TXCIE) | (0<<UDRIE) | (1<<RXEN) | (1<<TXEN) | (0<<UCSZ2) | (0<<RXB8) | (0<<TXB8);
UCSRC=(1<<URSEL) | (0<<UMSEL) | (0<<UPM1) | (0<<UPM0) | (0<<USBS) | (1<<UCSZ1) | (1<<UCSZ0) | (0<<UCPOL);
UBRRH=0x00;
UBRRL=0x33;

// Analog Comparator initialization
// Analog Comparator: On
// The Analog Comparator's positive input is
// connected to the AIN0 pin
// The Analog Comparator's negative input is
// connected to the AIN1 pin
// Interrupt on Falling Output Edge
// Analog Comparator Input Capture by Timer/Counter 1: Off
ACSR=(0<<ACD) | (0<<ACBG) | (0<<ACO) | (0<<ACI) | (1<<ACIE) | (0<<ACIC) | (1<<ACIS1) | (0<<ACIS0);
SFIOR=(0<<ACME);

// Global enable interrupts
#asm("sei")

while (1)
      {
      // Place your code here
       while(i>=0)
       {
       PORTA=ebna[i]&0xff;   
       PORTC=(ebna[i]>>8);
       PORTA.0=1;
       PORTC.7=1;
       delay_us(300);
       i--;
       }
       PORTA.0=1;
       PORTC.7=1;
      }
}
