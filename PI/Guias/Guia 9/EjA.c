#include <stdio.h>
void
palotes(int n){
    if (n==0)
        return;
    palotes(n-1);
    printf("|");
}
int main(int argc, char const *argv[])
{
    palotes(3);
    return 0;
}
