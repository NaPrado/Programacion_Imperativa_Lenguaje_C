#include<stdio.h>
int main(void)
{
    int caracter = 0;
    while (caracter != EOF)
    {
        int caracter = getchar();
        if (caracter != ' ' && caracter != 'n/' && caracter != 't/')
        {
            printf("%c", caracter);
        }
        else
            printf("\n");
    }
        
}
