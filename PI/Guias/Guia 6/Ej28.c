#define ERROR 0
#define EXITO 1
#define CANT_VOCAL 5
#include <ctype.h>
#include <stdio.h>

int
esVocal(char * str){
    char vocales[]="aeiouAEIOU";
    for (int i = 0;vocales[i]; i++)
        if (str==vocales[i])
            return (i+1);
    return 0;
}


int 
elimVocales(char * s, int m[][CANT_VOCAL], unsigned int n){
    int vecApariciones[CANT_VOCAL]={0};
    int j=0, ret=EXITO, p;
    for (int i = 0; s[i] ; i++)
    {
        if (p=(esVocal(s[i]))){
            int letra=(p>5?p-5:p)-1;
            int apariciones;
            if (vecApariciones[letra]<n)
                apariciones=vecApariciones[letra]++;
            if (apariciones<n)
                m[apariciones][letra]=i;
            else
                ret = ERROR;
        }
        else
            s[j++]=s[i];
    }
    s[j]=0;
    for (int i = 0; i < CANT_VOCAL; i++)
        vecApariciones[i]=-1;
    
    return ret;
}