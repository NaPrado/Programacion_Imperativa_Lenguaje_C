#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int
eliminaRepetidos(const int original[], int dimOrig, int resultado[]){
    int dimRes = !dimOrig?0:1, rep = 0;
    resultado[0]=original[0];
    for (int i = 0; i < dimOrig; i++, rep = 0){
        for (int j = 0; j < dimRes; j++){
            rep += resultado[j]==original[i];
        }
        if (!rep){
            resultado[dimRes] = original[i];
            dimRes++;
        }
    }
    return dimRes;
}
