#define ALTO 6
#define ANCHO 5
#define MAX(x,y) ((x) > (y) ? (x) : (y))
#define MIN(x,y) ((x) < (y) ? (x) : (y))

void
copy(unsigned char src[ALTO][ANCHO],unsigned char trg[ALTO][ANCHO],int fill,int coll){
    for (int i = 0; i < fill; i++)
        for (int j = 0; j < coll; j++)
            trg[i][j]=src[i][j];
}


int
promedio(unsigned char m[ALTO][ANCHO], int row, int col, int w){
    w/=2;
    int sum = 0, cant = 0;
    for (int i = MAX(0, row-w); i <= MIN(ALTO-1, row+w); i++){
        for (int j = MAX(0, col-w); j <= MIN(ANCHO-1, col+w); j++){
            sum +=m[i][j];
            cant++;
        }
    }
    return sum/cant;
}



void
suavizar(unsigned char imagen[ALTO][ANCHO], unsigned int w ){
    if (w < 3 || !(w % 2) )
        return;
    unsigned char aux[ALTO][ANCHO];
    for (int i = 0;i < ALTO; i++){
        for (int j = 0;j < ANCHO; j++){
            aux[i][j]=promedio(imagen,i, j, w);
        }
    }
    
    copy(aux,imagen,ALTO,ANCHO);
}



