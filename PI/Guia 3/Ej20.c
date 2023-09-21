#include<stdio.h>

#define EPS 0.0000001

int main(void){
    double e = 1, prev = 0;
    int factorial = 1;
    printf("%-10s %-10s\n","N", "e");
    for ( int n = 1; e -prev > EPS ; n++ )
    {
        prev = e;
        printf("%-10d %10.7f\n", n, e);
        factorial *= n;
        e += 1.0/factorial;
    }
    
}
/*2.718282*/