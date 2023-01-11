#include <xc.h>

// Configuration bits
#pragma config FOSC = INTOSC, PLLEN = OFF, WDTE = OFF
#pragma config MCLRE = OFF, LVP = OFF

void wait_1ms(){
    while(1){
    if(PIR1bits.TMR2IF ==1){
        PIR1bits.TMR2IF =0;
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

    while(1) {
        
        LATB = 0b0001; //LEDS OFF
        LATD = 0b0000;
        wait_1s();
        
        LATB = 0b0010; //LEDS OFF
        LATD = 0b0000;
        wait_1s();
        
        LATB = 0b0100; //LEDS OFF
        LATD = 0b0000;
        wait_1s();
        
        LATB = 0b1000; //LEDS OFF
        LATD = 0b0000;
        wait_1s();
        
        LATB = 0b0000; 
        LATD = 0b0001;
        wait_1s();
        
        LATB = 0b0000; 
        LATD = 0b0010;
        wait_1s();
        
        LATB = 0b0000; 
        LATD = 0b0100;
        wait_1s();
        
        LATB = 0b0000; //LEDS OFF
        LATD = 0b1000;
        
        
        
        wait_1s();


    return 0;
}
}
