#include <stdio.h>

unsigned int copiaSubVector(const char * arregloIn, char * arregloOut, unsigned int desde, unsigned int hasta, unsigned int dimMax){
    unsigned int i, dim=0;
    if (desde<0  ||  desde>hasta || dimMax<=0)
        return 0;
    for(i = 0; i < desde && arregloIn[i]; i++)
	   ;
	
    if ( i < desde )
		return 0;
	
	for ( ; dim < dimMax-1 && i <= hasta && arregloIn[i]!= 0; i++)
		arregloOut[dim++] = arregloIn[i];

	arregloOut[dim] = 0;

	return dim;	
}