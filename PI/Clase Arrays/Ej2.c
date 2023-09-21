#include<stdio.h>
#define FILAS 100
#define COLUMNAS 500

int main(void){
    int dimFilas= 0, dimCol= 0;
    float numeros[FILAS][COLUMNAS], suma= 0;
    // se asignan valores a componentes
    for (int i = 0; (i < FILAS);i++)
    {
        for (int j = 0; j < COLUMNAS; j++)
        {
            suma += numeros[i][j];
        }
        putchar('\n');
    }
     
}