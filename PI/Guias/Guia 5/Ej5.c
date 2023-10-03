#include <stdio.h>
#include <stdlib.h>
double power(double base, int exponente){
    double resultado = 1; 
    for (int i = 0; i < abs(exponente); i++){
        resultado = resultado * base ; }
    return resultado;}
double potencia(double base, int exponente){
    if (exponente > 0){
        return (power(base, exponente));}
    else if (exponente < 0){
        return (1/(power(base, exponente)));}
    else if (exponente != 0 && base == 0){
        return 0;}
    else if (exponente == 0 && base != 0){
        return 1;}
    else{// 0^0
        return -1;}}
int main(void){
    printf("%f\n",potencia(2,-4));
    return 0;}