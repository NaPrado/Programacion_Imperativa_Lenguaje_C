#include <stdio.h>
int
aparece(const int v[],unsigned int dim, int num){
    int aparecio = 0;
    for (int i = 0; i < dim && !aparecio; i++){
        if (v[i]==num){
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
