#include "Ej8.h"

typedef struct Node * TList;

typedef struct Node
{
    elemType head;
    TList tail;
}TNode;



typedef struct setCDT{
    TList L;
    size_t size;
    compare cmp;
}setCDT;


setADT
newSet(compare fcmp){
    setADT aux= malloc(sizeof(setCDT));
    aux->cmp=fcmp;
    return aux;
}


void
freeRec(TList lista){
    if (lista==NULL)
        return;    
    freeRec(lista->tail);
    free(lista);
    return;
}


void 
freeSet(setADT set){
    if (set->L!=NULL)
        freeRec(set->L);
    free(set);
    return;
}


int
isEmptySet(const setADT set){
    return set->size==0;
}


int
sizeSet(const setADT set){
    return set->size;
}


int
belongs(TList l, elemType elem){
    if (l==NULL)
        return 0;
    if (l->head<elem)
        return belongs(l->tail,elem);
    if (l->head==elem)
        return 1;
    return 0;
}


//pregunta si elem pertenece a set
int
containsSet(const setADT set, elemType elem){
    return belongs(set->L,elem);
}

TList
createNewNode(TList l,elemType elem){
    TList nuevo=calloc(1,sizeof(TNode));
    nuevo->head=elem;
    l=nuevo;
    return nuevo;
}


TList
include(TList l, elemType elem){
    if (l==NULL)
    {
        TList nuevo=calloc(1,sizeof(TNode));
        nuevo->head=elem;
        l=nuevo;
        return nuevo;
    }
    
    if (l->head>elem)
    {
        TList nuevo=calloc(1,sizeof(TNode));
        nuevo->tail=l;
        nuevo->head=elem;
        return nuevo;
    }
    if (l->head<elem)
    {
        l->tail=include(l->tail,elem);
        return l;
    }
    
    
}

int 
addElementSet(setADT set, elemType elem){
    if (!belongs(set->L,elem))
    {
        include(set->L,elem);
    }
    
}