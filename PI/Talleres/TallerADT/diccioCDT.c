#include "diccioADT.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct TPalsign{
    char palabra[MAXWIDTH];
    char significado[MAXSIGNIFICADO]
};


typedef struct TLetra{
    char letra;
    size_t * palabrasContadas;
    int conPalabras;
}TLetra;

typedef struct diccioCDT{
    TLetra arrLetras[MAXWIDTH];
}diccioCDT;

diccioADT creaDiccionario(void){
    return calloc(1,sizeof(diccioCDT));
}

void liberaDiccionario(diccioADT dic){
    free(dic);
}

int agregaPalabra(diccioADT dic, const char * palabra, const char * significado){
    
}