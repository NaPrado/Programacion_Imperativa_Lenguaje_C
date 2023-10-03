#include <stdio.h>
int
aparece(int v[],unsigned int dim, int num){
    int aparecio = 0, *end = v + dim;
    for (; v < end && !aparecio; v++){
        if (*v==num){
            aparecio = 1;
        }
    }
    return aparecio;
}
int
main(void)
{
    int v[]={3,5,7};
    int dim = sizeof(v)/sizeof(v[0]);
    int esta = aparece(v,dim,6);
    printf("%d\n",esta);
    return 0;
}
