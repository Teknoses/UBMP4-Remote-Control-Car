#include    "xc.h"              // Microchip XC8 compiler include file
#include    "stdint.h"          // Include integer definitions
#include    "stdbool.h"         // Include Boolean (true/false) definitions

#include    "UBMP4.h"           // Include UBMP4 constants and functions

// TODO Set linker ROM ranges to 'default,-0-7FF' under "Memory model" pull-down.
// TODO Set linker code offset to '800' under "Additional options" pull-down.

// Button constant definitions
#define EnableA H1OUT
#define Abackward H2OUT
#define Aforward H3OUT
#define Bforward H4OUT
#define Bbackward H5OUT
#define EnableB H6OUT
unsigned char Speed = 255;
int command;

enum carstatetype
{
    forward,
    backward,
    left,
    right,
    neutral
};
enum carstatetype carstate = neutral;
// Program variable definitions

int main(void)
{
    OSC_config();               // Configure internal oscillator for 48 MHz
    UBMP4_config();             // Configure on-board UBMP4 I/O devices
    bluetooth_config();
	TRISC = 0b00000000;         //Sets H1-H8 Pins as Outputs
    while(1)
	{ 
        if(SW2 == 0)
        {
            while(!RCIF);
        }
        command = bluetooth_getChar();
         
        if(command == 1)
        {
            carstate = backward;
        }
        else if(command == 2)
        {
            carstate = forward;
        }
        else if(command == 3)
        {
            carstate = left;
        }
        else if(command == 4)
        {
            carstate = right;
        }
        else if(command == 5)
        {
            carstate = neutral;
        }









      if(carstate == backward)
      {
        EnableA = 1;
        EnableB = 1;
        Abackward = 1;
        Bbackward = 1;
        Aforward = 0;
        Bforward = 0;
      }
      else if(carstate == forward)
      {
        EnableA = 1;
        EnableB = 1;
        Abackward = 0;
        Bbackward = 0;
        Aforward = 1;
        Bforward = 1;
      }
        else if(carstate == left)
      {
        EnableA = 1;
          EnableB = 1;
        Abackward = 1;
        Bbackward = 0;
        Aforward = 0;
        Bforward = 1;
      }
         else if(carstate == right)
      {
        EnableA = 1;
        EnableB = 1;
        Abackward = 0;
        Bbackward = 1;
        Aforward = 1;
        Bforward = 0;
      }
      else if(carstate == neutral)
      {
        EnableA = 0;
        EnableB = 0;
        Abackward = 0;
        Bbackward = 0;
        Aforward = 0;
        Bforward = 0;
      }








        //RESET
        if(SW1 == 0)
        {
            RESET();
        }
    }
}