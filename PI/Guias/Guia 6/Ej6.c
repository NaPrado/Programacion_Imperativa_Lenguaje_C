#include "../Librerias/random/random.h"
#include <stdio.h>
#include <time.h>

void
elRandomInador(int vecOrd[],int vecDim){
    int randNum, aux;
    for (int i = 0; i < vecDim; i++){
            randNum=randInt(0,vecDim-1);
            aux = vecOrd[i];
            vecOrd[i] = vecOrd[randNum];
            vecOrd[randNum] = aux; 
    }
}

int main(void)
{
    srand((int) time(NULL));
    int v[]={0,1,2,3,4,5,6,7,8,9};
    elRandomInador(v,10);
    for (int i = 0; i < 10; i++)
    {
        printf("%d\n",v[i]);
    }
    
    return 0;
}
