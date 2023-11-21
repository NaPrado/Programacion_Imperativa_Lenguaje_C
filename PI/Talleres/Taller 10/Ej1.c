
#include <stdio.h>
#include <assert.h>
 
int esPotenciaDe3(int);
 
int
main(void) {
    assert(esPotenciaDe3(0) == 0);
    assert(esPotenciaDe3(1) == 1);
    assert(esPotenciaDe3(3) == 1);
    assert(esPotenciaDe3(9) == 1);
    assert(esPotenciaDe3(27) == 1);
    assert(esPotenciaDe3(30) == 0);
    assert(esPotenciaDe3(100) == 0);
    printf("OK!\n");
    return 0;
}

int
esPotenciaDe3(int n){
    return (n==1)||(!(n==0 || n%3!=0)&&esPotenciaDe3(n/3));
}