#define DIM 9
#include <stdio.h>

int
analizaFC(char (m[])[DIM],int FC){
    int ret=1, pos;
    for (int i = 0; i < 9 && ret; i++)
    {
        int v[9]={0};
        for (int j = 0; j < 9 && ret; j++)
                if ((pos = (FC?m[j][i]:m[i][j])-1)>-1 && pos<=9){
                    v[pos]+=1;
                if ((v[pos])>1){
                    ret = 0;   
                }}
                else
                    return 0;
    }
    return ret;
}

int
analizaSM(char (m[])[DIM],int x, int y){
    int ret=1;
    int v[9]={0};
    for (int i = x; i < x+3; i++)
        for (int j = y; j < y+3; j++)
            if (v[(m[i][j])-1]++)
                ret = 0;
    return ret;
}


int 
sudokuSolver(char m[][DIM]){
    int ret;
    if(!(ret=analizaFC(m,0)))
        return ret;
    if (!(ret=analizaFC(m,1)))
        return ret;
    // for (int i = 0; i < 9; i+=3)
    //     for (int j = 0; j < 9; j+=3)
    //         if (!(ret=analizaSM(m,i,j)))
    //             return ret;
    return ret;
}