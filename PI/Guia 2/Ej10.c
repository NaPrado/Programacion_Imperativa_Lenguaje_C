#include<stdio.h>
#include"../Librerias/getnum.h"
int main(void)
{
    /* Escribir un programa que lea una variable entera que representa un intervalo de tiempo expresado en segundos. 
    Realizar la conversión para imprimir en la salida estándar el equivalente en horas, minutos y segundos. 
    No utilizar variables auxiliares. */
    int n;
    n = getint("paasssssaaasasasasadasjkasjdkasdijadf: ");
    printf("Horas %d\nMinutos %d\nSegundos %d\n",n/3600,n/60,n);
    return 0;
}
