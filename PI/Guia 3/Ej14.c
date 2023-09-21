/*Leer desde la entrada estándar una serie de caracteres, hasta que uno de ellos no sea una letra ni un espacio.  
Luego imprimir por salida estándar  el menor alfabéticamente de ellos  respetando si fue mayúscula o minúscula, 
indicando además cuántas letras eran mayúsculas y cuántas minúsculas. No considerar el carácter ‘ñ’ como letra. 
(En no más de 15 líneas).

	Ejemplo: si se ingresa "Aqui murio Solis" debe imprimir la letra "A"
		   si se ingresa "Hola mundo" debe imprimir la letra "a"*/
#include<stdio.h>
int main(void)
{
    int letra, anterior = 'z', min = 0, mayus = 0, menor;
    while (((letra=getchar()) >= 'a' && letra <= 'z') || (letra >= 'A' && letra <= 'Z') || (letra == ' ' ))
    {
        if (letra >= 'a' && letra <= 'z')
        {
            min++;
            if ((letra - ('a') + 'A') <= anterior)
            {
                menor = letra;
                anterior = letra - ('a') + 'A';
            }
        }
        else if (letra >= 'A' && letra <= 'Z')
        {
            mayus++;
            if (letra <= anterior)
            {
                menor = letra;
                anterior = letra;
            }
        }
    }
    printf("El menor es el caracter %c\nHay %d minusculas y %d mayusculas\n",menor,min,mayus);
    return 0;
}
