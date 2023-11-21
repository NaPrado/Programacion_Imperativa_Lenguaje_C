void
fact(int n,int * h){
    if (n==0)
    {
        *h=1;
        return;
    }
    fact(n-1,h);
    *h=*h*n;
}