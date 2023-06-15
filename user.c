#define _XTAL_FREQ 4000000

#include <xc.h>      

#include <stdio.h>
#include <stdint.h>         
#include <stdbool.h>        

#include "user.h"

unsigned char note = 0;
unsigned char playedTimes = 0;
bool isPlay = false;

void Repeat(void);
bool IsEnd(void);

void beep(unsigned char note) {
    switch(note) {
        case D3: __delay_us(D3_Freq); break;
        case F3: __delay_us(F3_Freq); break;
        case G3: __delay_us(G3_Freq); break;
        case G3d:__delay_us(G3d_Freq); break;
        case P: return;
    }
    if (PORTBbits.RB7 == 1) PORTBbits.RB7 = 0;
    else PORTBbits.RB7 = 1;
}


void Tackt() {
    unsigned char currentNote = eeprom_read(note);
    
    if (!isPlay) return;
    else if (playedTimes == 3) Stop();
    else beep(currentNote);
}


void Play(void) {
    isPlay = true;
    T0IE = 1;
}

void Stop(void) {
    isPlay = false;
    note = 0;
    playedTimes = 0;
    T0IE = 0;
    T0IF = 0; 
}


void NextNote() {
    static unsigned char noteDuration = 4;
    if (noteDuration) noteDuration--;
    else {
        noteDuration = 4;
        
        if (!IsEnd()) note++;
        else Repeat();
    }
}

bool IsEnd() {
    return note > SONG_LENGHT - 1;
}

void Repeat() {
    note = 0;
    playedTimes++;
}

void InitApp(void)
{
    TRISB = 0;       // Configure PORTB as output
    TRISB0 = 1;      // Configure RB0 pin as input
    
    T0CS = 0;        // Select internal instruction cycle clock (Fosc/4) as the source for Timer0
    PS2 = 1; PS1 = 1; PS0 = 1;  // Set Timer0 prescaler to 1:256
    PSA = 0;         // Assign Timer0 prescaler to Timer0 module
    T0IE = 0;        // Disable Timer0 overflow interrupt
    T0IF = 0;        // Clear Timer0 overflow interrupt flag
    GIE = 1;         // Enable global interrupts
}


