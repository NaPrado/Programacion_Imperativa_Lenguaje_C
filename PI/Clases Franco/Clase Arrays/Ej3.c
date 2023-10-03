#include <stdio.h>
#include <ctype.h>
#define TOPE	5

void 
encripta( char letra )
{
   /* Esta tabla indica el ASCII a devolver para cada letra mayuscula  */
   static char transforma[26] =  { '#', '!', '?', '&', '.', '/', '{', ']', 
			'(', '=', '[', '}', ')', 'c', 'e', 'w', 'j', 'x', 'a', 
			'i', 'm', 'o', 'y', 'h', '\\', '<'  };
   letra = toupper(letra);
   if ( isalpha(letra) )
      letra= transforma[letra - 'A' ];
   putchar(letra);
}

int
main( void )
{
   char mensaje[TOPE];
   int dimension = 0;
   int leido, rec;

   while ( dimension < TOPE && ( leido = getchar() ) != EOF )
      mensaje[dimension++]= leido;

   /* ... */

   for ( rec=0 ; rec<dimension ; rec++)
      encripta( mensaje[ rec ] );

   /* etc */
   
   return 0;
}