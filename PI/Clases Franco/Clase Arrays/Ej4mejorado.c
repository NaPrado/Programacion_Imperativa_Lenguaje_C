int
eliminaCeros(int v[],int n){
    int i,j;
    i=j=0;
    while (i<n){
        if(v[i]=0){
            v[j++]=v[i];
        }
        i++;
    }
    return n;
}