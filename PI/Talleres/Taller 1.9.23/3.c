//donde esta ????
int
dondeEsta(int v[],int dim,int num,int r[]){
    //indica las posiciones donde se encuentra un numero en un array
    int c = 0;
    for (int i = 0; i < dim && v[i]<= num; i++)
    {
        if (v[i]==num){
            r[c++]=i;
        }
    }
    return c;
}