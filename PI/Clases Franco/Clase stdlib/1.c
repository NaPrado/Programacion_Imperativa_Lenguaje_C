#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
int main(void)
{
    long int c;
    while ((c=getchar()) != '\n')
    {
        if (! isspace(c))
        {
        putchar(toupper(c));
        }
    }
    putchar('\n');
    return 0;
}
