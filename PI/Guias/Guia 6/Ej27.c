#include <stdio.h>
void
analize(const char * text, char * chars){
    int j=0;
    char aparece[256]={0};
    for (int i = 0 ; text[i]!=0 ; i++)
        aparece[(int)*(text+i)]=1;

    
    for (int i = 0; i<256 ; i++)
        if (aparece[i]!=0)
            chars[j++]=i;
    chars[j++]=0;
}