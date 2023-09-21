#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "../Librerias/getnum.h"
#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
#define EPSILON 10e-15
double
func(double j){
    //ingresar funciones aqui
    return (pow(j,0.5)+exp(j));}
double ceros(double a, double b){
    double A = MAX(a,b), B = MIN(a,b);
    int Q = 0;
    for (double j = B,i = (func(j)),last = i, lastj = j; j < A; j+= 0.001){
        double i = (func(j));
        //printf("%f\t%f\n",i, last);
        if (((i-0)< EPSILON)&&((0-i)<EPSILON)) {
            Q++;
            printf("Existe un  cero en %f\n", i);}
        else if (((last < 0)&&(i > 0))||((last > 0)&&(i < 0))){
            Q++;
            double SMALL = MIN(lastj, j);
            double BIG = MAX(lastj, j);
            printf("Existe un cero en el intervalo ( %f , %f )\n",SMALL,BIG);}
        last = i;
        lastj = j;}
        if (Q != 0){
            printf("No se encontraron mas ceros en el intervalo ( %f , %f )\n",B,A);}
        else if (Q == 0){
            printf("No se encontro ningun cero en el intervalo ( %f , %f )\n",B,A);}
    return 0;}
int main(void){
    double a = getdouble("Ingrese el primer valor del intervalo: \n"), b = getdouble("Ingrese el segundo valor del intervalo: \n");
    ceros(a,b);
    return 0;}
