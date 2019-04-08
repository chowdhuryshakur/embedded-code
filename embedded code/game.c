#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int dice(int lower, int upper)
{
        int num = (rand() % (upper - lower + 1)) + lower;
        return num;
    }

int main()
{
    int p1=0, p2=0, a=0,b=0;
     int turnscore;
    int lower = -1, upper = 2, count = 1;
    srand(time(0));
    while(p1<9 && p2<9)
    {
        if(a!=0)
            a=a-1;

        else{
        printf("player1 turn\n");
        char s1;
        scanf("%c", &s1);
    turnscore = dice(lower, upper);
    printf("player 1 dice %d\n", turnscore);
    p1=p1+turnscore;
    if(p1>9)
    {p1=p1-turnscore;}
    printf("player 1 score is %d\n\n", p1);

    if(p1==5)
    {
        printf("Player1 again turn\n");
        char s1;
        scanf("%c", &s1);
        turnscore = dice(lower, upper);
        printf("player 1 dice %d\n", turnscore);
        switch(turnscore)
        {
        case -1:
            a=1;
            printf("player1 loose 1 turn\n");
            break;
        case 0:
            p1=p1-1;
            printf("player1 loose 1 point\n");
            printf("player 1 score is %d\n\n", p1);
            break;
        case 1:
            a=2;
            printf("player1 loose 2 turn\n");
            break;
        case 2:
            p1=p1-2;
            printf("player1 loose 2 point\n");
            printf("player 1 score is %d\n\n", p1);
            break;
        }
    }

if(p1==9)
        {printf("Player 1 is win!!!\n");
         break;}
        }


        if(b!=0)
            b=b-1;

        else{
        printf("player2 turn\n");
        char s2;
        scanf("%c", &s2);
    turnscore = dice(lower, upper);
    printf("player 2 dice %d\n", turnscore);
    p2 = p2+turnscore;
    if(p2>9)
    {p2=p2-turnscore;}
    printf("player 2 score is %d\n\n", p2);

    if(p2==5)
    {
        printf("Player2 again turn\n");
        char s2;
        scanf("%c", &s2);
        turnscore = dice(lower, upper);
        printf("player 2 dice %d\n", turnscore);
        switch(turnscore)
        {
        case -1:
            b=1;
            printf("player2 loose 1 turn\n");
            break;
        case 0:
            p2=p2-1;
            printf("player2 loose 1 point\n");
            printf("player 2 score is %d\n\n", p2);
            break;
        case 1:
            b=2;
            printf("player2 loose 2 turn\n");
            break;
        case 2:
            p2=p2-2;
            printf("player2 loose 2 point\n");
            printf("player 2 score is %d\n\n", p2);
            break;
        }
    }
    if(p2==9)
         {printf("Player 2 is win!!!\n");
          break;}

    }
    }




    return 0;
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
#include <stdlib.h>
#include <time.h>

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
uint8_t dice(int8_t lower, uint8_t upper)
{
	uint8_t num = (rand() % (upper - lower + 1)) + lower;
        return num;
    }






int main()
{
	uint8_t p1=0, p2=0, a=0,b=0;
	uint8_t turnscore;
	int8_t lower = -1, upper = 2;
	   srand(time(0));
	USART_init(MYUBRR);
	stdout = fdevopen(USART_send, NULL);
	stdin = fdevopen(NULL, USART_receive);
	while(1)
	{
		while(p1<9 && p2<9)
		   {
		       if(a!=0)
		           a=a-1;

		       else{
		       printf("player1 turn\n");
		       char s1;
		       scanf("%c", &s1);
		   turnscore = dice(lower, upper);
		   printf("player 1 dice %u\n", turnscore);
		   p1=p1+turnscore;
		   if(p1>9)
		   {p1=p1-turnscore;}
		   printf("player 1 score is %u\n\n", p1);

		   if(p1==5)
		   {
		       printf("Player1 again turn\n");
		       char s1;
		       scanf("%c", &s1);
		       turnscore = dice(lower, upper);
		       printf("player 1 dice %d\n", turnscore);
		       switch(turnscore)
		       {
		       case -1:
		           a=1;
		           printf("player1 loose 1 turn\n");
		           break;
		       case 0:
		           p1=p1-1;
		           printf("player1 loose 1 point\n");
		           printf("player 1 score is %u\n\n", p1);
		           break;
		       case 1:
		           a=2;
		           printf("player1 loose 2 turn\n");
		           break;
		       case 2:
		           p1=p1-2;
		           printf("player1 loose 2 point\n");
		           printf("player 1 score is %u\n\n", p1);
		           break;
		       }
		   }

		if(p1==9)
		       {printf("Player 1 is win!!!\n");
		        break;}
		       }


		       if(b!=0)
		           b=b-1;

		       else{
		       printf("player2 turn\n");
		       char s2;
		       scanf("%c", &s2);
		   turnscore = dice(lower, upper);
		   printf("player 2 dice %u\n", turnscore);
		   p2 = p2+turnscore;
		   if(p2>9)
		   {p2=p2-turnscore;}
		   printf("player 2 score is %u\n\n", p2);

		   if(p2==5)
		   {
		       printf("Player2 again turn\n");
		       char s2;
		       scanf("%c", &s2);
		       turnscore = dice(lower, upper);
		       printf("player 2 dice %u\n", turnscore);
		       switch(turnscore)
		       {
		       case -1:
		           b=1;
		           printf("player2 loose 1 turn\n");
		           break;
		       case 0:
		           p2=p2-1;
		           printf("player2 loose 1 point\n");
		           printf("player 2 score is %u\n\n", p2);
		           break;
		       case 1:
		           b=2;
		           printf("player2 loose 2 turn\n");
		           break;
		       case 2:
		           p2=p2-2;
		           printf("player2 loose 2 point\n");
		           printf("player 2 score is %u\n\n", p2);
		           break;
		       }
		   }
		   if(p2==9)
		        {printf("Player 2 is win!!!\n");
		         break;}

		   }
		   }
		       }
}
