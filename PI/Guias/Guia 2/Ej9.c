#include<stdio.h>
#include"../Librerias/getnum.h"
int main(void)
{
    /* Leer un número entero positivo y escribir en la salida estándar el valor de dicho número dividido 2, 
    usando decalaje. */
    int entero, num;
    entero = getint("tirame un numerito maeeeeesssstrro: ");
    num = entero >> 1;
    printf("%d\n", num);
    return 0;
}
