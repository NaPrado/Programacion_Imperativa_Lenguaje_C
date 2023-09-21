#include <stdio.h>
#include <assert.h>

#define DIMMAX 4
int
suma(const int m1[DIMMAX][DIMMAX],const int m2[DIMMAX][DIMMAX], int f, int c, int dim){
    int sum=0;
    for (int i = 0; i < dim; i++){
        sum += (m1[f][i]*m2[i][c]);
    }
    return sum;
}

void
productoMat( const int m1[DIMMAX][DIMMAX], const int m2[DIMMAX][DIMMAX], int m3[DIMMAX][DIMMAX], int dim){
    for (int c=0 ; c<dim ; c++){
        for (int k = 0 ; k<dim ; k++){
            m3[c][k]=suma(m1,m2,c,k,dim);
        }
    }
}

/* 

int main(void)
{
    const int m1[DIMMAX][DIMMAX] = {
      { 1, 2, 3, 4},
      {11,12,13,14},
      {21,22,23,24},
      {31,32,33,34},
      };

    const int m2[DIMMAX][DIMMAX] = {
      { 2, 1, 3, 4},
      { 3, 4, 5, 2},
      { 2, 5,10,11},
      {21,12,13,14},
      };
    
    int m3[DIMMAX][DIMMAX];
    productoMat(m1,m2,m3, DIMMAX);
    for (int i=0;i<DIMMAX;i++)
    {
    for(int j=0;j<DIMMAX;j++)
    {
    printf("%d " ,m3[i][j]);
    }
    printf("\n");
    }

    return 0;
}
 */