#include <stdio.h>
double
raiz(double valorAnterior,int iter,double x){
    if (!(iter-1))
        return valorAnterior;
    return raiz((valorAnterior+(x/valorAnterior))/2,iter-1,x);
}
int main(int argc, char const *argv[])
{
    printf("%f\n",raiz(4,3,8));
    return 0;
}
