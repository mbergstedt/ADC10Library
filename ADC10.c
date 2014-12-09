/*
 * ADC10.c
 *
 *  Created on: Dec 8, 2014
 *      Author: C16Matthew.Bergstedt
 */

#include "msp430g2553.h"
#include "ADC10.h"

unsigned short leftSensorReading(void){
	// set the clock
	BCSCTL1 = CALBC1_8MHZ;										// 8MHz clock
	DCOCTL = CALDCO_8MHZ;

	ADC10CTL0 = 0;
	ADC10CTL1 = INCH_5 | ADC10DIV_3 ;
	ADC10AE0 = BIT5;
	ADC10CTL0 = SREF_0 | ADC10SHT_3 | ADC10ON | ENC;
	ADC10CTL0 |= ADC10SC;
	while(ADC10CTL1 & ADC10BUSY);
	return ADC10MEM;
}

unsigned short frontSensorReading(void){
	// set the clock
	BCSCTL1 = CALBC1_8MHZ;										// 8MHz clock
	DCOCTL = CALDCO_8MHZ;

	ADC10CTL0 = 0;
	ADC10CTL1 = INCH_3 | ADC10DIV_3 ;
	ADC10AE0 = BIT3;
	ADC10CTL0 = SREF_0 | ADC10SHT_3 | ADC10ON | ENC;
	ADC10CTL0 |= ADC10SC;
	while(ADC10CTL1 & ADC10BUSY);
	return ADC10MEM;
}

unsigned short rightSensorReading(void){
	// set the clock
	BCSCTL1 = CALBC1_8MHZ;										// 8MHz clock
	DCOCTL = CALDCO_8MHZ;

	ADC10CTL0 = 0;
	ADC10CTL1 = INCH_4 | ADC10DIV_3 ;
	ADC10AE0 = BIT4;
	ADC10CTL0 = SREF_0 | ADC10SHT_3 | ADC10ON | ENC;
	ADC10CTL0 |= ADC10SC;
	while(ADC10CTL1 & ADC10BUSY);
	return ADC10MEM;
}
