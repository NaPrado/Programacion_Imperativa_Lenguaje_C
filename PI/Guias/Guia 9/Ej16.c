

int
orden(int v[]){
    if (v[0]==-1 || v[1]==-1)
        return 0;
    if (v[2]==-1)
    {
        if (v[0]<v[1])
            return 1;
        if (v[0]>v[1])
            return -1;
        return 0;
    }
    int aux = orden(v++);
    if (aux==0)
        return 0;
    if (aux==1)
        return v[0]<v[1];
    if (v[0]<v[1])
        return -1;
    return 0;
}