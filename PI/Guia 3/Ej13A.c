#include<stdio.h>
#include"../Librerias/getnum.h"
int main(void)
{
    int lado;
    do
    {
        lado = getint("Ingrese el valor de un lado del cuadrado: ");
    } while (lado <= 0);
       for (int alto = 0; alto < lado; alto++)
       {
        for (int ancho = 0; ancho < lado; ancho++)
        {
            printf("*");
        }
        printf("\n");
       }
       
    return 0;
}
