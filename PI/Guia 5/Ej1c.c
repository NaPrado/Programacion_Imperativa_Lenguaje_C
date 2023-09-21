#include <stdio.h>
 	
int letra; 
void segundo ( void );


int
main( void )
{	
printf( "Ingrese un carácter : "); 
letra = getchar();
      segundo();
      printf( " letra es : %c\n", letra );
            return 0;
}


void 
segundo( void )
{	
int letra; 
 	letra = 'X';
 	return;
}