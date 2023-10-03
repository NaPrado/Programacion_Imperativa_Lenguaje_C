/*Problema del else colgante. Determine la salida estándar  para cada uno de los siguientes casos, 
cuando x = 9 e y = 11. Advierta que el compilador ignora las indentaciones.  
El compilador siempre asocia un else con el if anterior, a menos que se le indique lo contrario con llaves {}. 
A primera vista el programador tal vez no esté seguro de cuál if coincide con cuál else, 
ésto se conoce como el problema del "else colgante".  
Se eliminaron las sangrías para hacer el problema un poco más 'interesante'. 

Determinar la salida primero haciendo el seguimiento y luego comprobándola con la PC.

a)	if (x < 10)
	if (y > 10)
	printf("#######\n");
	else
	printf("%%%%%\n");
	printf("********\n");

b)	if (x < 10) {
	if (y > 10)
	printf("########\n");
	}
	else {
	printf("%%%%%\n");
	printf("********\n”);
	}*/
#include <stdio.h>
int main(void)
{
    if (x < 10) 
	if (y > 10)
	printf("#######\n");
	else
	printf("%%%%%\n");
	printf("********\n");
    return 0;
}
