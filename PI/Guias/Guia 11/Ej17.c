#include "Ej17.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct cifrada * TList;

struct cifrada
{
    char * frase;
    size_t clave;
    size_t longitug;
    TList tail;
};


typedef struct phrasesCDT{
    TList first; //como una lista pero con palabras y key
    size_t Ro; //rango inicial
    size_t Rf; //rango final
}phrasesCDT;

/*
* Recibe cuál será el rango de claves válidas a utilizar, por ejemplo si
* keyFrom=1001, keyTo=1500 habrá un máximo de 500 frases a almacenar
* keyFrom=1001, keyTo=3500 habrá un máximo de 2500 frases a almacenar
* Si los parámetros son inválidos retorna NULL
*/
phrasesADT newPhrasesADT(size_t keyFrom, size_t keyTo){
    if(keyFrom<keyTo){
        phrasesADT nuevo=calloc(1,sizeof(phrasesCDT));
        nuevo->Ro=keyFrom;
        nuevo->Rf=keyTo;
        return nuevo;
    }
    return NULL;
}

/* Libera toda la memoria reservada por el TAD */
void freePhrases(phrasesADT ph);


#define BLOCK 20

// Recibe un string (puede ser NULL), la cantidad de bytes ya reservados y de ser necesario va creando mas espacio
// Si estamos trabajando con strings extensos no seria eficiente usar
// directamente strlen y malloc, por lo que copiamos de a bloques
static char * copy(char * s, const char *newS, size_t * len ) {
    char * ans = s;
    
    size_t reserved = *len;
    size_t i;
    for (i = 0; newS[i] != 0; i++) {
        // Si ya usamos todo el string original, entonces agrandamos
        if ( i == reserved) {
            reserved += BLOCK;
            ans = realloc(ans, reserved);
        }
        ans[i] = newS[i];
    }
    ans = realloc(ans, i+1);     // liberamos lo que usamos de mas
    ans[i]=0;
    *len = i; 
    return ans;
}

putR(TList l,int * ok,size_t key,const char * phrase){
    int c;
    if ( l==NULL || (c=l->clave)>key )
    {
        TList nuevo=calloc(1,sizeof(struct cifrada));
        nuevo->clave=key;
        nuevo->tail=l;
        copy(nuevo->frase,phrase,)
    }
    
}

/*
* Agrega una frase. Si la clave key es inválida retorna 0, sinó retorna 1 (uno)
* Si ya hay una frase asociada a la clave, actualiza la frase almacenada,
* reemplazándola por el parámetro phrase.
* Se almacena una copia de la frase.
*/
int put(phrasesADT ph, size_t key, const char * phrase){

}

/*
* Retorna una copia de la frase asociada a la clave key. Si no hay frase asociada
* a la clave key retorna NULL, lo mismo si la clave es inválida.
*/
char * get(const phrasesADT ph, size_t key);

/*
* Cantidad de frases almacenadas
*/
size_t size(const phrasesADT ph);

/*
* Retorna un string con todas las frases concatenadas 
* Si no hay frases retorna un string vacío
*/
char * concatAll(const phrasesADT ph);

/*
* Retorna un string con todas las frases concatenadas cuyas claves estén entre
* from y to inclusive. Si from o to son inválidas (están fuera del rango)
* retorna NULL
* Si no hay frases en ese rango, retorna un string vacío
*/
char * concat(const phrasesADT ph, size_t from, size_t to);
