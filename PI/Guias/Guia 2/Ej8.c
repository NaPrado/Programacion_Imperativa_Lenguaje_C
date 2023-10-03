#include"../Librerias/getnum.h"
#include<stdio.h>
int main(void)
{
    float num;
    num = getfloat("pasame el numerito querido: ");
    num = num * 3.6;
    printf("\n%fm/s", num);
    return 0;
}
