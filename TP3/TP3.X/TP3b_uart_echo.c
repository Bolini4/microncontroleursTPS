/* 
 * File:   newmain.c
 *
 * Created on 6 janvier 2023, 09:52
 */
#include "configbits.h"
#include <xc.h>
#include <string.h>
#define _XTAL_FREQ 8000000 // define the frequency of the crystal oscillator
char msg;
void __interrupt() receive(){
    msg = RC1REG;
    TX1REG = msg;
    PIR1bits.RCIF = 0;
}


void main(void) {
    RC6PPS = 0x14;
    RXPPS = 0x17;

    //1. Configurer le registre ANSEL pour RC7 :
    ANSELCbits.ANSC7 = 0;

    //2. Configurer le registre TRIS pour RC6 et RC7 :
    TRISCbits.TRISC6 = 0;
    TRISCbits.TRISC7 = 1;

    //3. Configurer le registre LAT pour RC6 :
    LATCbits.LATC6 = 0;
    LATCbits.LATC7 = 0;

    BAUD1CONbits.BRG16 = 0; //1 = 16-bit Baud Rate Generator is used
    TX1STAbits.SYNC = 0;
    TX1STAbits.BRGH = 0;

    SP1BRGH = 0x00;
    SP1BRGL = 12;

    RC1STAbits.SPEN = 1;
    TX1STAbits.TXEN = 1;
    RC1STAbits.CREN =1;
    
    
    INTCONbits.GIE = 1; //enable global interrupts
    INTCONbits.PEIE = 1; //enable perpheral interupts
    
    PIE1bits.RCIE = 1; //enable RECEIV Interrupts


    while (1){
        // Envoi de la chaîne de caractère

        

        }
    }
