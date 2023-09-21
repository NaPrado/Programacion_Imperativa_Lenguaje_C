#include<stdio.h>
#include"../Librerias/getnum.h"
int main(void)
{
    int num,fact= 1;
    do
    {
        num = getint("te doy un factorial?  ");
        if (num < 0 )
        {
            printf("Num positivo plissssss");
        }
    } while ( num < 0 );
    for (int i=1 ; i <= num; i++)
    {
        fact = fact*i;
    }
    printf("%d\n",fact);
    return 0;
}
