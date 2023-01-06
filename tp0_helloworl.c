 
  File   newmain.c
  Author 
 
  Created on 6 janvier 2023, 0952
 

#include stdio.h
#include stdlib.h
#include xc.h
#define _XTAL_FREQ 8000000  define the frequency of the crystal oscillator

int main(void) {
     Initialize the device
    OSCCON = 0xFC;
    ANSELB = 0x00;
    ANSELD = 0x00;
    TRISD = 0x00;
    TRISB = 0x00;

    while(1) {
         Toggle the first group of LEDs
        LATBbits.LATB3 = 1;
        LATBbits.LATB2 = 1;
        LATBbits.LATB1 = 1;
        LATBbits.LATB0 = 1;
        LATDbits.LATD3 = 0;
        LATDbits.LATD2 = 0;
        LATDbits.LATD1 = 0;
        LATDbits.LATD0 = 0;

         Delay
        __delay_ms(1000);

         Toggle the second group of LEDs
        LATBbits.LATB3 = 0;
        LATBbits.LATB2 = 0;
        LATBbits.LATB1 = 0;
        LATBbits.LATB0 = 0;
        LATDbits.LATD3 = 1;
        LATDbits.LATD2 = 1;
        LATDbits.LATD1 = 1;
        LATDbits.LATD0 = 1;

         Delay
        __delay_ms(1000);
    }

    return 0;
}