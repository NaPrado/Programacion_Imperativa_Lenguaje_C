#define MAXCOL 10
#include <stdio.h>
void
swap(int matriz[][MAXCOL], int col, int h){
    int aux;
    for (int i = 0; i < col; i++)
    {
        aux=matriz[h][i];
        matriz[h][i]=matriz[h+1][i];
        matriz[h+1][i]=aux;
    }
    
}
void 
ordenaMatriz (int matriz[][MAXCOL], int fil, int col, int colOrd){
    int huboSwap=1;
    while(huboSwap){ 
        huboSwap = 0;
        for (int h = 0; h < fil-1; h++){
            if (matriz[h][colOrd-1]>matriz[h+1][colOrd-1]){
                swap( matriz, col, h );
                huboSwap = 1;
            }
        }
    }
} 
