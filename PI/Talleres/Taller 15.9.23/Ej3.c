#include <stdio.h>
#include <assert.h>
 
#define FILAS 7
#define COLS 6
 
#define ERROR (-1)
 
int calculaDireccion(char mat[][COLS], int alto, int ancho, int x, int y);
 
int
main(void) {
    char tablero[][COLS] = {
            {'0', '0', '0', '0', '1', '0'},
            {'X', 'X', '0', '0', '0', '0'},
            {'0', '0', '0', '0', 'X', 'X'},
            {'0', '0', '0', '0', '0', '0'},
            {'0', '0', '0', '0', '0', '0'},
            {'0', '0', '0', 'X', '0', '0'},
            {'1', '0', '0', 'X', 'X', 'X'}
    };
    int res = calculaDireccion(tablero, FILAS, COLS, 4, 1);
    assert(res == 0 || res == 45);
 
    assert(calculaDireccion(tablero, FILAS, COLS, 0, 0) == 0);
    assert(calculaDireccion(tablero, FILAS, COLS, 6, 2) == 90);
    assert(calculaDireccion(tablero, FILAS, COLS, 5, 4) == 135);
    assert(calculaDireccion(tablero, FILAS, COLS, 3, 5) == 180);
    assert(calculaDireccion(tablero, FILAS, COLS, 0, 5) == 225);
 
    res = calculaDireccion(tablero, FILAS, COLS, 3, 2);
    assert(res == 0 || res == 45 || res == 90 || res == 270);
 
    // Jugador fuera del tablero
    assert(calculaDireccion(tablero, FILAS, COLS, FILAS, COLS) == ERROR);
 
    printf("OK!\n");
    return 0;
}
int
calculaDireccion(char mat[][COLS], int f, int c, int x, int y){
    int nose[2];
    int anterior=-1;
    int direccion[][2]={{0,1},
                        {-1,1},
                        {-1,0},
                        {-1,-1},
                        {0,-1},
                        {1,-1},
                        {1,0},
                        {1,1}};
    for (int i = 0; i < 8; i++){
        for (int j = 0; i < 2; i++){
            if (analizaDireccion(mat, f, c, x, y, direccion[i][j], direccion[i][j])>anterior){
                anterior = analizaDireccion(mat, f, c, x, y, direccion[i][j], direccion[i][j]);
                nose[0]=i;
                nose[1]=j;
            }
        }
    }
    if ()
    {
        /* code */
    }
    
    
}


int analizaDireccion(char mat[][COLS], int f, int c, int x, int y, int ns, int eo){
    int u=0, exit=0;
    for (int i = x; i < f && !exit; i++)
    {
        for (int j = y; i < c && !exit; j++)
        {
            if (ns>0)
            {
                i++;
            }
            else if (ns<0)
            {
                i--;
            }
            if (eo>0)
            {
                j++;
            }
            else if (eo<0)
            {
                j--;
            }
            if (mat[i][j]=='0')
            {
                u++;
            }
            else
                exit=1;
        }
        
    }
    return u;
}