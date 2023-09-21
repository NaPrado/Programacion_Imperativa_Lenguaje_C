#include"../Librerias/getnum.h"
#include<stdio.h>
int num1, num2, num3, pnum1, pnum2, maxnum;
int main(void)
{
    num1 = getint("ingrese num1: ");
    num2 = getint("ingrese num2: ");
    num3 = getint("ingrese num3: ");
    pnum1 = num1 > num2 ? num1:num2;
    pnum2 = num2 > num3 ? num2:num3;
    maxnum = pnum1 > pnum2 ? pnum1:pnum2;
    printf("El numero mas grande es : %d \n", maxnum);
    return 0;
}
 