#include "../../Librerias/getnum.h"
#include "../../Librerias/random/random.h"
#include <math.h>
#include <stdio.h>
typedef struct co
{
    int x;
    int y;
}co;

void
step(co* coords){
    randomize();
    switch (randInt(0,3)){
    case 0:
        coords->x--;
        break;
    case 1:
        coords->x++;
        break;
    case 2:
        coords->y--;
        break;
    case 3:
        coords->y++;
        break;
    default:
        break;
    }
}

int
check(co coords,int r, int * t){
    if (pow(coords.x,2)+pow(coords.y,2)>=pow(r,2))
        return 0;
    (*t)++;
    return 1;

}

void
printResults(int r,int t){
    double j=((double)r)/t;
    printf("The radius is %d\n",r);
    printf("The time is %d\n",t);
    printf("The relation between the radius and the time is %f\n",j);
}

int main(int argc, char const *argv[])
{
    co coords;
    coords.x=0;
    coords.y=0;
    int t=0;
    int r=getint("what's the radius of the circumference\n");
    while (check(coords,r,&t)){
        step(&coords);
        printf("coords(%d,%d)\n",coords.x,coords.y);
    }
    printResults(r,t);
    
    return 0;
}
