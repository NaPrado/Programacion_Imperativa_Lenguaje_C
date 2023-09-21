#include <stdio.h>
void
swap(int *a,int *b){
    int aux=*a;
    *a=*b;
    *b=aux;
}


int
main(void){
    int a,b,*pa,*pb;
    a=5;
    b=3;
    pa=&a;
    pb=&b;
    swap(pa,pb);
    printf("%d,%d\n",a,b);
    return 0;
}
