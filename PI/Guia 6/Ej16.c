#define FILS 3
#define COLS 4
#include <stdio.h>
int ascendenteODescendente(const int (m[])[COLS]){
    int anterior=0, decendente = 1, acendente = 1, ret = 0;
    for (int i = 0; i < FILS; i++){
        for (int j = 0; j < COLS; j++){
            if (!(i==0 && j==0))
            {
                if (anterior >= m[i][j] && decendente)
                    decendente=1;
                else
                    decendente=0;
                if (anterior <= m[i][j] && acendente)
                    acendente=1;
                else
                    acendente=0;
            }
            anterior = m[i][j];
        }
    }
    if (decendente)
        ret= -1;
    else if (acendente)
        ret= 1;
    else
        ret=0;
    return ret;
}