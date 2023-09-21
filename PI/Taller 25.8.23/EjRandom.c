#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "../Librerias/random/random.h"
int
lee(int N,int L){
    int c,cantletras = 0;
    for (int i = 0;(((c = getchar()) != EOF) || i <= N); i++)
    {
        if (L == c || tolower(L) == c)
        {
            cantletras++;
        }
    }
    return cantletras;
}

int main(void)
{
    randomize();
    int letraR = randInt('A', 'Z');
    int numR = randInt(1,256);
    int cant = lee(numR,letraR);
    printf("cantidad de apariciones de %c (hasta %d simbolos): %d\n", letraR,numR,cant);
    return 0;
}



