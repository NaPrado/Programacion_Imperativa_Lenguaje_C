#define N 4
#define M 5
#include <math.h>

int armaFilas(int m[][M], int vec[]){
    int value=0, c=0;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M && value!=-1; j++)
        {
            if (m[i][j]<10 && m[i][j]>=0){
                value+=m[i][j]*pow(10,(M-1)-j);
            }
            else
                value =-1;
        }
        if (value!=-1)
            vec[c++]=value;
        value=0;
    }
    return c;
}