#include <stdlib.h>

typedef struct complejoCDT * complejoADT;

//crea un nuevo numero complejo
complejoADT nuevoComp(double real,double imaginario);

//devuelve el complejo conjugado
complejoADT conjugadoComp(complejoADT A);

//devuelve la parte real del complejo
double parteRealComp(complejoADT A);

//devuelve la parte imaginaria del complejo
double parteImagComp(complejoADT A);

//suma 2 numeros complejos A+B
complejoADT sumaComp(complejoADT A,complejoADT B);

//resta 2 numeros complejos A-B
complejoADT restaComp( complejoADT A, complejoADT B);

//multiplica 2 complejos
complejoADT multiplicaComp(complejoADT A,complejoADT B);

//divide A/B siendo A,B numeros complejos
complejoADT divideComp(complejoADT A,complejoADT B);

// hace free del complejo
void liberaComp(complejoADT A);


