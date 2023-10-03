//intersecta 2 vecs ordenados
int
interseccion(int const A[], int dimA, int const B[], int dimB, int r[]){
    int c=0;
    for (int i = 0,j=0; i < dimA && i < dimB ;){
        if (A[i]==B[j]){
           r[c++]=A[i];
            i++;
            j++;
        }
        else if (A[i]<B[j]){
            i++;
        }
        else if (A[i]>B[j]){
            j++;
        }
    }
    return c;
}