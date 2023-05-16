/******************************************************************************/
/*Files to Include                                                            */
/******************************************************************************/
#if defined(__XC)
    #include <xc.h>         /* XC8 General Include File */
#elif defined(HI_TECH_C)
    #include <htc.h>        /* HiTech General Include File */
#endif

#include <stdint.h>         /* For uint8_t definition */
#include <stdbool.h>        /* For true/false definition */

#include "user.h"

/******************************************************************************/
/* Interrupt Routines                                                         */
/******************************************************************************/

/* Baseline devices don't have interrupts. Note that some PIC16's 
 * are baseline devices.  Unfortunately the baseline detection macro is 
 * _PIC12 */

#define fosc    4 // ???
#define mc      4 // ???????? ?????
#define devisor 256 // ???????????? TMR0 1:256. PS2=1;PS1=1;PS0=1;
#define BPM     115 // BMP = ?????? "?????????? (1/4)" ? ??????
#define period  (1000000*60)/(BPM*8) // 1/32 ?????? ? 8 ??? ????
#define TMR0_   256-(period*(fosc/mc)/devisor)
//#define TMR0_   0

#ifndef _PIC16

void __interrupt() isr(void)
{
    if (T0IF & T0IE)
    {
        T0IF=0;
    	TMR0 = TMR0_;
        NextNote();
        
        if (PORTBbits.RB3 == 1) PORTBbits.RB3 = 0;
        else PORTBbits.RB3 = 1;
    }
    RB3 = !RB3;
//    if (RBIF && RBIE) {
//        T0IE = 1;
//        RBIF = 0;
//        Play();
//    }
}
#endif


