#include<stdio.h>
#include"../Librerias/getnum.h"
int main()
{
    /* Escribir un programa que lea dos enteros, e imprima si el segundo es múltiplo del primero.
    Usar el operador condicional.
    */
   int num1 = getint("Pasame el primer numero pibe: \n");
   int num2 = getint("Pasame el segundo querido: \n");
   ((num1 % num2) == 0) ? printf("El segundo es multiplo del primero\n") : printf("El segundo NOOOOOOOOOOOOOOOOOOOOOOO es multiplo del primero\n");
   return 0;
}
