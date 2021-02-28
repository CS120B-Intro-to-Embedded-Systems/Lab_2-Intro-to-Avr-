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
	DDRA = 0x00; PORTA = 0xFF;// Configure port A's 8 pins as inputs
	DDRB = 0x00; PORTB = 0xFF;// Configure port B's 8 pins as inputs
	DDRC = 0x00; PORTC = 0xFF;// Configure port C's 8 pins as inputs
	DDRD = 0xFF; PORTD = 0x00;// Configure portD's 8 pins as outputs

	unsigned char tmpA = 0x00;// Temporary variable to hold the value of A
	unsigned char tmpB = 0x00;// Temporary variable to hold the value of B
	unsigned char tmpC = 0x00;// Temporary variable to hold the value of C
	unsigned char tmpD = 0x00;// Temporary variable to hold the value of D
	int sum = 0;
	  while(1) {
            // 1) Read input
            tmpA = PINA;
						tmpB = PINB;
						tmpC = PINC;

						sum = tmpA + tmpB + tmpC;

						if(sum > 0x8C){ //0x8C = 140 kg
							tmpD = tmpD + 0x01; //add 1 to pd0
						}
						if((tmpC - tmpA) > 0x50 || (tmpA - tmpC) > 0x50){ //0x50 = 80 kg
							tmpD = tmpD + 0x02; //add 1 to pd1
						}

						tmpD = tmpD + (sum << 2); //add sum to the rest of tmpD
						PORTD = tmpD;

						//reset
						tmpD = 0x00;
    }
	return 0;
}
