#include <math.h>
#define EXITO 0
#define ERRORPASOS 1
#define ERRORPARAMETROS 2


int
distancia(int i,int dir,int n,int fuera,int*f){
	int borde=0;
	if((i+dir*n)>fuera){
		borde=1;
		*f=fuera;
	}
	else if((i+dir*n)<0){
		borde=1;
		*f=0;
	}
	else{
		*f=i+dir*n;

	}
	return borde;
}


int
posicionFinal(int tab[FILAS][COLUMNAS], int xi, int yi, int dirx, int diry, int n, int* xf, int* yf){
	int ret=EXITO;
	if(xi>COLUMNAS||xi<0||yi>FILAS||yi<0||(dirx!=fabs(1)&& dirx!=0)||(diry!=fabs(1)&& diry!=0)||n<0||!(dirx==0&&diry==0)){
		ret=ERRORPARAMETROS;
	}
	else{
		int borde=distancia(xi,dirx,n,COLUMNAS,xf)||distancia(yi,diry,n,FILAS,yf);
		tab[*yf][*xf]='B';
		if(borde){
			ret=ERRORPASOS;
		}
	}
	return ret;
}