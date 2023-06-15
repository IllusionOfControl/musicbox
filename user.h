#define P       0
#define D3      1
#define F3      2
#define G3      3
#define G3d     4

// calculated from 1/NoteFreq*1000'000 ms
#define D3_Freq  6810
#define F3_Freq  5727
#define G3_Freq  5102
#define G3d_Freq 4815

const unsigned char SONG_LENGHT = 32; 

__eeprom unsigned char song[] = {
    D3, P, F3, P, G3, G3, P,
    
    D3, P, F3, P, G3d, G3, G3, P, P, 
    
    D3, P, F3, P, G3, G3, P, F3, P, D3, D3, D3, D3, 
    
    P, P, P, P
};

void InitApp(void);
void Tackt(void);
void NextNote(void);
void Play(void);
void Stop(void);
