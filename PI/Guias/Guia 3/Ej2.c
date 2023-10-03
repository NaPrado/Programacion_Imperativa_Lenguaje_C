#include<stdio.h>
int main()
{
    char caracter1 = getchar();
    char caracter2 = getchar();
    if (caracter1 > caracter2)
    {
        printf("El caracter '%c' es mayor al caracter '%c'.\n", caracter1, caracter2);
    }
    else if (caracter1 < caracter2)
    {
        printf("El caracter '%c' es menor al caracter '%c'.\n", caracter1, caracter2);
    }
    else
    {
        printf("Los caracteres son iguales.\n");
    }
    return 0;
}





/*Leer dos caracteres desde la entrada estándar  e imprimir por salida estándar  si son iguales, 
si el primero es mayor o si el primero es menor, teniendo en cuenta su valor ASCII. 
(En no más de 15 líneas).
Ejemplo: si se ingresa 'a', 'g', debe imprimir  El caracter 'a' es menor al caracter 'g'.
*/