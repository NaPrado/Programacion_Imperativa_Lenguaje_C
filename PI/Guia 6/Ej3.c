#include <stdio.h>
#include <stdlib.h>
#include <math.h>
double
maxDiferencia(const double arreglo[]){
    double save, mayor = 0;
    for (int i=0; arreglo[i+1] != 0; i++){
            save = fabs(arreglo[i]-arreglo[i+1]);
            if (save > mayor)
            {
                mayor = save;
            }
    }
    return mayor;
}