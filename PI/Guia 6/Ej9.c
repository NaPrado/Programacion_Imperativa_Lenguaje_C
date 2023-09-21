#include <math.h>
#define ISDORI (i%2?v[i/2]&0x0F:v[1/2]&0xF0>>4)


double
desv(const char v[], int cantnum){
    int a[cantnum];
    double sumatoria=0, promedio=0;
    for (int i = 0; i < cantnum;i++){
        promedio += ISDORI/(double)cantnum;
    }
    
    for (int i = 0; i < cantnum; i++)
    {
        sumatoria+=pow((ISDORI-promedio),2);
    }
    return (cantnum==0)?((double)(0.0)):(double)(sqrt(sumatoria)/cantnum);
}