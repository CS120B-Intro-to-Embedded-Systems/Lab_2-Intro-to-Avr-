/*	Author: Karsten
 *  Partner(s) Name:
 *	Lab Section:
 *	Assignment: Lab #  Exercise #
 *	Exercise Description: [optional - include for your own benefit]
 *
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */
#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif

int main(void) {
	DDRA = 0x00; PORTA = 0xFF; // Configure port A's 8 pins as inputs
	//DDRB = 0xFF; PORTB = 0x00; // Configure port B's 8 pins as outputs, initialize to 0s
	DDRC = 0xFF; PORTC = 0x00;

	//unsigned char tmpB = 0x00; // Temporary variable to hold the value of B
	unsigned char tmpA = 0x00; // Temporary variable to hold the value of A
	unsigned char tmpA1 = 0x00;
	unsigned char tmpA2 = 0x00;
	unsigned char tmpA3 = 0x00;
	unsigned char cntavail = 0x00;
    while(1) {
            // 1) Read input
            tmpA = PINA & 0x01; //PA0
						tmpA1 = PINA & 0x02; //PA1
						tmpA2 = PINA & 0x04; //PA2
						tmpA3 = PINA & 0x08; //PA3
            // 2) Perform computation
            // if PA0 is 1, set PB1PB0 = 01, else = 10
            if(tmpA == 0x00){
							cntavail = cntavail + 0x01;
						}
						if(tmpA1 == 0x00){
							cntavail = cntavail + 0x01;
						}
						if(tmpA2 == 0x00){
							cntavail = cntavail + 0x01;
						}
						if(tmpA3 == 0x00){
							cntavail = cntavail + 0x01;
						}

						PORTC = cntavail;
						//reset
						cntavail = 0x00;
			}
	return 0;
}
