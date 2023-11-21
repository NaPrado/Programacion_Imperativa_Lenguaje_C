#include <stdlib.h>
#include <stdio.h>
#define BLOQUE 5


int *
pares(const int * v, size_t dim, size_t * nuevaDim){
    int * rta= NULL;
    *nuevaDim=0;
    for (int i = 0; i < dim; i++)
    {
        if (v[i]%2==0)
        {
            if (*nuevaDim%BLOQUE==0)
            {
                rta=realloc(rta,(*nuevaDim+BLOQUE)*sizeof(*rta));
            }
            rta[(*nuevaDim)++]=v[i];
        }
        
    }
    rta=realloc(rta,*nuevaDim*sizeof(*v));
    return rta;
}