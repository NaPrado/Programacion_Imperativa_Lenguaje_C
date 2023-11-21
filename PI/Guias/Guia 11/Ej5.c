#include "Ej5.h"

typedef struct complejoCDT
{
    double real;
    double imaginario;
}complejoCDT;

complejoADT
nuevoComp(double real, double imaginario){
    complejoADT nuevo= malloc(sizeof(complejoCDT));
    nuevo->real=real;
    nuevo->imaginario=imaginario;
    return nuevo;
}

complejoADT 
conjugadoComp(complejoADT A){
    A->imaginario=(A->imaginario)*-1;
    return A;
}

double
parteRealComp(complejoADT A){
    return A->real;
}

double 
parteImagComp(complejoADT A){
    return A->imaginario;
}

complejoADT 
sumaComp(complejoADT A,complejoADT B){
    complejoADT aux=malloc(sizeof(complejoCDT));
    aux->real=A->real+B->real;
    aux->imaginario=A->imaginario+B->imaginario;
    return aux;
}

complejoADT
restaComp( complejoADT A, complejoADT B){
    complejoADT aux=malloc(sizeof(complejoCDT));
    aux->real=A->real-B->real;
    aux->imaginario=A->imaginario-B->imaginario;
    return aux;
}

complejoADT 
multiplicaComp(complejoADT A,complejoADT B){
    complejoADT aux= malloc(sizeof(complejoCDT));
    aux->real=((A->real*B->real)+(A->imaginario*B->imaginario));
    aux->imaginario=((A->real*B->imaginario)+(A->imaginario*B->real));
    return aux;
}

complejoADT 
divideComp(complejoADT A,complejoADT B){
    complejoADT aux=malloc(sizeof(complejoCDT));
    aux->real=((A->real*B->real)+(A->imaginario*B->imaginario))/((B->real*B->real)+(B->imaginario*B->imaginario));
    aux->imaginario=((A->imaginario*B->real)-(A->real*B->imaginario))/((B->real*B->real)+(B->imaginario*B->imaginario));
    return aux;
}

void
liberaComp(complejoADT A){
    free(A);
    return;
}