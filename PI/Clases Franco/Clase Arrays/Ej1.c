#include <stdio.h>
#define FILAS 10
#define COLUMNAS 5
int
main(void)
{
    int numeros[FILAS][COLUMNAS];
// se asignan valores a la matriz
    for (int i = 0; (i < FILAS);i++)
    {
        for (int j = 0; j < COLUMNAS; j++)
        {
            printf("%d ",numeros[i][j]);
        }
        putchar('\n');
    }
    return 0;
}
