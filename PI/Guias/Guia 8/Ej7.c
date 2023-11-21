#include <stdio.h>
#include <ctype.h>
#define FILS 6
#define COLS 7
#define DIC 10
typedef enum {DER=0, IZQ, ABA, ARR, I_AR, I_AB, D_AR, D_AB } Tdireccion;

struct posicion {
	char * palabra;
	size_t fila;
	size_t columna;
	Tdireccion direccion;
};

int
MAX (int x,int y){
    return (x>y)?(x):(y);
}

int
MIN(int x, int y){
    return (x<y)?(x):(y);
}



char *diccionario[] = {"ARRE", "CANCION", "CAPA", "ERROR", "ORCO", "PERRO", "PERTINAZ", "REA", "RIO", ""};

struct posicion
checkDir(char sopa[FILS][COLS],char * diccionario,int i,int j){
    for (int x = MAX(i-1,0); x < MIN(i+1,FILS-1); x++)
    {
        for (int y = MAX(j-1,0); y < MIN(i+1,COLS); y++)
        {
            if(sopa[x][y]==*(diccionario+1)){
                if ()
                {
                    /* code */
                }
                
                struct posicion pos;
                pos.palabra=diccionario;
                pos.fila=i;
                pos.columna=j;
                pos.direccion=;
                return 
            }
        }
        
    }
    
    
}

controlaDic(char sopa[FILS][COLS],char * diccionario[DIC],int i,int j){
    for (int q = 0; q < DIC; q++)
    {
        if (sopa[i][j]==*diccionario[q])
        {
            checkDir(sopa,diccionario[q],i,j);
        }
    }
}


struct posicion
recorreSopa(char sopa[FILS][COLS], char * diccionario[DIC]){
    for (int i = 0; i < FILS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            if(controlaDic(sopa,diccionario,i,j)){

            }
        }
        
    }
    
    
}

struct posicion
resolverSopa(char sopa[FILS][COLS], char * diccionario[DIC]){
    recorreSopa(sopa,diccionario);
    
}