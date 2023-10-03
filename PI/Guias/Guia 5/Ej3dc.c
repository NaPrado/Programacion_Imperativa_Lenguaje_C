#include <stdio.h>
#include "../Librerias/getnum.h"
#include <math.h>

int lugar (int num, int pos);
int CantDigit(int num);

int
main( void )
{
	int boleto = getint("Ingrese un número: "), esCapicua=1;
	int  j, Digitos = CantDigit(boleto),top = Digitos/2;
	
	
	for (j=1; j<=top; j++)
		if ( lugar(boleto, j) != lugar(boleto,Digitos-j+1))
		{	
 			esCapicua=0;
			continue;
		}
	printf("El boleto %ses capicúa\n",(esCapicua)? "":"no ");
    return(esCapicua);
}


int 
lugar( int num, int pos )
{	
return (num / (int)pow(10, pos-1)) % 10;
}

int
CantDigit(int num)
{
	int i= 0;
	do
	{
		i++;
		num /= 10;
	} while (num > 0 );
	return i;
}