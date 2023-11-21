#include <stdio.h>
#include <stdlib.h>
#include "../../../Librerias/getnum.h"
  
#define TOTAL_ITEMS 2
#define MAX_LONG 10
 
typedef struct {
    int codigo;
    char desc[MAX_LONG];
    float precio;
} tItem;
 
typedef tItem tFactura[TOTAL_ITEMS];

int getline(char s[], int lim) {
    int c,i;
    i = 0;
    while(--lim > 0 && (c = getchar()) != EOF && c !='\n')
        s[i++] = c;
    if (c == '\n')
        s[i++] = c;
    s[i] = '\0';
    return i;
}

tItem leerItem(){
    tItem item;
    item.codigo=getint("Ingrese codigo: ");
    while (item.codigo<=0)
        item.codigo=getint("Ingrese codigo: ");
    item.precio =getfloat("Ingrese precio ");
    fgets()
}
 
void cargar(tFactura fact, int cant){

}
float importe(tFactura fact, int cant);



int
main(void) {
    tFactura f;
    cargar(f, TOTAL_ITEMS);
    printf("%.2f", importe(f, TOTAL_ITEMS));
    return 0;
}

