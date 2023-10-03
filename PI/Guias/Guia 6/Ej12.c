#include <stdio.h>
void
swap(int matriz[][6], int i, int j){
    int aux;
    aux=matriz[i][j];
    matriz[i][j]=matriz[j][i];
    matriz[j][i]=aux;
}


void
traspuesta(int m[][6],int dim){
    for (int i = 0; i < dim; i++){
        for (int j = i; j < dim; j++){
                if(i!=j)
                swap(m,i,j);
        }
    }
}