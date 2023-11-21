#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "../../Librerias/getnum.h"

int
baseDiez(int num,int entrada){
    int c,num10=0;
    for (int i = 0; num ;)
    {
        c=num%10;
        num10+=c*(pow(entrada,i++));
        num/=10;
    }
    return num10;
}

int
baseNueva(int decimal, int base){
    int a=0;
    for (int i=0;decimal;i++){
        a+= pow(10,i)*(decimal%base);
        decimal/= base;
    }
    return a;  
}


int main()
{
    int entrada,salida,num,decimal;
    printf("Ingresar <base_entrada> base_salida ");
    scanf("< %d > %d",&entrada,&salida);
    printf("Ingresar numero en base %d ",entrada);
    num=getint("Ingrese numero a pasar: ");
    decimal=baseDiez(num,entrada);
    int resultado=baseNueva(decimal,salida);
    printf("%d\n",resultado);
    return 0;
}
