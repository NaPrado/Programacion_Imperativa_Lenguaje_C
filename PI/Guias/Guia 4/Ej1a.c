#include<stdio.h>
#define PI  3.1415
 	
int
main(void)
{
	int a = 0;
	int b;


    b = PI + a++;
    printf("%d\n%d\n",a,b);

	return 0;
}
