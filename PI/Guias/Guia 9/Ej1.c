sumaVec(int v[],int dim){
    if (!dim)
        return 0;
    return *v+sumaVec(v+1,dim-1);
}