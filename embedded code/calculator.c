#include <stdio.h>
long int operation(long int x, long int y, int o)
{
    switch(o)
    {
    case 1:
        return x+y;
        break;
    case 2:
        return x-y;
        break;
    case 3:
        if(x>y)
            return x;
        else
            return y;
        break;
    case 4:
        if(x<y)
            return x;
        else
            return y;
        break;
    case 5:
        return x>>y;
        break;
    case 6:
        return x<<y;
        break;
    default:
        printf("error\n");
    }
}
int main(){
long int a;
long int b;
int o;
long int r;
printf("Enter first number:");
scanf("%ld", &a);
printf("Enter second number:");
scanf("%ld", &b);
printf("Enter operation:");
scanf("%d", &o);
r = operation(a,b,o);
printf("%ld", r);
}





/*
 * Doxygen tutorail site: http://wiki.vmars.tuwien.ac.at/index.php/Doxygen_Primer
 * and here http://mcuoneclipse.com/2012/06/25/5-best-eclipse-plugins-1-eclox-with-doxygen-graphviz-and-mscgen/
 * to make pdf output go to latex directory and run make command
 */

/**
 * @file usart.c
 * @author rezwan
 * @date 05.06.2015
 *
 * @brief AVR ATMEGA328P USART communication example for CSE3023.
 *
 * A simple echo program that receives a character from computer and echos it back.
 *  Eclipse may cause problem in macro resolution = 'Symbol xxx could not be resolved'.
 *  If someone encounters this problem following steps should resolve the matter.
 *  In the project explorer right click on the project then go to 'index' and left click on Rebuild'
*/
#include <avr/io.h>
#include <stdio.h>
#include <util/delay.h>


#define F_CPU 16000000UL /**< Clock speed for delay functions. */


#define FOSC 16000000 /**< Clock speed for UBRR calculation. refer page 179 of 328p datasheet. */
#define BAUD 9600 /**< Baud Rate in bps. refer page 179 of 328p datasheet. */
#define MYUBRR FOSC/16/BAUD-1 /**< UBRR = (F_CPU/(16*Baud))-1 for asynch USART page 179 328p datasheet. Baud rate 9600bps, assuming	16MHz clock UBRR0 becomes 0x0067*/

/**
 * @brief Initialize USART for 8 bit data transmit no parity and 1 stop bit.
 *
 *@details This is a code snippet from datasheet page 182
 *
 * @param ubrr The UBRR value calculated in macro MYUBRR
 * @see MYUBRR
*/
void USART_init(unsigned int ubrr)
{

	UCSR0C = (0<<USBS0)|(3<<UCSZ00); /// Step 1. Set UCSR0C in Asynchronous mode, no parity, 1 stop bit, 8 data bits
	UCSR0A = 0b00000000;/// Step 2. Set UCSR0A in Normal speed, disable multi-proc

	UBRR0H = (unsigned char)(ubrr>>8);/// Step 3. Load ubrr into UBRR0H and UBRR0L
	UBRR0L = (unsigned char)ubrr;


	UCSR0B = 0b00011000;/// Step 4. Enable Tx Rx and disable interrupt in UCSR0B
}

/**
 * @brief Send 8bit data.
 *
 *@details This is a code snippet from datasheet page 184
 *
 * @param data The 8 bit data to be sent
*/

int USART_send(char c, FILE *stream)
{

	while ( !( UCSR0A & (1<<UDRE0)) )/// Step 1.  Wait until UDRE0 flag is high. Busy Waitinig
	{;}

	UDR0 = c; /// Step 2. Write char to UDR0 for transmission
}
/**
 * @brief Receive 8bit sata.
 *
 *@details This is a code snippet from datasheet page 187
 *
 * @return Returns received data from UDR0
*/
int USART_receive(FILE *stream )
{

	while ( !(UCSR0A & (1<<RXC0)) )/// Step 1. Wait for Receive Complete Flag is high. Busy waiting
		;

	return UDR0;/// Step 2. Get and return received data from buffer
}

/**
 * @brief Program entry point.
 *
 *@details This is a code snippet from datasheet page 187.
 *Initialize the usart communication.
 *Then in the while loop first wait for the data and then echo it back.
 *
*/

unsigned long int operation(unsigned long int x, unsigned long int y, uint8_t o)
{
    switch(o)
    {
    case 1:
        return x+y;
        break;
    case 2:
        return x-y;
        break;
    case 3:
        if(x>y)
            return x;
        else
            return y;
        break;
    case 4:
        if(x<y)
            return x;
        else
            return y;
        break;
    case 5:
        return x>>y;
        break;
    case 6:
        return x<<y;
        break;
    }
}





int main()
{

	unsigned long int a;
	unsigned long int b;
	uint8_t o;
	unsigned long int r;

	USART_init(MYUBRR);
	stdout = fdevopen(USART_send, NULL);
	stdin = fdevopen(NULL, USART_receive);
	while(1)
	{
		printf("Enter first number:");
		scanf("%lu", &a);
		printf("Enter second number:");
		scanf("%lu", &b);
		printf("Enter operation:");
		scanf("%u", &o);
		r = operation(a,b,o);
		printf("%lu", r);
		       }
}

