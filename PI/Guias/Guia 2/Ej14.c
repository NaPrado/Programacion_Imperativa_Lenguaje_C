#include<stdio.h>
#include"../Librerias/getnum.h"
int main(void)
{
    /* Escribir un programa que lea dos enteros y a continuación imprima el promedio, 
    la suma, el menor y el mayor de ellos (o indicar que son iguales). 
    Usar el operador condicional. */
    int num1 = getint("Ingrese el primer numero: \n");
    int num2 = getint("Ingrese el segundo numero: \n");
    int suma = num1 + num2;
    float promedio = suma/2.0;
    int menor = (num1 < num2 ? num1 : num2);
    int mayor = (num1 > num2 ? num1 : num2);
    printf("El promedio es %.1f \nLa suma es %d \n", promedio, suma);
    num1 == num2 ? printf("Son Iguales\n"):printf("El menor es %d \nEl mayor es %d \nNo son iguales\n", menor, mayor);
    return 0;
}
