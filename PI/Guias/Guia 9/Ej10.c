#include <string.h>
invierte(char* origen, char* destino){ 
    if (*origen)
        *(destino+strlen(origen)-1)=*origen;
        invierte(origen+1,destino);
}