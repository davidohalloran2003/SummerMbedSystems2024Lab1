#include "mbed.h"


/* 

a few words max 100 on the program.
For InterruptIn bluebtn, Right click BUTTON1 in brackets and >Go To Declaration  which will give the definition of location of #define BUTTON1  PC_13  // BUTTON_EXTI13 [B2] - which also again if right click on PC_13
>Go To Declaration which will give the definition of location of PC_13      = 0x2D
Right Click and >Go to Declaration will give further info on your code
Original Error "Error Message: Mutex: 0x200015FC, Not allowed in ISR context" - Fix: Disable and enable irq 

*/

InterruptIn bluebtn(PC_13);

void bttnFall () {
printf("bttnfall triggerd");       
}

void bttnRise() {
    printf("bttnRise triggerd");
}

// main() runs in its own thread in the OS
int main()
{
        bluebtn.fall(&bttnFall);
        bluebtn.rise(&bttnRise);

//This program is for the Lab 1 embedded systems module 

while (true) {

}

}