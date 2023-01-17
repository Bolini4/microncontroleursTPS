/*
 * File:   TP2a_pwm.c
 * Author: matte
 *
 * Created on 17 janvier 2023, 15:47
 */


// Configuration bits
#pragma config FOSC = INTOSC, PLLEN = OFF, WDTE = OFF
#pragma config MCLRE = OFF, LVP = OFF

#include <xc.h>


void setup_button(void){
    TRISAbits.TRISA5 =1; //configure en entrée
    ANSELAbits.ANSA5 =0; //ce n'est pas une entrée analogique
}

void main(void) {
        // Initialize the device
    OSCCON = 0xFC;
    ANSELB = 0x00;
    ANSELD = 0x00;
    TRISB = 0x00;
    TRISD = 0x00;

    // Initialize the timer2
    T2CONbits.T2CKPS0 = 1;
    T2CONbits.T2CKPS1 = 0; //prescaler at 4
    
    T2CONbits.T2OUTPS0 = 1;
    T2CONbits.T2OUTPS1 = 0;
    T2CONbits.T2OUTPS2 = 0; //post scaler at 2
    T2CONbits.T2OUTPS3 = 0;
    
    T2CONbits.TMR2ON = 1;
    
    PIR1bits.TMR2IF = 0; //initialize flag at 0;
    
    PR2 = 0xF9; //set overflow value
     LATB = 0b0000;
     LATD = 0b0000;
    
    
    
    RB3PPS = 0b01111;
    
    PWM4CON = 0b10000000; //enable pwm / output active is high  
    PWM4DCH = 0x0A;
    PWM4DCL = 0x00;

   
    return;
}
