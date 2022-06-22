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
                                    
enum carstatetype //sets up different carstates
{
    forward,
    backward,
    left,
    right,
    neutral,
};
enum carstatetype carstate = neutral; //sets carstate as neutral to start

int recievecommand(void);
void changestate(void); 
int setstate(void);
void backwardstate(void);
void forwardstate(void);
void leftstate(void);
void rightstate(void);
void neutralstate(void);
// Program variable definitions

int main(void)
{
    OSC_config();               // Configure internal oscillator for 48 MHz
    UBMP4_config();             // Configure on-board UBMP4 I/O devices
    bluetooth_config();         // Configures pins on the Microchip to connect to bluetooth
	TRISC = 0b00000000;         // Sets H1-H8 pins as outputs
    while(1)
	{ 
        changestate();  
        //RESET
        if(SW1 == 0)
        {
            RESET();
        }
    }
}

int recievecommand(void)
{
    while(!RCIF);
    int command = bluetooth_getChar();
    return(command);
}



int setstate(void)
{
    int command = bluetooth_getChar();
     if(command == 1)
    {
        return(backward);
    }
    else if(command == 2)
    {
        return(forward);
    }
    else if(command == 3)
    {
        return(left);
    }
    else if(command == 4)
    {
        return(right);
    }
    else if(command == 5)
    {
        return(neutral);
    }
}

void changestate(void)
{

    carstate = setstate();

    if(carstate == backward)
      {
        backwardstate();
      }
      else if(carstate == forward)
      {
        forwardstate();
      }
        else if(carstate == left)
      {
        leftstate();
      }
        else if(carstate == right)
      {
        rightstate();
      }
      else if(carstate == neutral)
      {
        neutralstate();
      }
}

void backwardstate(void)
{
    
    EnableA = 1;
    EnableB = 1;
    Abackward = 1;
    Bbackward = 1;
    Aforward = 0;
    Bforward = 0;
}

void forwardstate(void)
{
    EnableA = 1;
    EnableB = 1;
    Abackward = 0;
    Bbackward = 0; 
    Aforward = 1;
    Bforward = 1;
}

void leftstate(void)
{
    EnableA = 1;
    EnableB = 1;
    Abackward = 1;
    Bbackward = 0;
    Aforward = 0;
    Bforward = 1;
}

void rightstate(void)
{
    EnableA = 1;
    EnableB = 1;
    Abackward = 0;
    Bbackward = 1;
    Aforward = 1;
    Bforward = 0;
}

void neutralstate(void)
{
    EnableA = 0;
    EnableB = 0;
    Abackward = 0;
    Bbackward = 0;
    Aforward = 0;
    Bforward = 0;
}