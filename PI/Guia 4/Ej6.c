#define MAXIMO2(x,y,z) ((z)=((x) >= (y) ? (x) : (y)))
#define MAXIMO3(j,w,q,t) (MAXIMO2(j,w,j), MAXIMO2(w,q,w),t = (j >= w  ? j : w))
#include<stdio.h>
#include"../Librerias/getnum.h"
int main(void)
{
    int j=getint("ingrese primer numero "),w=getint("\ningrese segundo numero "),q=getint("\ningrese tercer numero "),t;
    MAXIMO3(j,w,q,t);
    printf("\nEl mas grande es %d\n",t);
    return 0;
}
