#include <stdlib.h>
#include <stdio.h>
char *
strrchr(char*str,char c){
    if (!*str)
        return NULL;
    char * aux = strrchr(str+1, c);
	if ( aux != NULL )
		return aux;
    if (*str==c)
        return str;
    return NULL;
}