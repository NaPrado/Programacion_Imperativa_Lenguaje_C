#include<stdio.h>
#include"../Librerias/getnum.h"
int main(void)
{
    int lado;
    do
    {
        lado = getint("Ingrese el valor de un lado del cuadrado: ");
    } while (lado <= 0);
       for (int ancho = 0, alto = 0; (ancho <= lado) && (alto < lado); ancho++)
       {
        if (ancho == lado)
        {
            printf("\n");
            alto++;
            ancho = -1;

        }
        else
        {
            printf("*");
        }
       }
    return 0;
}
