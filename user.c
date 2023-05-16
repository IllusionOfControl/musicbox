#define _XTAL_FREQ 4000000
#if defined(__XC)
    #include <xc.h>         /* XC8 General Include File */
#elif defined(HI_TECH_C)
    #include <htc.h>        /* HiTech General Include File */
#endif

#include <stdio.h>
#include <stdint.h>         /* For uint8_t definition */
#include <stdbool.h>        /* For true/false definition */

#include "user.h"

unsigned char* note;
unsigned char playedTimes = 0;
bool isPlay = true;

void Repeat(void);
bool IsEnd(void);

void beep() {
    if (PORTBbits.RB7 == 1) PORTBbits.RB7 = 0;
    else PORTBbits.RB7 = 1;
    switch(*note) {
        case D3: __delay_us(6810); break;
        case F3: __delay_us(5730); break;
        case G3: __delay_us(5100);break;
        case G3d:__delay_us(4815); break;
    }
}


void Tackt() {
    if (*note == Empty) note++;
    if (!isPlay || *note == P) return;
    else if (playedTimes == 3) {
        Stop();
        return; 
    }
    else beep();
}


void Play(void) {
    isPlay = true;
    T0IE = 1;
}

void Stop(void) {
    isPlay = false;
    note = (unsigned char*) &song[0];
    playedTimes = 0;
    T0IE = 0;
    T0IF = 0; 
}


void NextNote() {
    static unsigned char noteDuration = 4;
    if (noteDuration > 0) noteDuration--;
    else {
        noteDuration = 4;
        
        if (IsEnd()) note++;
        else Repeat();
    }
}

bool IsEnd() {
    return note < &song[0] + sizeof(song) - 1;
}

void Repeat() {
    note = (unsigned char*) &song[0];
    playedTimes++;
}

void InitApp(void)
{
    // ????????? IO RB0 ? IN ??? ? OUT
    TRISB = 0;
    TRISB0 = 1;
    
    T0CS = 0; // ????????? ????????? ??????? TMR0 (??????????)
    PS2 = 1; PS1 = 1; PS0 = 1; // ?????????? ??????? 1:256
    PSA = 0; // Prescaler Assignment bit
    T0IE = 0; // ????? ???? ????????? ???????????? ??????? TMR0
    T0IF = 0; // ????? ???? ???????????? ??????? TMR0
    GIE = 1;
}

