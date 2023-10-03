#include<stdio.h>
#include"../Librerias/getnum.h"
#define sueldo (int)300
#define RANGOVENTA0 (int)0
#define RANGOVENTA1 (int)1000
#define RANGOVENTA2 (int)2000
#define RANGOVENTA3 (int)4000
#define PORCENTAJE1 (double)0.05
#define PORCENTAJE2 (double)0.07
#define PORCENTAJE3 (double)0.09
int venta, comision;
double total = sueldo;
int main(void){
    do{
        venta = getint("Ingrese monto de las ventas semanales: ");
        if (venta > RANGOVENTA1 && venta < RANGOVENTA2){
            total += (PORCENTAJE1 * venta);}
        else if (venta > RANGOVENTA2 && venta < RANGOVENTA3){
            total += (PORCENTAJE2 * venta);}
        else if (venta > RANGOVENTA3 && venta > RANGOVENTA3){
            total += (PORCENTAJE3 * venta);}
        else if (venta == RANGOVENTA0){
            break;}
        else{
            puts("Ingrese un valor valido");}
    } while (venta < 0);
    printf("El personal de ventas debe ganar $%.2f\n",total);
    return 0;}






/*Una empresa paga a su personal de venta en base a comisiones.  
El personal de ventas recibe $300 por semana más un porcentaje de las ventas brutas de esa semana.  
El porcentaje a aplicar depende del total vendido: si la venta no supera los $1000, 
no hay porcentaje, hasta $2000 es un 5%, hasta $4000 es un 7%, y más de $4000 es un 9%. 

Por ejemplo, un vendedor que vende $5000 en una semana, recibe $300 más 9% de $5000, o sea un total de $750.  
Hacer un programa en C que lea una única variable que indique la suma vendida en una semana, 
e imprima por salida estándar  el monto total a cobrar. 
Si la suma vendida es un valor incorrecto pedir un nuevo valor. (En no más de 15 líneas).*/