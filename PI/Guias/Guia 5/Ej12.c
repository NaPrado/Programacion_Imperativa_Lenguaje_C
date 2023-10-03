#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "../Librerias/getnum.h"
int main(void)
{
    int n,c;


    /* al salir del ciclo n debe ser un número par mayor que cero */
    do
	n = getint("hola\n");
    while(!(n == abs(n) && n%2 == 0));


		
    /* este ciclo debe incluir la lectura de caracteres y debe ejecutarse  
    * mientras no sea fin de archivo y los caracteres sean  dígitos o minúsculas
    */
    while ((c=getchar())!=EOF&&(isdigit(c)||islower(c))){
 	    putchar(c);
    }
    return 0;
}
