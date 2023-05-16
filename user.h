#define P       0
#define D3      1
#define F3      2
#define G3      3
#define G3d     4
#define Empty   255



__EEPROM_DATA(D3, P, F3, P, G3, G3, P, D3);
__EEPROM_DATA(P, F3, P, G3d, G3, G3, P, P,);
__EEPROM_DATA(D3, P, F3, P, G3, G3, P, F3); 
__EEPROM_DATA(P, D3, D3, D3, D3, P, P, P, );
__EEPROM_DATA(P, Empty, Empty, Empty, Empty, Empty, Empty, Empty);

const unsigned char song[] = {
    D3,
    P,
    F3,
    P,
    G3, 
    G3, 
    P,
    
    D3, 
    P, 
    F3,
    P,
    G3d,
    G3, 
    G3, 
    P, 
    P, 
    
    D3,
    P, 
    F3, 
    P, 
    G3, 
    G3, 
    P, 
    F3, 
    P,
    D3, D3, D3, D3, 
    
    P, P, P, P,
};

void InitApp(void);
void Tackt(void);
void NextNote(void);
void Play(void);
void Stop(void);
