#include <stdio.h>
void
regla(int h){
    if (h==1)
    {
        printf("%d",h);
        return;
    }
    regla(h/2);
    printf("%d",h);
    regla(h/2);
}
int main(int argc, char const *argv[])
{
    regla(5);
    return 0;
}
