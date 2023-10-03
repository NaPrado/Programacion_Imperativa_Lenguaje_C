/*Dado un entero que representa un número binario positivo (todos sus dígitos son cero o uno), 
imprimir por salida estándar  el equivalente decimal. (En no más de 10 líneas)*/
#include <stdio.h>
#include "../Librerias/getnum.h"


/* Solo se consideran binarios positivos */
int
main(void)
{
	int binario;
	int decimal=0;
	int base=1;
	int resto;


	binario = getint("Ingrese un número binario (hasta 10 digitos):");


	for (base = 1; binario > 0;  binario /=10, base *=2)
	{
		if ( (resto = binario % 10) > 1 ) 
		{
			printf("\nNo es un número binario !!!\n");
			return 1;
		}
		else if (resto) 
			decimal += base;
	}
	printf("\nEquivalente decimal = %d\n",decimal);


	return 0;
}
