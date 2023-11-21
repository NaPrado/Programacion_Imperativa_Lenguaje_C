#include "Ej14.h"
#include <stdio.h>
#include <stdlib.h>


typedef struct node {
  elemType elem;
  struct node * tail;
} node;

typedef struct listCDT {
    struct node * firstAsc;     // primero en orden ascendente
    struct node * firstInsert;
    struct node * lastInsert;
    struct node * iterAsc;      // para iterar en orden ascendente
    struct node * iterInsert;
    int (*compare) (elemType e1, elemType e2);  // almacenamos la función de comparación
} listCDT;
 
/* Retorna una lista vacía.
*/
listADT newList(int (*compare) (elemType e1, elemType e2)){
    listADT nuevo= calloc(1,sizeof(listCDT));
    nuevo->compare=compare;
    return nuevo;
}

node * addRec(node*lista,elemType elem,int *ok,int (*compare) (elemType e1, elemType e2)){
    int c;
    if (lista==NULL || (c=compare((lista->elem),(elem))) > 0 )
    {
        node * nuevo= malloc(sizeof(node));
        nuevo->elem=elem;
        nuevo->tail=lista;
        *ok=1;
        return nuevo;
    }
    if (c<0)
        lista->tail=addRec(lista->tail,elem,ok,compare);
    return lista;
}


/* Agrega un elemento. Si ya estaba no lo agrega */
void add(listADT list, elemType elem){
    int ok;
    list->firstAsc=addRec(list->firstAsc, elem,&ok,list->compare);//añado por orden asc
    if (ok)
    {
        node * nuevo= malloc(sizeof(node));
        nuevo->elem=elem;
        nuevo->tail=NULL;
        if (list->firstInsert==NULL)
            list->firstInsert=nuevo;
        else
            list->lastInsert->tail=nuevo;
        list->lastInsert=nuevo;
    }
}

/* Resetea el iterador que recorre la lista en el orden de inserción */
void toBegin(listADT list){
    list->iterInsert=list->firstInsert;
}

/* Retorna 1 si hay un elemento siguiente en el iterador que
** recorre la lista en el orden de inserción. Sino retorna 0 */
int hasNext(listADT list) {
  return list->iterInsert != NULL;
}

/* Retorna el elemento siguiente del iterador que recorre la lista en el orden de inserción. 
** Si no hay un elemento siguiente o no se invocó a toBegin aborta la ejecución.
*/
elemType next(listADT list){
    if (hasNext(list))
    {
        elemType ans=list->iterInsert->elem;
        list->iterInsert=list->iterInsert->tail;
        return ans;    
    }
    fprintf(stderr, "Invalid use of iterator\n");
    exit(1);
}

/* Resetea el iterador que recorre la lista en forma ascendente */
void toBeginAsc(listADT list){
    list->iterAsc=list->firstAsc;
}

/* Retorna 1 si hay un elemento siguiente en el iterador que
** recorre la lista en forma ascendente. Sino retorna 0 */
int hasNextAsc(listADT list){
    return list->iterAsc != NULL;
}

/* Retorna el elemento siguiente del iterador que recorre la lista en forma ascendente. 
** Si no hay un elemento siguiente o no se invocó a toBeginAsc aborta la ejecución.
*/
elemType nextAsc(listADT list){
    if (hasNextAsc(list))
    {
        elemType toReturn = list->iterAsc->elem;
        list->iterAsc = list->iterAsc->tail;
        return toReturn;
    }
    fprintf(stderr, "Invalid use of iterator\n");
    exit(1);
}

void freeNodeRec(node* list){
    while (list!=NULL)
    {
        node* aux=list->tail;
        free(list);
        list=aux;
    }
}

/* Libera la memoria reservada por la lista */
void freeList(listADT list){
    freeNodeRec(list->firstAsc);
    freeNodeRec(list->firstInsert);
    free(list);
}