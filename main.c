#define _XTAL_FREQ 4000000

#include <xc.h>     

#include <stdint.h>        
#include <stdbool.h>      

#include "system.h"        
#include "user.h"          

void main(void)
{
    ConfigureOscillator();

    InitApp();

    while(1) {
        if (!RB0) {
            while (!RB0) __delay_ms(200);
            Stop();
            Play();
        }
        Tackt();
    }
}

