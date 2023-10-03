#define COLS 4

int contieneOrden(const int v1[], const int v2[], unsigned int dim) {
  int i, j;
  for (i=0, j=0; i < dim && j < dim; ) {
    if ( v1[i] < v2[j] )  
      return 0;
    if ( v1[i] == v2[j]) {
      i++; 
    }
    else 
      j++;
  }
  return i==dim;
}



int vecEnMatriz(const int v[], const int (m[])[COLS], unsigned int fils) {
  for(int i=0; i < fils; i++) {
    if ( contieneOrden(v, m[i], COLS))
       return 1;
  }
  return 0;
}



int
esAmiga( int (m1[])[COLS],unsigned int f1, int (m2[])[COLS],unsigned int f2){
    for (int i = 0; i < f1; i++)
    {
        if (!vecEnMatriz(m1[i],m2,f2))
            return 0;
    }
    return 1;
}

int sonAmigas( int m1[][COLS], unsigned int fils1, int m2[][COLS], unsigned int fils2 ){
    int ret;
    if (esAmiga(m1,fils1,m2,fils2))
        ret= 1;
    else if (esAmiga(m2,fils2,m1,fils1))
        ret=2;
    else
        ret=0;
    return ret;
}