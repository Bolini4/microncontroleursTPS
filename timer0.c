/* 
 * File:   newmain2.c
 *
 * Created on 6 janvier 2023, 09:52
 */

// AP:No #include "configbits.h" ?
#include <stdio.h>  // AP:No use here
#include <stdlib.h> // AP:No use here
#include <xc.h>
#define _XTAL_FREQ 8000000 // define the frequency of the crystal oscillator

int main(void) { // AP:main does not need to return anything on MCUs : best form is void main(void){}
    // Initialize the device
    OSCCON = 0xFC; // AP:Description ?
    ANSELB = 0x00; // AP:Description ? Any use here ?
    ANSELD = 0x00; // AP:Description ? Any use here ?
    TRISD = 0x00;  // AP:Description ? I know D1-D4 are TRISD<0:3>, why set TRISD<4:7> aswell ?
    TRISB = 0x00;  // AP:Description ? I know D5-D8 are TRISB<0:3>, why set TRISB<4:7> aswell ?

    while(1){
        OPTION_REGbits.PS = 0; // AP: no need to execute this repeatedly : this should be an initialization routine
        OPTION_REGbits.TMR0CS = 0;
        while((INTCON & 0x04) == 0) {
            // AP: Why do this in a while loop ? The best would be to either :
            // * Do nothing while you wait (blocking)
            // * Test TMR0IF : if it is set, toggle ; if it is not, skip. Repeat (non-blocking)
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
        /* AP: 3 next lines : no need to execute this repeatedly + it is odd setting this here : this should be an initialization routine */
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
    return 0; // AP:main does not need to return anything on MCUs : best form is void main(void){}
}
