#include "../../Librerias/getnum.h"
#include "../../Librerias/random/random.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#define PAUSA                       \
    {                               \
        while ((getchar()) != '\n') \
            ;                       \
    }
#define MAX 90
#define MAXLINEA 5
#define MAXCOLUMNA 3
typedef  int TipoLinea[5];
typedef  TipoLinea  TipoCarton [3];

void
generarCarton(TipoCarton carton){
    int ordenado[MAX], n=MAX-1;
    for (int i = 0; i < MAX; i++)
        ordenado[i]=i+1;
    for (int i = 0; i < MAXCOLUMNA; i++)
    {
        for (int j = 0; j < MAXLINEA; j++)
        {
            int numAux = randInt(0,n-1);
            carton[i][j]=ordenado[numAux];
            ordenado[numAux]=ordenado[n--];
        }
    }
    return;
}

int
sacarBolilla(int bolillero[],int * cantBolillas){
    int random = randInt(1, *cantBolillas)-1;
    int aux;
    (*cantBolillas)--;
    aux=bolillero[random];
    bolillero[random] = bolillero[*cantBolillas];
    return aux;
}

int
buscarBolilla(TipoCarton jugador, int bolilla){
    int correcto = 0;
    for (int i = 0; i < MAXCOLUMNA && !correcto; i++)
    {
        for (int j = 0; j < MAXLINEA && !correcto; j++)
        {
            if(jugador[i][j]==bolilla){
                jugador[i][j]=0;
                correcto=1;
            }
        }
    }
    return correcto;
}

int
controlarLineas(TipoLinea linea){
    int correcto=0;
    for (int i = 0; i < MAXLINEA ; i++)
        correcto+= (linea[i]==0);
    return (correcto==MAXLINEA);
}

int
controlarCarton(TipoCarton jugador, int bolilla){
    int cantLineas=0;
    if(buscarBolilla(jugador,bolilla))
        for (int i = 0; i < MAXCOLUMNA; i++)
            cantLineas+=controlarLineas(jugador[i]);
    return cantLineas;
}

void
imprimirCarton(TipoCarton jugador){
    printf("\n");
    for (int i = 0; i < MAXCOLUMNA; i++){
        for (int j = 0; j < MAXLINEA; j++)
            (jugador[i][j]==0)?printf("X\t"):printf("%d\t",jugador[i][j]);
        printf("\n");
    }
}



int
jugar(int bolillero[],TipoCarton jugador1, TipoCarton jugador2){
    int cantBolillas, bolita, j1=0, j2=0, huboLinea=0, bingo;
    do{
        printf("\njugador 1\n");
        imprimirCarton(jugador1);
        printf("\njugador 2\n");
        imprimirCarton(jugador2);


        bolita=sacarBolilla(bolillero,&cantBolillas);
        printf("Salio la bolilla %d\n",bolita);


        j1=controlarCarton(jugador1,bolita);
        j2=controlarCarton(jugador2,bolita);

        if (!huboLinea)
        {
            if (j1)
                printf("El jugador 1 hizo linea");
            if (j2)
                printf("El jugador 2 hizo linea");
            huboLinea+=j1+j2;
        }
        bingo = (j1 == 3) | 2*(j2==3);
        PAUSA
        
    } while (bingo==0);
    return bingo;
    printf("Gano el jugador %d",(j1==3)?1:2);
    
}


int main(void)
{
    TipoCarton carton1, carton2;
    int bolillero[MAX];
    int i;

    int bingo;

    randomize();

    for (i = 0; i < MAX; i++)
        bolillero[i] = i + 1;

    generarCarton(carton1);
    generarCarton(carton2);

    bingo = jugar(bolillero, carton1, carton2);

    for (i = 1; i <= 2; i++)
        if (bingo & i)
            printf("El jugador %d hizo bingo\n", i);

    return 0;
}