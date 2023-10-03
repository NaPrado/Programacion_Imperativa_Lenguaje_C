
int
interseccion(int const A[], int dimA, int const B[], int dimB, int r[]){
    int rep, c=0;
    for (int i = 0; i < dimA; i++, rep=0){
        for (int j = 0; j < dimB && !rep; j++){
            rep = A[i]==B[j];
        }
        if (rep){
            r[c++]=A[i];
        }
    }
    return c;
}