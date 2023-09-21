#include <stdio.h>
#define DELTA 0.0001
double mathfunction(double x){
    int  rta = 1;
    for (int i = 1,  exp = 1, fact = 1, anterior = 0; (rta-anterior) > DELTA; i++)
    {
        anterior = rta;
        exp *= x;
        fact *= i;
        rta += exp / fact;
    }
    return rta;
}

int main(int argc, char const *argv[])
{
    printf("\n%.4f",mathfunction(23.45));
    return 0;
}
