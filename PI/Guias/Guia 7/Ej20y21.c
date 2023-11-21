#include <string.h>
#include <stdlib.h>
typedef char TAlumnos[][40];


char ** aprobados(TAlumnos alumnos, const int notas[] ){


    char ** apAlum=malloc(5*sizeof(char *));
    int j=0, q=1;


    for (int i = 0;alumnos[i][0]; i++){
        if (notas[i]>=4){
            if (j>=5*q){
                char ** apAlum=realloc(**apAlum,sizeof(char *)*(5*q));
                q++;
            }


            int largo=strlen(alumnos[i]);
            malloc((largo+1)*sizeof(char));
            strcpy(apAlum[j++],alumnos[i]);
        
        
        }
    }

    char ** apAlum=realloc(apAlum,sizeof(char *)*(j+1));
    apAlum[j][0]=0;
    
    return apAlum;
}

void
freeaprob(char ** aprob){
    for (int i = 0; aprob[i]; i++)
        free(aprob[i]);
    free(aprob);
}