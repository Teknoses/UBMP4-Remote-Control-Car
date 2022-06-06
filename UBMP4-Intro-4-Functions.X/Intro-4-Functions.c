/*==============================================================================
 Project: Intro-4-Functions
 Date:    May 16, 2021
 
 This program demonstrates the use of functions, and variable passing between
 the main and function code.
 
 Additional program analysis and programming activities examine function code
 location, function prototypes, and reinforce the concepts of global and local
 variables.
==============================================================================*/

#include    "xc.h"              // Microchip XC8 compiler include file
#include    "stdint.h"          // Include integer definitions
#include    "stdbool.h"         // Include Boolean (true/false) definitions

#include    "UBMP4.h"           // Include UBMP4 constants and functions

// TODO Set linker ROM ranges to 'default,-0-7FF' under "Memory model" pull-down.
// TODO Set linker code offset to '800' under "Additional options" pull-down.

// Button constant definitions


// Program variable definitions


int main(void)
{
    OSC_config();               // Configure internal oscillator for 48 MHz
    UBMP4_config();             // Configure on-board UBMP4 I/O devices
	TRISC = 0b00001001;
    while(1)
	{
        if(SW2 == 0 && SW3 == 1) //backwards
        {
            H2OUT = 1;
            LED3 = 1;
        }
        else
        {
            H2OUT = 0;
            LED3 = 0;
        }

        if(SW3 == 0 && SW2 == 1) //forwards
        {
            H3OUT = 1;
            LED4 = 1;
        }
        else
        {
            H3OUT = 0;
            LED4 = 0;
        }
        if(SW1 == 0)
        {
            RESET();
        }
    }
}

