#include <ctype.h>
int
esVocal(char l){
    l=toupper(l);
    char v[10]={'A','E','I','O','U'};
    for (int i = 0; i < 5; i++)
        if (l==v[i])
            return 1;
    return 0;
}
int
vocales(char*s){
    if(*s==0)
        return 0;
    return esVocal(*s) + vocales(s+1);
}