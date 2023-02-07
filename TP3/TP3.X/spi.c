/* Explorer 8 SPI Module APIs Source File

 * File originally generated by Microchip for the Explorer 8 (Device : PIC16F1719)
 * File amended (01/2023) by AP for JUNIA ISEN AP4

 */


/**
  Section: Included Files
*/

#include <xc.h>
#include "spi.h"

#define RxyPPS_SCK 0x10
#define RxyPPS_SDO 0x11
#define xxxPPS_RC3 0x13
#define xxxPPS_RC4 0x14

#define SPI_CLK_LAT  LATCbits.LATC3
#define SPI_CLK_TRIS TRISCbits.TRISC3
#define SPI_SDI_LAT  LATCbits.LATC4
#define SPI_SDI_TRIS TRISCbits.TRISC4
#define SPI_SDO_LAT  LATCbits.LATC5
#define SPI_SDO_TRIS TRISCbits.TRISC5


/**
  Section: Macro Declarations
*/

#define SPI_RX_IN_PROGRESS 0x0


/**
  Section: Module APIs
*/

void SPI_InitializePins(void){
    // SPI CLK
    SPI_CLK_LAT = 0;
    SPI_CLK_TRIS = 0;

    // SPI Data In
    SPI_SDI_LAT = 0;
    SPI_SDI_TRIS = 1;

    // SPI Data Out
    SPI_SDO_LAT = 0;
    SPI_SDO_TRIS = 0;

    SSPDATPPSbits.SSPDATPPS = xxxPPS_RC4; // RC4->MSSP:SDI;
    RC3PPSbits.RC3PPS       = RxyPPS_SCK; // RC3->MSSP:SCK;
    SSPCLKPPSbits.SSPCLKPPS = xxxPPS_RC3; // RC3->MSSP:SCK;
    RC5PPSbits.RC5PPS       = RxyPPS_SDO; // RC5->MSSP:SDO;
}

void SPI_Initialize(void)
{
    SSP1STAT = 0x40; // R_nW write_noTX; P stopbit_notdetected; S startbit_notdetected; BF RCinprocess_TXcomplete; SMP Middle; UA dontupdate; CKE Active to Idle; D_nA lastbyte_address;
    SSP1CON1 = 0x22; // SSPEN enabled; WCOL no_collision; CKP Idle:Low, Active:High; SSPM FOSC/64; SSPOV no_overflow;
    SSP1ADD = 0x00; // SSP1ADD 0;
}

char SPI_Exchange8bit(char data)
{
    // Clear the Write Collision flag, to allow writing
    SSP1CON1bits.WCOL = 0;

    SSP1BUF = data;

    while(SSP1STATbits.BF == SPI_RX_IN_PROGRESS)
    {
        CLRWDT();
    }

    return (SSP1BUF);
}

char SPI_Exchange8bitBuffer(char *dataIn, char bufLen, char *dataOut)
{
    char bytesWritten = 0;

    if(bufLen != 0)
    {
        if(dataIn != NULL)
        {
            while(bytesWritten < bufLen)
            {
                if(dataOut == NULL)
                {
                    SPI_Exchange8bit(dataIn[bytesWritten]);
                }
                else
                {
                    dataOut[bytesWritten] = SPI_Exchange8bit(dataIn[bytesWritten]);
                }

                bytesWritten++;
                CLRWDT();
            }
        }
        else
        {
            if(dataOut != NULL)
            {
                while(bytesWritten < bufLen )
                {
                    dataOut[bytesWritten] = SPI_Exchange8bit(DUMMY_DATA);

                    bytesWritten++;
                    CLRWDT();
                }
            }
        }
    }

    return bytesWritten;
}

char SPI_IsBufferFull(void)
{
    return (SSP1STATbits.BF);
}

char SPI_HasWriteCollisionOccured(void)
{
    return (SSP1CON1bits.WCOL);
}

void SPI_ClearWriteCollisionStatus(void)
{
    SSP1CON1bits.WCOL = 0;
}
/**
 End of File
*/
