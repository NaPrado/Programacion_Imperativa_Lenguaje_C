#include <stdio.h>
#include "../Librerias/getnum.h"

int main(void)
{
    int n;
    int n2 = 0;
    int aux;

    do
    {
        n = getint("Ingrese un número (sin ceros a la izquierda):");
    } while (n < 0);

    aux = n;

    while (aux > 0)
    {
        n2 = n2 * 10 + (aux % 10);
        aux /= 10;
    }

    printf("\nEl número %ses capicúa\n", (n2 == n) ? "" : "no ");

    return 0;
}
/*La idea es recrear un numero digito a digito pero al revez y confirmar que son iguales*/