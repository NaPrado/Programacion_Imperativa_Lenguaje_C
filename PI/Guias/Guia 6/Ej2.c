//Para la opción de simplificar una fracción, 
//la obtención del numerador y denominador pertenece al front-end. 
//Luego se invoca a una función de back-end que recibe esos parámetros y los modifica. 
//¿Cómo se puede hacer para que la función de back-end reciba ambos y los pueda modificar? 
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "../Librerias/getnum.h"
#define NUMERADOR 0
#define DENOMINADOR 1
#define DIMENSION 2

int
DivisorComunMaximo(int a, int b){
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

void
simpleFracs(int Fraccion[]){

    if ((Fraccion[NUMERADOR] > 0 && Fraccion[DENOMINADOR] < 0)||(Fraccion[NUMERADOR] < 0 && Fraccion[DENOMINADOR] > 0)){
        Fraccion[NUMERADOR] = -abs(Fraccion[NUMERADOR]);
        Fraccion[DENOMINADOR] = abs(Fraccion[DENOMINADOR]);
    }
    Fraccion[NUMERADOR] /= DivisorComunMaximo(Fraccion[NUMERADOR],Fraccion[DENOMINADOR]);
    Fraccion[DENOMINADOR] /= DivisorComunMaximo(Fraccion[NUMERADOR],Fraccion[DENOMINADOR]);
}
void
printar(int Fraccion[]){
    printf("La nueva fraccion es ");
    if(Fraccion[DENOMINADOR] == 1){
        printf("%d\n\n", Fraccion[NUMERADOR]);
    }
    else if (Fraccion[NUMERADOR] == 0)
    {
        printf("0\n\n");
    }
    
    else{
    printf("%d/%d\n\n", Fraccion[NUMERADOR], Fraccion[DENOMINADOR]);
    }
}
void
pedirDatos(int Fraccion[]){
        Fraccion[NUMERADOR] = getint("Ingrese un numerador: ");
        Fraccion[DENOMINADOR] = getint("Ingrese un denominador: "); 
}
void
sum(int fraccion1[],int fraccion2[]){
    fraccion1[NUMERADOR] = fraccion1[NUMERADOR] * fraccion2[DENOMINADOR] + fraccion2[NUMERADOR] * fraccion1[DENOMINADOR];
    fraccion1[DENOMINADOR] = fraccion1[DENOMINADOR] * fraccion2[DENOMINADOR];
}
int main(void)
{
    int fraccion1[DIMENSION]={0},fraccion2[DIMENSION]={0};
    int NumeroIncorrecto = 1;
    while (NumeroIncorrecto)
    {
        printf("Seleccione una opcion: \n   1. Simplificar una fracción\n   2. Sumar dos fracciones\n   3. Terminar la ejecución\n");
        switch (getint("Ingrese un numero del 1 al 3: \n"))
        {
        case 1:
            NumeroIncorrecto = 1;
            pedirDatos(fraccion1);
            simpleFracs(fraccion1);
            printar(fraccion1);
            break;
        case 2:
            NumeroIncorrecto = 1;
            pedirDatos(fraccion1);
            pedirDatos(fraccion2);
            sum(fraccion1, fraccion2);
            simpleFracs(fraccion1);
            printar(fraccion1);
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
    return 0;
}
