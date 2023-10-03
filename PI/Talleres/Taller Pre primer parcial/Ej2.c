#include <ctype.h>
int
elimina(char str[]){
    int i,c = 0;
    for (i = 0; str[i]!=0; i++)
    {
        if (isalpha(str[i]))
        {
            str[c++]=str[i];
        }
    }
    str[c]=0;
    return c;
}
// Para el B) char *s = "abc" /// no podes modificar el puntero