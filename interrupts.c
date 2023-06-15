#include <xc.h> 

#include <stdint.h> 
#include "user.h"

#define NOTE_DURATION   64

#ifndef _PIC16

void __interrupt() isr(void)
{
    if (T0IF & T0IE)
    {
        T0IF=0;
    	TMR0 = NOTE_DURATION;
        NextNote();
    }
}
#endif


