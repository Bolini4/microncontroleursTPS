/* 
 * File:   newmain2.c
 *
 * Created on 6 janvier 2023, 09:52
 */

#include <stdio.h>
#include <stdlib.h>
#include <xc.h>
#define _XTAL_FREQ 8000000 // define the frequency of the crystal oscillator

int main(void) {
    // Initialize the device
    OSCCON = 0xFC;
    ANSELB = 0x00;
    ANSELD = 0x00;
    TRISD = 0x00;
    TRISB = 0x00;

    while(1){
        OPTION_REGbits.PS = 0;
        OPTION_REGbits.TMR0CS = 0;
        while((INTCON & 0x04) == 0) {
            // Toggle the first group of LEDs
            LATBbits.LATB3 = 1;
            LATBbits.LATB2 = 1;
            LATBbits.LATB1 = 1;
            LATBbits.LATB0 = 1;
            LATDbits.LATD3 = 0;
            LATDbits.LATD2 = 0;
            LATDbits.LATD1 = 0;
            LATDbits.LATD0 = 0;
        }
        INTCONbits.TMR0IF = 0;
        TMR0 = 0x38;
        OPTION_REGbits.PS0 = 1;
        OPTION_REGbits.PS1 = 1;
        OPTION_REGbits.PS2 = 1;
        // Toggle the second group of LEDs
        LATBbits.LATB3 = 0;
        LATBbits.LATB2 = 0;
        LATBbits.LATB1 = 0;
        LATBbits.LATB0 = 0;
        LATDbits.LATD3 = 1;
        LATDbits.LATD2 = 1;
        LATDbits.LATD1 = 1;
        LATDbits.LATD0 = 1;
    }
    return 0;
}