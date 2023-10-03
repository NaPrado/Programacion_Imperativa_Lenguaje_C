#include<stdio.h>
#include"../Librerias/getnum.h"
int main(void)
{
    int lado;
    do
    {
        lado = getint("Ingrese el valor de un lado del cuadrado: ");
    } while (lado <= 0);
       for (int I = 1; (I <= lado*lado); I++)
       {
        putchar('*');
        if (I % lado == 0)
        {
            putchar('\n');
        }
       }
    return 0;
}
