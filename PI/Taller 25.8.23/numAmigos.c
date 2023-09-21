#include <stdio.h>
#include <math.h>
#include "../Librerias/getnum.h"
int
sumdiv(int num1){
    int amigo = 0;
    for (int i = 1; i <= num1/2; i++)
    {
        if (( (num1) % i) == 0)
        {
            amigo += i;
        }
    }
    return amigo;
}
int
numerosAmigos(int num1, int num2){
    return ((((num2) == sumdiv(num1)))&&((num1) == sumdiv(num2)));
}
int main(void)
{
    int c = getint(""), d = getint("");
    numerosAmigos(c,d)?printf("son amigos\n"):printf("no son amigos\n");
    return 0;
}