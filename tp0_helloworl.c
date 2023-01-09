/*
 * File:   newmain2.c
 *
 * Created on 6 janvier 2023, 09:52
 */

// AP:No #include "configbits.h" ?
#include <stdio.h>  // AP:No use here
#include <stdlib.h> // AP:No use here
#include <xc.h>
#define _XTAL_FREQ 8000000  define the frequency of the crystal oscillator

int main(void) { // AP:main does not need to return anything on MCUs : best form is void main(void){}
    // Initialize the device
    OSCCON = 0xFC; // AP:Description ?
    ANSELB = 0x00; // AP:Description ? Any use here ?
    ANSELD = 0x00; // AP:Description ? Any use here ?
    TRISD = 0x00;  // AP:Description ? I know D1-D4 are TRISD<0:3>, why set TRISD<4:7> aswell ?
    TRISB = 0x00;  // AP:Description ? I know D5-D8 are TRISB<0:3>, why set TRISB<4:7> aswell ?

    while(1) {
        // Toggle the first group of LEDs
        LATBbits.LATB3 = 1;
        LATBbits.LATB2 = 1;
        LATBbits.LATB1 = 1;
        LATBbits.LATB0 = 1;
        LATDbits.LATD3 = 0;
        LATDbits.LATD2 = 0;
        LATDbits.LATD1 = 0;
        LATDbits.LATD0 = 0;

        // Delay
        __delay_ms(1000); // AP:OK. Should be 500 ms for a 1s period

        // Toggle the second group of LEDs
        LATBbits.LATB3 = 0;
        LATBbits.LATB2 = 0;
        LATBbits.LATB1 = 0;
        LATBbits.LATB0 = 0;
        LATDbits.LATD3 = 1;
        LATDbits.LATD2 = 1;
        LATDbits.LATD1 = 1;
        LATDbits.LATD0 = 1;

        // Delay
        __delay_ms(1000); // AP:OK. Should be 500 ms for a 1s period
    }

    return 0; // AP:main does not need to return anything on MCUs : best form is void main(void){}
}
