/* Biblioteca para obtener el promedio de 3 enteros */

#include "tp4_15b.h"

int 
fAuxiliar3 (int n, int m, int p)
{
	return n + m + p;
}

float
promedio3 (int n, int m, int p)
{
	return fAuxiliar3(n,m,p) / 3.0;
}
