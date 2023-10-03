#include<stdio.h>
int edad = 25;
float longitud = 185.654;
char  letra = 'Z';
int main(void)
{
    /*imprimir en la salida estándar:
    a)  la variable edad, encolumnada a izquierda, en un ancho de campo de 5 espacios.
    b)  la variable edad, encolumnada a derecha, en un ancho de campo de 10 espacios.
    c) la variable longitud, encolumnada a la izquierda en un ancho de campo de 10 espacios, con 2 dígitos decimales.
    d)  la variable letra, como número entero, en un ancho de campo de 8 espacios.*/
    printf("%-5d*\n",edad);
    printf("%10d*\n", edad);
    printf("%-10.2f*\n",longitud);
    printf("%8d*\n",letra);
    return 0;
}
