#define ELAPSED(h1,m1,h2,m2) (((h1)*60+(m1))>((h2)*60+(m2))?(((h1)*60+(m1))-((h2)*60+(m2))):(((h2)*60+(m2))-((h1)*60+(m1))))
#include <stdio.h>
int main(void)
{
    int h1=3,m1=15,h2=2,m2=10;
    printf("%d",ELAPSED(h1,m1,h1+1,m1));
    return 0;
}
