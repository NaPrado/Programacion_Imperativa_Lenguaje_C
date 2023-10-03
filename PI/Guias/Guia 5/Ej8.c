#include <stdio.h>        
#include <math.h>       
#include <errno.h>        
#include "../Librerias/getnum.h"
double
redondeo(double x, double y){
    y=pow(10,y);
    return(floor(x*y)/y);
}
int
menu(void){
    int flag = 1;
    while (flag){
        printf("Que funcion desea usar:\n    1. Redondeo al entero más cercano.\n    2. Redondeo a la décima más cercana.\n    3. Redondeo a la centésima más cercana.\n    4. Redondeo a la milésima más cercana\n");
        int i = getint("Seleccione una opcion (ingresando un numero del 1 al 4): ");
        switch (i){
        case 1:
            
            printf("Redondeo al entero más cercano %.0f\n", (redondeo(getdouble("Ingrese numero a redondear: "),0)));
            flag = 0;
            break;
        case 2:
            printf("Redondeo a la décima más cercana %.1f\n", (redondeo(getdouble("Ingrese numero a redondear: "),1)));
            flag = 0;
            break;
        case 3:
            printf("Redondeo a la centésima más cercana %.2f\n", (redondeo(getdouble("Ingrese numero a redondear: "),2)));
            flag = 0;
            break;
        case 4:
            printf("Redondeo a la milésima más cercana %.3f\n", (redondeo(getdouble("Ingrese numero a redondear: "),3)));
            flag = 0;
            break;
        default:
            printf("se ingreso un valor incorrecto\n");
            break;
            return 0;}}}

int main(int argc, char const *argv[])
{
    menu();
    return 0;
}
