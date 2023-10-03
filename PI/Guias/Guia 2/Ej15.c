#include<stdio.h>
#include"../Librerias/getnum.h"
int main(void)
{
    /* Leer un carácter e imprimirlo en mayúscula. 
    Considerar que el conjunto de caracteres es el del lenguaje inglés, o sea ignorar la ñ  y vocales acentuadas. 
    (Usar operador condicional). */
    int caracter = getchar();
    int mayus = caracter - ('a'-'A');
    ((caracter < 'a') | (caracter > 'z')) ? printf( "%c\n", caracter ): printf( "%c\n", mayus );
    return 0;
}
