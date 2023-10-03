#define ISDIGIT(c) ((c >= '0')&&(c<= '9'))
#include<stdio.h>
int main(void)
{
    int letra;
	letra = getchar();
	if ( ISDIGIT(letra) )
		printf("Es un dígito\n");
    return 0;
}
