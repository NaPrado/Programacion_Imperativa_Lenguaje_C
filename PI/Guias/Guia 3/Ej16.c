#include<stdio.h>
#include"../Librerias/getnum.h"
int main(void)
{
    int decimal, save = 0;
    decimal = getint("Ingrese un numero decimal: ");
    for (int base = 1; decimal >= 1 ; base = base * 10 )
    { 
            save = save + base * (decimal % 2);
            decimal = (decimal)/2;
    }
    printf("%d\n", save);
    return 0;
}