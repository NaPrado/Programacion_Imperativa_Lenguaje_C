#include <stdio.h>
int lector(const int m[][30],int i, int j);

void
graficar (const int cielo[][30], int filas, int columnas){
    for (int i = 1; i < filas-1; i++){
        for (int j = 1; j < columnas-1; j++){
            if(lector(cielo,i,j)>10){
                printf("*");
            }
            else
                printf(" ");
    }
    printf("\n");
}
}

int
lector(const int m[][30],int i, int j){
    int f=i;
    int c=j;
    int suma=0;
    for (int i = f-1; i <= f+1 ; i++){
        for (int j = c-1; j <= c+1 ; j++){
        suma += m[i][j];
        }
    }
    return suma/9;
}