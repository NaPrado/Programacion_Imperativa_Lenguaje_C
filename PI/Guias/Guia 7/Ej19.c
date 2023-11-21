#include <stdio.h>
char *
copiaPrefijo(char * str,int n){
    char prefijo[n];
    int i;
    if (n<=0 || str==0)
        return NULL;
    for (i = 0; i < n || str[i]; i++)
    {
        prefijo[i]=str[i];
    }
    prefijo[i+1]=0;
    return prefijo;
}