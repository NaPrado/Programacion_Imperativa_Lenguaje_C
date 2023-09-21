#include <stdio.h>
#include <math.h>
#include "../Librerias/getnum.h"
#define ES 1
int esPrimo(int num){
    if(num < 0)
        num = num*(-1);
    int rta = ES;
    if(num <2)
        rta = !rta;
    int div = 2;
    while (div <= sqrt(num)&& rta)
    {
        if(num%div == 0)
            rta = !rta;
        div++;
    }
    return rta;
}
int
nprimo(int n){
    for (int i = 0, contador = 0; contador < n; i++)
    {
        if (esPrimo(i))
        {
            printf("%d, ",i);
            contador++;
        }
    }
    printf("\n");
    return 0;
}
int main(void)
{
    int c = getint("");
    nprimo(c);
    return 0;
}
