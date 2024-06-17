#include "mbed.h"
#include <cstdio>

/* 

a few words max 100 on the program.
a variable has been created called Interrupt triggered int_trig
For InterruptIn bluebtn, Right click BUTTON1 in brackets and >Go To Declaration  which will give the definition of location of #define BUTTON1  PC_13  // BUTTON_EXTI13 [B2] - which also again if right click on PC_13
>Go To Declaration which will give the definition of location of PC_13      = 0x2D
Right Click and >Go to Declaration will give further info on your code
Original Error "Error Message: Mutex: 0x200015FC, Not allowed in ISR context" - Fix: Disable and enable irq - Or certainly Removing printF
When the blue bttn is pressed it will remain a continuous "buttonfall" until releaesed and then print a continuous "bttnrise" as file one will always be running. The fix is to write a rest into the code. 

Note: ensure the functions are being called which in turn will ensure the value is being changed when a change happens. Key termn in this case is 'volatile'

So finally when the code is downloaded to the mbed and the bluebttn is pressed a message is printed to CoolTerm to indicate this, printed as 'bttnFall' 
*/

InterruptIn bluebtn(PC_13);

volatile int int_trig = 0;

void bttnFall () {
        int_trig = 1;

}

// main() runs in its own thread in the OS
int main()
{
        bluebtn.fall(&bttnFall);
      

//This program is for the Lab 1 embedded systems module 

while (true) {
    if (int_trig ==1){
            int_trig = 0;
            printf("bttnFall \r\n");

    }
    
}

}

