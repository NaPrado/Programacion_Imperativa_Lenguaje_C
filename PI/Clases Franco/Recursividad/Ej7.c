#include <stdio.h>
int
branches(int max, int min){
    if (max<min)
        return 0;
    if (max==min)
        return 1;
    return 1+2*branches(max/2,min);
}
int main(int argc, char const *argv[])
{
    printf("%d\n",branches(5,1));
    return 0;
}
