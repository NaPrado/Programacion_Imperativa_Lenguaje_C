#include<stdio.h>
int main(void)
{
    char caracter = getchar();
    if ( caracter >= 'A' && caracter <= 'Z' )
    {
        printf("El caracter ingresado es una letra mayuscula\n");
    }
    else if (caracter >= 'a' && caracter <= 'z')
    {
        printf("El caracter ingresado es una letra minuscula\n");
    }
    else
    {
        printf("El caracter ingresado no es una letra\n");
    }
    
    return 0;
}






/*Ejercicio 1
Leer un caracter desde la entrada estándar e imprimir por salida estándar si el caracter es una letra o no y, 
en caso de ser una letra, indicar si es letra mayúscula o minúscula, sin tener en cuenta el caracter ‘ñ’. 
(En no más de 15 líneas).
*/