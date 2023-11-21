
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include "../../Librerias/utillist.h"

TList addAll(TList lista1,  TList lista2);

#define ELEMS 200

int main(void) {

  int pares[ELEMS], impares[ELEMS];

  for(int i=1; i <= ELEMS; i++) {
    pares[i-1] = i * 2 ;
    impares[i-1] = i * 2 - 1;
  }

  TList lPar = fromArray(pares, ELEMS);
  TList lImpar = fromArray(impares, ELEMS);

  lPar = addAll(lPar, lImpar);

  int all[ELEMS * 2];
  for(int i=1, j=0; i <= ELEMS; i++) {
    all[j++] = i * 2 - 1;
    all[j++] = i * 2 ;
  }
  assert(checkElems(lPar, all, ELEMS*2));
  freeList(lPar);

  lPar = NULL;
  lPar = addAll(lPar, lImpar);
  assert(checkElems(lPar, impares, ELEMS));
  
  lPar = addAll(lPar, lImpar);
  assert(checkElems(lPar, impares, ELEMS));
  freeList(lPar);

  lPar = fromArray(pares, ELEMS);
  lImpar = addAll(lImpar, lPar);
  assert(checkElems(lImpar, all, ELEMS*2));
  freeList(lPar);
  freeList(lImpar);
   
  int w[] = {1,2,3,4,5,6,7,8};
  TList l1 = fromArray(w,3);
  TList l2 = fromArray(w+3,5);
  l1 = addAll(l1,l2);
  assert(checkElems(l1, w, 8));
  freeList(l1);
  freeList(l2);

  l1 = fromArray(w,8);
  l2 = fromArray(w,8);
  l1 = addAll(l1,l2);
  assert(checkElems(l1, w, 8));
  freeList(l2);
  freeList(l1);


  printf ("OK!\n");
  return 0;
}

TList addAll(TList l1,  TList l2){
    if (l2==NULL)
        return l1;
    if (l1==NULL||l2->elem<l1->elem)
    {
        TList nuevo = malloc(sizeof(TNode));
        nuevo->elem=l2->elem;
        nuevo->tail=addAll(l1,l2->tail);
        return nuevo;
    }
    if (l2->elem>l1->elem)
        l1->tail=addAll(l1->tail,l2);
    else
        l1->tail=addAll(l1->tail,l2->tail);
    return l1;
}