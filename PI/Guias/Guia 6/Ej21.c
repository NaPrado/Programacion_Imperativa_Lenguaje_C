#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "../Librerias/getnum.h"
int DivisorComunMaximo(int a, int b){
    int mcd = 1;
    a = abs(a);
    b = abs(b);
    for (int i = 2; (a >= i) && (b >= i);)
    {
        if (a == 0||b == 0)
        {
            return 0;
        }
        if ((a%i==0)&&(b%i==0) ){
            mcd = mcd * i;
            a /= i;
            b /= i;
        }
        else{
            i++;
        }
    }
    return mcd;
}

int fracctions(int numera,int denom){
    int mcd =DivisorComunMaximo(denom,numera);
    if ((denom > 0 && numera < 0)||(denom < 0 && numera > 0)){
        numera = -abs(numera);
        denom = abs(denom);
    }
    numera /= mcd;
    denom /= mcd;
    printf("La fraccion simplificada es ");
    if(numera == 1){
        printf("%d\n\n", numera);
    }
    else{
    printf("%d/%d\n\n", numera, denom);
    }
    return 0;
}
int sum(){
    int numera1 = getint("Ingrese el primer numerador \n");
    int denom1 = getint("Ingrese el primer denominador \n");
    int numera2 = getint("Ingrese el segundo numerador \n");
    int denom2 = getint("Ingrese el segundo denominador \n");
    int numera = numera1 * denom2 + numera2 * denom1;
    int denom = denom1 * denom2;
    fracctions(numera,denom);
    return 0;
}

int menu(void){
    int NumeroIncorrecto = 1;
    while (NumeroIncorrecto)
    {
        printf("Seleccione una opcion: \n   1. Simplificar una fracción\n   2. Sumar dos fracciones\n   3. Terminar la ejecución\n");
        switch (getint("Ingrese un numero del 1 al 3: \n"))
        {
        case 1:
            NumeroIncorrecto = 1;
            int numera = getint("Ingrese el numerador: ");
            int denom = getint("Ingrese el denominador: "); 
            fracctions(numera,denom);
            break;
        case 2:
            NumeroIncorrecto = 1; 
            sum();
            break;
        case 3:
            printf("El programa finaliza.\n");
            return 0;
            break;
        default:
            printf("Se ingreso un numero no valido\n");
            NumeroIncorrecto = 0; 
            break;
    }
    }
}

int main(void)
{
    menu();
    return 0;
}