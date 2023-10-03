#include<stdio.h>
#include"../Librerias/getnum.h"
int main(void)
{
    /* 	Leer dos caracteres desde la entrada estándar e imprimir en la salida estándar el de mayor valor ASCII, 
    usando el operador condicional. 
    Redireccionar la entrada de manera tal que getchar  lea desde el archivo entrada.txt.  
    Dicho archivo será escrito con un editor de texto sin formato y deberá tener el siguiente contenido:

    a)   ABCD

    b)   A
          B
          C
          D

    c)   A	   B     (usando tabulador entre A y B)

    Indicar la salida generada en cada punto.

    */
   char letra1 = getchar();
   char letra2 = getchar();
   char maxl = letra1 > letra2 ? letra1 : letra2;
   printf("%c\n", maxl);
   return 0;
}
