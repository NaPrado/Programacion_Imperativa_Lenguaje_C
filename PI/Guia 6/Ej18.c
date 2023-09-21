#define COLS 4

int comparar(const int a[], unsigned int da, const int b[], unsigned int db){
    int hizoMatch = 1;
    for (int i = 0; i < da && hizoMatch; i++){
        hizoMatch = 0;
        for (int j = 0; j < db && !hizoMatch; j++){
            if (a[i]==b[j]){
                hizoMatch = 1;
            }
        }
    }
    return hizoMatch;
}


/* int contiene(const int v1[], unsigned int dim1, const int v2[], unsigned int dim2){
    int ret=0;
    ret =(comparar(v1,dim1,v2,dim2)?1:0);
    if (!ret)
        ret = (comparar(v2,dim2,v1,dim1)?2:0);
    return ret;
} */

int
filaAFila(const int (mA[])[COLS], unsigned int filsA,const int (mB[])[COLS], unsigned int filsB){
    int son;
    for (int i = 0; i < filsA; i++)
        for (int j = 0; j < filsB && (son=!comparar(mA[i],COLS,mB[j],COLS)); j++)
        ;
    return son;
}

int sonAmigas(const int (m1[])[COLS], unsigned int fils1,const int (m2[])[COLS], unsigned int fils2 ){
    int ret;
    if (filaAFila(m1,fils1,m2,fils2))
        ret= 1;
    else if (filaAFila(m2,fils2,m1,fils1))
        ret=2;
    else
        ret=0;
    return ret;
}