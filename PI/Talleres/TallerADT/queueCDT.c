#include "queueADT.h"
#include "../../Librerias/utillist.h"

typedef struct queueCDT
{
    TList first;
    TList last;
    TList nashe;
}queueCDT;


queueADT
newQueue(void){
    return calloc(1,sizeof(queueCDT));
}

void queue(queueADT q, elementType n){
    TList nuevo=calloc(1,sizeof(TNode));
    nuevo->elem=n;
    if (q->first==NULL){
        q->first=q->last=nuevo;
        return;
    }
    q->last->tail=nuevo;
    q->last=nuevo;
    return;
}

void dequeue(queueADT q, elementType * out){
    if (isEmpty(q))
        return;
    TList aux=q->first->tail;
    *out=q->first->elem;
    free(q->first);
    q->first=aux;
    if (q->first==NULL)
        q->last=NULL;
    return;
}

void freerec(TList l){
    if (l==NULL)
        return;
    freerec(l->tail);
    free(l);
}

void freeQueue(queueADT q){
    free(q->last);
    freerec(q->first);
    free(q);
}

int isEmpty(queueADT q){
    return q->first==NULL;
}

void toBegin(queueADT q){
    q->nashe=q->first;
}

int hasNext(queueADT q){
    return q->nashe!=NULL;
}

elementType next(queueADT q){
    elementType aux = q->nashe->elem;
    q->nashe=q->nashe->tail;
    return aux;
}

/* NASHEE */