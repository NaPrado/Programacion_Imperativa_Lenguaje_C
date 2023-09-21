#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define CERO '0'
#define VOCALm(a) (a=='a' && a=='e' && a=='i' && a=='o' && a=='u')
#define VOCALM(a) (a=='A' && a=='E' && a=='I' && a=='O' && a=='U')
#define VOCAL(a) (VOCALM(a)&&VOCALm(a))
int main(void)
{
    int a, b, c;
    a = getchar();
    b = getchar();
    c = getchar();


    if (isalpha(a)&&!islower(a))
    	printf("El caracter %c es una consonante mayúscula \n", a);
    else 
    if (islower(a)&& !VOCALm(a))
    		printf("El caracter %c es una consonante minúscula \n", a);
    else 
     		if (VOCAL(a))
    			printf("El caracter %c es una vocal \n", a);
    		else
    			printf("El caracter %c no es una letra \n", a);


    if ( b%2 == 0)
    printf("El valor ASCII de %c es par \n", b);
	
    if ( isdigit(b) && (b-CERO)%2 == 0 )
    printf("El caracter %c representa un dígito par \n", b);
	
    if ( isalpha(c)&&(!islower(c)||(VOCAL(c))) )
    printf("El caracter %c es una vocal o es mayúscula \n", c);
	
    if ( isalpha(c)&& !VOCAL(c))
    printf("El caracter %c no es una vocal pero es letra \n", c);
    return 0;
}

