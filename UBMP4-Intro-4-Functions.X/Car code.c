
#include    "xc.h"              // Microchip XC8 compiler include file
#include    "stdint.h"          // Include integer definitions
#include    "stdbool.h"         // Include Boolean (true/false) definitions

#include    "UBMP4.h"           // Include UBMP4 constants and functions

// TODO Set linker ROM ranges to 'default,-0-7FF' under "Memory model" pull-down.
// TODO Set linker code offset to '800' under "Additional options" pull-down.

// Button constant definitions
#define EnableA H1OUT
#define EnableB H6OUT
#define Aforward H3OUT
#define Abackward H2OUT
#define Bforward H4OUT
#define Bbackward H5OUT
// Program variable definitions


int main(void)
{
    OSC_config();               // Configure internal oscillator for 48 MHz
    UBMP4_config();             // Configure on-board UBMP4 I/O devices
	TRISC = 0b00000000;
    while(1)
	{
       if(SW2 == 0 && SW3 == 1 && SW4 == 1 && SW5 == 1) //backwards
        {
            EnableA = 1;
            EnableB = 1;
            Abackward = 1;
            Bbackward = 1;
        }
        else
        {
            EnableA = 0;
            EnableB = 0;
            Abackward = 0;
            Bbackward = 0;

        }

        // if(SW3 == 0 && SW2 == 1 && SW4 == 1 && SW5 == 1) //forwards
        // {
        //     EnableA = 1;
        //     EnableB = 1;
        //     Aforward = 1;
        //     Bforward = 1;
 
        // }
        // else
        // {
        //     EnableA = 0;
        //     EnableB = 0;
        //     Aforward = 0;
        //     Bforward = 0;
        // }
        if(SW4 == 0 && SW2 == 1 && SW3 == 1 && SW5 == 1) //Turn right
        {
            EnableA = 1;
            EnableB = 1;
            Aforward = 1;
            Bbackward = 1;
        }
        else
        {
            EnableA = 0;
            EnableB = 0;
            Aforward = 0;
            Bbackward = 0;
        }
        if(SW5 == 0 && SW2 == 1 && SW3 == 1 && SW4 == 1) //Turn left
        {
            EnableA = 1;
            EnableB = 1;
            Bforward = 1;
            Abackward = 1;
        }
        else
        {
            EnableA = 0;
            EnableB = 0;
            Bforward = 0;
            Abackward = 0;
        }
        //RESET
        if(SW1 == 0)
        {
            RESET();
        }
    }
}

