
int
potencia(int i, int n){//base exponente
    if (n==0)
        return 1;
    return i*potencia(i,--n);
}