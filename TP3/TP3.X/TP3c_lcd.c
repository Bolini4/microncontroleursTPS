/* 
 * File:   newmain.c
 *
 * Created on 6 janvier 2023, 09:52
 */
#include "configbits.h"
#include "spi.h"
#include "lcd.h"
#include <xc.h>

#define _XTAL_FREQ 8000000 // define the frequency of the crystal oscillator



void main(void) {
    SPI_InitializePins();
    LCD_InitializePins();
    LCD_Clear();
    LCD_GoTo(0,0);
    LCD_WriteString("Coucou");
    while (1){
        // Envoi de la chaîne de caractère
        }
    }

