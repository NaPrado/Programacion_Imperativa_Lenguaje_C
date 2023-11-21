#include "Ej13.h"
#include <stdio.h>
#include <stdlib.h>

struct rankingCDT
{
    elemType * elems;
    size_t amount;
    compare cmp;
};

void swap(rankingADT r,size_t a,size_t b){
    elemType aux=r->elems[a];
    r->elems[a]=r->elems[b];
    r->elems[b]=aux;
    return;
}

/* Crea un nuevo ranking. Recibe un vector con elementos, donde el primer
** elemento (elems[0]) está al tope del ranking (puesto 1), elems[1] en el 
** puesto 2, etc. Si dim es cero significa que no hay elementos iniciales
*/
rankingADT newRanking(elemType elems[], size_t dim, compare cmp){
    rankingADT nuevo = malloc(sizeof(struct rankingCDT));
    if (dim>0){
        nuevo->elems = malloc(dim*sizeof(elemType));
        for (size_t i = 0; i < dim; i++)
        nuevo->elems[i]=elems[i];
    }
    else
        nuevo->elems=NULL;
    nuevo->amount = dim;
    nuevo->cmp=cmp;
    return nuevo;
}


size_t where(rankingADT ranking, elemType elem){
    for (size_t i = 0; i < ranking->amount; i++)
        if (ranking->cmp((ranking->elems[i]),(elem))==0)
            return i;
    return -1;
}


/* Agrega un elemento en la posición más baja del ranking, si no estaba.
** Si el elemento estaba, es equivalente a accederlo, por lo que sube un 
** puesto en el ranking
*/
void addRanking(rankingADT ranking, elemType elem){
    int pos=where(ranking,elem);
    if (pos==0)
        return;
    if (pos>0){
        swap(ranking,pos,pos-1);
        return;
    }
    ranking->amount++;
    ranking->elems=realloc(ranking->elems,sizeof(ranking->amount)*ranking->amount);
    ranking->elems[ranking->amount-1]=elem;
    return;
}

/* La cantidad de elementos en el ranking */
size_t size(const rankingADT ranking){
    return ranking->amount;
}

/* Si n es una posición válida del ranking, guarda en elem el elemento que está 
** en el puesto n y retorna 1.
** Si no hay elemento en la posición n, retorna cero y no modifica *elem
** Este acceso también hace que el elemento suba un puesto en el ranking
*/
int getByRanking(rankingADT ranking, size_t n, elemType * elem){
    if (ranking->amount<n || n<=0)
        return 0;
    *elem=ranking->elems[n-1]; //la respuesta hizo otra cosa que tiene mucho mas sentido veamos si esto funciona
    addRanking(ranking,*elem);
    return 1;
}


/* top: entrada/salida
** Recibe cuántos elementos al tope del ranking se desean 
** Almacena cuántos pudo guardar (ver ejemplos)
** Si el ranking está vacío *top queda en cero y retorna NULL
*/
elemType * getTopRanking(const rankingADT ranking, size_t * top){
    size_t cant=(*top<ranking->amount?*top:ranking->amount);
    *top=cant;
    if (cant<=0)
        return NULL;
    elemType * ans=malloc(cant*sizeof(elemType));
    for (size_t i = 0; i < cant; i++)
        ans[i]=ranking->elems[i];
    return ans;
}

/* 1 si el elemento consultado está en el ranking, cero si no 
** Este acceso también hace que el elemento suba un puesto en el ranking
*/
int contains(rankingADT ranking, elemType elem){
    int c=where(ranking,elem);
    if (c<0)
        return 0;
    addRanking(ranking,elem);
    return 1;
}
/* int contains(rankingADT ranking, elemType elem){
	int n = where(ranking, elem, ranking->cmp);
	if( n < 0 )
		return 0;
	if( n > 0 )
		swap( ranking, n, n-1 );
	return 1;
} */
/* Baja una posición en el ranking para el elemento que está en la posición n */
void downByRanking(rankingADT ranking, size_t n){
    swap( ranking, n-1, n );
}

void freeRanking(rankingADT r){
    free(r->elems);
    free(r);
}