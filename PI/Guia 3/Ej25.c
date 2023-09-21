#include<stdio.h>
#include"../Librerias/getnum.h"
int main(void)
{
    int decimal, save = 0;
    decimal = getint("Ingrese un numero decimal: ");
    for (; decimal >= 1 ;)
    { 
        save = save +(decimal % 2);
        decimal = (decimal)/2;
    }
    printf("se tienen %d unos\n", save);
}