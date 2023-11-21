#define APROBACION 6
#include <string.h>
#include <stdlib.h>
int obtenerAprobados(char *arrNombres[], int tam, char * aprobados[], int notas[]){
    int k=0;
    for (int i = 0; i < tam; i++)
    {
        if (notas[i]>=APROBACION)
        {
            aprobados[k]=malloc((strlen(arrNombres[i])+1)*sizeof(char));
            strcpy(aprobados[k++],arrNombres[i]);
        }
    }
    return k;
}