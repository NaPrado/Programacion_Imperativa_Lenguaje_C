#include<stdio.h>
#include"../Librerias/getnum.h"
int main(void)
{
    
    int num = getint("Ingrese un numero: "), modulo1,modulo2,Base = 5,i=0;
    while (num >= Base)
    {
        if ((modulo1 = num%5 ) == 0 &&  (modulo2 = num%10) == 0)
        {
            num = num / 10;
        }
        else if ((modulo1 = num%5 ) == 0)
        {
            i++;
            num = num -5;
        }
        else
        num = num -(num%10);
    }
    printf("Se tienen %d digitos iguales a 5\n",i);
    return 0;
}


