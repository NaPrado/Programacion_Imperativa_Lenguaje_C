#include <stdio.h>
int
srtlen(char * str){
    if (!*str)
        return 0;
    return 1+srtlen(str+1);
}

int main(int argc, char const *argv[])
{
    printf("%d\n",srtlen("Gerooo\0"));
    return 0;
}
