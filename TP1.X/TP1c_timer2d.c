#include <xc.h>

// Configuration bits
#pragma config FOSC = INTOSC, PLLEN = OFF, WDTE = OFF
#pragma config MCLRE = OFF, LVP = OFF

int t_ms=0;
int i = 0;

void __interrupt() wait_tmr2(){
    if(t_ms = 60000){
        switch( i )
{
    case 0:
        LATB = 0b0001;
        LATD = 0b0000;
        i++;
        break;
    case 1 :
        LATB = 0b0010;
        LATD = 0b0000;
        i++;
        break;
    case 2 :
        LATB = 0b0100;
        LATD = 0b0000;
        i++;
        break;
    case 3 :
        LATB = 0b1000;
        LATD = 0b0000;
        i++;
        break;
    case 4 :
        LATB = 0b0000;
        LATD = 0b0001;
        i++;
        break;
    case 5 :
        LATB = 0b0000;
        LATD = 0b0010;
        i++;
        break;
    case 6 :
        LATB = 0b0000;
        LATD = 0b0100;
        i++;
        break;
    case 7 :
        LATB = 0b0000;
        LATD = 0b1000;
        i++;
        i=0;
        break;
}
  PIR1bits.TMR2IF = 0;
    }
    t_ms++;
    if(t_ms > 1000){
        t_ms =0;
    }
    PIR1bits.TMR2IF = 0;
    }
     


int main(void) {
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
    
    INTCONbits.GIE = 1; //enable global interrupts
    INTCONbits.PEIE = 1; //enable perpheral interupts
    
    PIE1bits.TMR2IE = 1; //enable Timer2 Interrupts
   

    while(1) {
    }
       


    return 0;
}


