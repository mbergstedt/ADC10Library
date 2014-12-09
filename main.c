//-----------------------------------------------------------------
// Name:	Matt Bergstedt
// Date:	8 Dec 14
// Purp:	Demonstrate use of the ADC10 header and sub files
//-----------------------------------------------------------------

#include <msp430.h> 
#include "ADC10.h"

void initMSP430();

/*
 * main.c
 */
void main(void) {
    WDTCTL = WDTPW | WDTHOLD;	// Stop watchdog timer
	IFG1=0; 					// clear interrupt flag1

    // use to keep values of input from ir sensors
	unsigned short sampleLeft;
	unsigned short sampleRight;
	unsigned short sampleFront;
	
	P1DIR = BIT0 | BIT6;										// Set the LEDs as output

	while(1) {
		// read from the different sensors
		sampleLeft  = leftSensorReading();
		sampleFront = frontSensorReading();
		sampleRight = rightSensorReading();

		// turn the LEDs on depending on the input
		if (sampleRight > 0x0250)			P1OUT |= BIT0;
		else if (sampleLeft > 0x0250)		P1OUT |= BIT6;
		else if (sampleFront > 0x0250)		P1OUT |= BIT0|BIT6;
		else								P1OUT &= ~(BIT0 | BIT6);
	}
}
