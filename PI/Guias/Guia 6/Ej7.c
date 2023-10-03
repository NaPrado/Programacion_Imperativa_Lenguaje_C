#include<stdio.h>
#define END -1

void
unirArreglos( const int v1[], const int v2[], int r[]){
    int c = 0;
    for (int i = 0, j = 0; (v1[i]!= END)||(v2[j]!=END);){
        if((v1[i]!= END)&&(v2[j]!=END)){    
            if(v1[i]==v2[j]){
                r[c++]=v1[i];
                i++;
                j++;
            }
            else if (v1[i]<v2[j]){
                r[c++]=v1[i];
                i++;
            }
            else if (v2[j]<v1[i]){
                r[c++]=v2[j];
                j++;
            }
        }
        else if (v1[i]!= END){
            r[c++]=v1[i];
            i++;
        }
        else{
            r[c++]=v2[j];
            j++;
        }
    }
    r[c++]=-1;
}
