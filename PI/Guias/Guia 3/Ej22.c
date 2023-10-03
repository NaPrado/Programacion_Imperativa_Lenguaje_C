#include<stdio.h>
int main(void)
{
    int caracter = 0, blancos = 0;
    while (caracter != EOF)
    {
        int caracter = getchar();
         if (blancos > 0 && caracter != ' ')
        {
            blancos = 0;
        }
        else if ((caracter != ' ') || (blancos == 0 && caracter == ' '))
        {
            printf("%c", caracter);
            blancos++;
        }
        else if (blancos > 0)
        {
            blancos++;
        }   
    }
        
}