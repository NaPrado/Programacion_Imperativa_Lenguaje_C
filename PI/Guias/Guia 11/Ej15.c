#include "Ej15.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct node * TList;

typedef struct node
{
    elemType elem;
    TList tail;
}TNode;



typedef struct moveToFrontCDT{
    TList first;    // puntero al primer elemento de la lista
    size_t cant;   // almacena la cantidad de elementos
    TList iter;     // para iterar, apunta al nodo que contiene el valor a retornar por la función next
    compare cmp;  // Guardamos la función de comparación
}moveToFrontCDT;

/* Retorna un nuevo conjunto de elementos genéricos. Al inicio está vacío */
moveToFrontADT newMoveToFront(compare cmp){
    moveToFrontADT nuevo=calloc(1,sizeof(moveToFrontCDT));
    nuevo->cmp=cmp;
    return nuevo;
}

void freeRec(TList l){
    if (l==NULL)
        return;
    TList aux = l->tail;
    free(l);
    freeRec(aux);
    return;
}

/* Libera toda la memoria reservada por el TAD */
void freeMoveToFront(moveToFrontADT moveToFront){
    freeRec(moveToFront->first);
    free(moveToFront);
}

TList addRec(TList l,elemType e,int * ok,compare cmp){
    int c;
    if (l==NULL)
    {
        TList nuevo = calloc(1,sizeof(TNode));
        nuevo->elem=e;
        *ok=1;
        return nuevo;
    }
    if ((c=cmp(l->elem,e))==0)
    {
        return l;
    }
    l->tail=addRec(l->tail,e,ok,cmp);
    return l;
}

/* Inserta un elemento si no está. Lo inserta al final.
** Retorna 1 si lo agregó, 0 si no.
*/
unsigned int add(moveToFrontADT moveToFront, elemType elem){
    int ok=0;
    moveToFront->first=addRec(moveToFront->first,elem,&ok,moveToFront->cmp);
    moveToFront->cant+=ok;
    return ok;
}
  
/* Retorna la cantidad de elementos que hay en la colección */
unsigned int size(moveToFrontADT moveToFront){
    return moveToFront->cant;
}
 
/* Se ubica al principio del conjunto, para poder iterar sobre el mismo */
void toBegin(moveToFrontADT moveToFront){
    moveToFront->iter=moveToFront->first;
}

/* Retorna 1 si hay un elemento siguiente en el iterador, 0 si no */
int hasNext(moveToFrontADT moveToFront){
    return moveToFront->iter != NULL;
}

/* Retorna el siguiente elemento. Si no hay siguiente elemento, aborta */
elemType next(moveToFrontADT moveToFront){
    if (hasNext(moveToFront))
    {
        elemType ret = moveToFront->iter->elem;
        moveToFront->iter=moveToFront->iter->tail;
        return ret;
    }
    exit(1);
}

static TList searchAndDisconnect(TList list ,elemType elem, TList * found, compare cmp){
    // Si la lista es NULL, significa que el elemento no estaba
    // Dejamos NULL en el parámetro de entrada/salida found
    if(list == NULL){
        *found = NULL;
        return NULL;
    }

    // Si encontramos el elemento, lo desconectamos de la lista, haciendo que la cola del
    // elemento anterior apunte al siguiente. 
    // Dejamos en found el puntero al nodo que contiene al elemento que buscábamos.
    if(cmp(list->elem,elem) == 0){
        *found = list;
        return list->tail;
    }

    list->tail = searchAndDisconnect(list->tail,elem,found, cmp);
    return list;
}

/* Retorna una copia del elemento. Si no existe retorna NULL.
** Para saber si el elemento está, usa la función compare. 
** Si el elemento estaba lo ubica al principio.
 */
elemType * get(moveToFrontADT moveToFront, elemType elem){
    TList found;
    //Buscamos el elemento en la lista.
    moveToFront->first = searchAndDisconnect(moveToFront->first,elem, &found, moveToFront->cmp);

    // Si no estaba, devolvemos NULL
    if(found == NULL)
        return NULL;
    
    // Si lo encontramos, como ya lo "desenganchamos" de la lista, lo insertamos al principio: hacemos que 
    // su cola apunte al elemento que antes era el primero y lo fijamos como primero
    found->tail = moveToFront->first;
    moveToFront->first = found;

    // Hacemos una copia del elemento encontrado para devolverlo
    elemType * e = malloc(sizeof(elemType));
    *e = found->elem;
    return e;
}