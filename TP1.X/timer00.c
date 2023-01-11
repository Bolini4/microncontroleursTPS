#include <xc.h>

// Configuration bits
#pragma config FOSC = INTOSC, PLLEN = OFF, WDTE = OFF
#pragma config MCLRE = OFF, LVP = OFF


void wait_1ms(){
    while(1){
    if(INTCONbits.TMR0IF ==1){
        INTCONbits.TMR0IF =0;
        TMR0 = 0x06;
        return;
    }
    }

}

void wait_1s(){
    for(int i=0; i<1000; i++){
        wait_1ms();
    }
}

int main(void) {
    // Initialize the device
    OSCCON = 0xFC;
    ANSELB = 0x00;
    ANSELD = 0x00;
    TRISB = 0x00;
    TRISD = 0x00;

    // Initialize the timer
    OPTION_REGbits.TMR0CS = 0; //prendre fosc/4
    OPTION_REGbits.PSA = 0; //Use prescaler
    
    OPTION_REGbits.PS0 = 0; 
    OPTION_REGbits.PS1 = 1; //set prescaler to value 8 
    OPTION_REGbits.PS2 = 0; 
    
    
   
    INTCONbits.TMR0IF = 0; //clear overflow flag
    TMR0 = 0x06;


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
        wait_1s();

       //  Toggle the second group of LEDs
        LATBbits.LATB3 = 0;
        LATBbits.LATB2 = 0;
        LATBbits.LATB1 = 0;
        LATBbits.LATB0 = 0;
        LATDbits.LATD3 = 1;
        LATDbits.LATD2 = 1;
        LATDbits.LATD1 = 1;
        LATDbits.LATD0 = 1;

       //  Delay
        wait_1s();
    }

    return 0;
}
