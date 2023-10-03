#include <stdio.h>
#include "../Librerias/getnum.h"
#define delta ('a' -'A')
int
caracter(void){
    return getchar();
}
int f1(int caracter){
    if (caracter >= 'A' && caracter <= 'Z'){
        caracter = delta + caracter;
        printf("El caracter en minuscula es %c\n",caracter);}
    else if (caracter >= 'a' && caracter <= 'z'){
        printf("El caracter ya es una letra minuscula\n");}
    else{
        printf("El caracter no es una letra\n");}
    return 0;}
int f2(int caracter){
    if (caracter >= 'a' && caracter <= 'z'){
        caracter = caracter - delta;
        printf("El caracter en mayuscula es %c\n",caracter);}
    else if (caracter >= 'A' && caracter <= 'Z'){
        printf("El caracter ya es una letra mayuscula\n");}
    else{
        printf("El caracter no es una letra\n");}
    return 0;}
int f3(int caracter){
    caracter ++;
    printf("El siguiente caracter es %c\n",caracter);
    return 0;}
int f4(int caracter){
    if (caracter == 'Z'){
        printf("La siguiente letra en forma circular es A\n");}
    else if (caracter == 'z'){
        printf("La siguiente letra en forma circular es a\n");}
    else{
        caracter ++;
        printf("La siguiente letra en forma circular es %c\n", caracter);}
    return 0;}
int menu(void){
    int flag = 1;
    while (flag){
        printf("Que funcion desea usar:\n    1. Convertir de mayúscula a minúscula.\n    2. Convertir de minúscula a mayúscula.\n    3. Imprimir el carácter siguiente.\n    4. Imprimir la siguiente letra en forma circular\n");
        int opcion = getint("Seleccione una opcion (ingresando un numero del 1 al 4): ");
        printf("Por favor ingrese caracter: \n");
        switch (opcion){
        case 1:
            f1(caracter());
            flag = 0;
            break;
        case 2:
            f2(caracter());
            flag = 0;
            break;
        case 3:
            f3(caracter());
            flag = 0;
            break;
        case 4:
            f4(caracter());
            flag = 0;
            break;
        default:
            printf("se ingreso un valor incorrecto\n");
            break;
            return 0;}}}
int main(void)
{
    menu();
    return 0;
}
