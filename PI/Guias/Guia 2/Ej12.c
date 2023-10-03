#include<stdio.h>
#include"../Librerias/getnum.h"
int main(void)
{
    /*Leer un carácter desde la entrada estándar e imprimir en la salida estándar si el mismo es una letra  o no. 
    Considerar que el conjunto de caracteres es el del lenguaje inglés, o sea ignorar la ñ  y vocales acentuadas. 
    Usar el operador condicional.*/
    char caracter = getchar();
    (caracter < 'A'|(caracter > 'Z' && caracter < 'a')| caracter > 'z') ? printf("No es una letra\n") : printf("Es una letra\n");
    return 0;
}
