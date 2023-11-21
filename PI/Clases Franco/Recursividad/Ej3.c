int
isNull(int vec[],int dim){
    if (dim==0 || (dim==1 && vec[1]==0))
        return 1;
    return vec[0]==0 && isNull(vec+1,dim-1);
}