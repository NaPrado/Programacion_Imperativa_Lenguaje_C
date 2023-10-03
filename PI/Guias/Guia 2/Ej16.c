#include<stdio.h>
#include"../Librerias/getnum.h"
int main(void)
{
    /* Leer dos caracteres seguidos de la entrada estándar e imprimir en la salida estándar si son iguales,
    si el primero es mayor o si el primero es menor, utilizando operadores condicionales:
    a)  desde teclado, hacia pantalla
    b)  redireccionando la entrada desde archivo, hacia pantalla
	c)  desde teclado, redireccionando la salida a  un archivo
	d)  redireccionando la entrada y la salida con archivos

    Ejemplo:   
 	    Si se ingresaran los caracteres  'a'  y  'g'  
        se debería  imprimir  El caracter 'a' es menor al caracter 'g'*/
    int c1 = getchar();
    int c2 = getchar();
    c1 == c2 ? printf("son iguales\n"): (c1 > c2 ? printf("%c es mayor que %c\n", c1, c2) : printf("%c es menor que %c\n", c1, c2)); 
    return 0;
}
