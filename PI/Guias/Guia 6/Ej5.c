#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int
eliminaRepetidos(const int original[], int dimOrig, int resultado[]){
    int dimRes = 0, i=0;
    if (dimOrig<=0){
       return 0;
    }
    while (i<dimOrig-1){
        if(original[i]!=original[i+1]){
            resultado[dimRes++]=original[i];
        }
        i++;
    }
    resultado[dimRes++]=original[i];
    return dimRes;
}