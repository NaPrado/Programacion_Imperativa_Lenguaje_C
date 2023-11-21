#include <stdio.h>
#include <stdlib.h>
#include "../../Librerias/getnum.h"
#define BLOQUE 5
#define OK 1


int main(){
    int c, i = 0, estado = OK;
    int *arr = NULL,* aux;
    while ((c=getchar())!=EOF && estado){
        if (i % BLOQUE == 0){
            aux = realloc(arr,sizeof(int) * (i+BLOQUE));
            if (aux != NULL)
                arr =aux;
            else
                estado = !OK;
        if (estado){
            arr[i]=c;
            i++;
        }
        arr = realloc(arr,i*sizeof(int));
        mostrarArreglo(arr, i);
        free(arr);
        return 0;
        }
        
    }
    
}