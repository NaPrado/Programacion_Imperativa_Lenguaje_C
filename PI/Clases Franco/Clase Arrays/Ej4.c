int eliminaCeros(int v[],int n){
    int i= 0, j;
    while (i < n)
    {
        if(v[i]== 0){
            n--;
            for (j=i; j < n; j++)
            {
                v[j]= v[j+1];
            }
        }
            else{
            i++;
        }
        return n;
    }
}