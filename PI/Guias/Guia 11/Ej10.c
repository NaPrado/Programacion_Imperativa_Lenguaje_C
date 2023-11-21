#include "Ej10.h"
#include <stdlib.h>
#include <stdio.h>

typedef struct Node * TList;

typedef struct Node
{
    elemType elemento;
    size_t cant;
    TList tail;
}TNode;

typedef struct bagCDT
{
    TList first;
    size_t size;
    compare cmp;    
}bagCDT;

/* Retorna un nuevo bag de elementos genéricos. Al inicio está vacío */
bagADT 
newBag(compare cmp){
    bagADT bag=calloc(1,sizeof(bagCDT));
    bag->cmp=cmp;
    return bag;
}

size_t
countRec(TList first, elemType elem,compare cmp){
    int c;
    if (first==NULL || (c=cmp(first->elemento, elem)) > 0)
        return 0;
    if (c==0)
        return first->cant;
    return countRec(first->tail,elem,cmp);
}

/* Retorna cuántas veces aparece el elemento en el bag */
unsigned int 
count(const bagADT bag, elemType elem){
    return countRec(bag->first,elem,bag->cmp);
}

/* Retorna la cantidad de elementos distintos que hay en el bag */
unsigned int 
size(const bagADT bag){
    return bag->size;
}

TList
addRec(TList first,elemType elem,compare cmp,int * countElem){
    int c;
    if (first==NULL || (c=cmp(first->elemento,elem)) > 0){
        TList nuevo= malloc(sizeof(TNode));
        nuevo->elemento= elem;
        nuevo->tail=first;
        nuevo->cant= 1;
        *countElem= 1;
        return nuevo;
    }
    if (c<0)
        first->tail = addRec(first->tail,elem,cmp,countElem);
    else
        *countElem= ++(first->cant);
    return first;
}
/* Inserta un elemento. Retorna cuántas veces está
** elem en el conjunto luego de haberlo insertado (p.e. si es la primera inserción retorna 1).
*/
unsigned int add(bagADT bag, elemType elem){
    int countElem;
    bag->first=addRec(bag->first,elem,bag->cmp,&countElem);
    if (countElem==1)//primera vez que añado el elemento
    {
        bag->size++;
    }
    return countElem;
}

/* Libera toda la memoria reservada por el TAD */
void freeBag( bagADT bag){
    TList current= bag->first,aux;
    while (current!=NULL)
    {
        aux=current->tail;
        free(current);
        current=aux;
    }
    free(bag);
}

/* Retorna el elemento que aparece más veces. Si hay más de uno 
** con esa condición, retorna cualquiera de los dos. 
** Precondicion: el bag no debe estar vacio. En caso de estar vacío, aborta
** la ejecución
*/
elemType mostPopular(bagADT bag){
    elemType ans;
    if (bag->size==0)
    {
        printf("El bag debe estar vacio\n");
        exit(1);
    }
    else{
        TList aux=bag->first;
        size_t cant=aux->cant;
        ans=aux->elemento;
        aux=aux->tail;
        while (aux!=NULL){
            if (aux->cant>cant){
                ans=aux->elemento;
                cant=aux->cant;
            }
            aux=aux->tail;
        }
        return ans;
    }
    
}
 
