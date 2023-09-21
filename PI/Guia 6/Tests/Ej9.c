#include <stdio.h>
#include <assert.h>

/* Calcula la desviacion estandar */
double desv(const char vector[], int cantnum );


  int main(void) {
  //double d;
  unsigned char arreglo2[] = { 0x33, 0x33, 0x33, 0x33, 0x33 };
  for(int i=0; i <= 10; i++)
    //printf("%f\n",desv(arreglo2, i));
    assert(desv(arreglo2, i)<1e-2);
  

   unsigned char arreglo[] = { 0x37, 0xF2, 0x03, 0x4A, 0xFF };
  assert(desv(arreglo, 1)==0);
  assert(desv(arreglo, 2)<1e-2+2.0);

  assert(desv(arreglo, 3) > 4.98-1e-2 && desv(arreglo, 3) < 4.99-1e-2);

  assert(desv(arreglo, 10) > 5.6071+1e-2 && desv(arreglo, 3) < 5.6072+1e-2); 

  puts("OK!");
} 
