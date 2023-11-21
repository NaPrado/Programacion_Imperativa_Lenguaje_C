#include <stdio.h>
#include <stdlib.h>
#include "../../Librerias/getnum.h"

cargarNumeros(int * dim){
    int *arr = malloc(sizeof(int));
    int i=0,n;
    do
    {
        n=getint("Dame un numero: ");
        arr[i++]=n;
        arr=realloc(arr,i+1*sizeof(int));
    } while (!esRepetido(arr,n,i));
    arr=realloc(arr,i*sizeof(int));
    *dim=i;
    return arr;
    
}


int main(){
    int dim;
    int *arr;
    arr= cargarNumeros(&dim);

    for (int i = 0; i < dim; i++)
        printf("%d ", arr[i]);
    
    free(arr);
    return 0;
    
}