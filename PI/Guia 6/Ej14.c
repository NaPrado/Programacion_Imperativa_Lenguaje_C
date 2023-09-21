

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


int contiene(const int v1[], unsigned int dim1, const int v2[], unsigned int dim2){
    int ret=0;
    ret =(comparar(v1,dim1,v2,dim2)?1:0);
    if (!ret)
        ret = (comparar(v2,dim2,v1,dim1)?2:0);
    return ret;
}

