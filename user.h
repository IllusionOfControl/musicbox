/******************************************************************************/
/* User Level #define Macros                                                  */
/******************************************************************************/

/* TODO Application specific user parameters used in user.c may go here */

/******************************************************************************/
/* User Function Prototypes                                                   */
/******************************************************************************/

/* TODO User level functions prototypes (i.e. InitApp) go here */


#define P       0
#define D3      1
#define F3      2
#define G3      3
#define G3d     4



const unsigned char song[] = {
    D3, D3, D3, D3, 
    P, P, P, P,
    F3, F3, F3, F3, 
    P, P, P, P,
    G3, G3, G3, G3,
    G3, G3, G3, G3,
    P, P, P, P,
    
    D3, D3, D3, D3, 
    P, P, P, P,
    F3, F3, F3, F3, 
    P, P, P, P,
    G3d, G3d, G3d, G3d,
    G3, G3, G3, G3,
    G3, G3, G3, G3,
    P, P, P, P,
    P, P, P, P,
    
    D3, D3, D3, D3, 
    P, P, P, P,
    F3, F3, F3, F3, 
    P, P, P, P,
    G3, G3, G3, G3,
    G3, G3, G3, G3,
    P, P, P, P,
    F3, F3, F3, F3, 
    P, P, P, P,
    D3, D3, D3, D3, 
    D3, D3, D3, D3, 
    D3, D3, D3, D3, 
    D3, D3, D3, D3, 
    
    P, P, P, P,
    P, P, P, P,
    P, P, P, P,
    
};

void InitApp(void);         /* I/O and Peripheral Initialization */
void Tackt(void);
void NextNote(void);
void Play(void);
void Stop(void);
