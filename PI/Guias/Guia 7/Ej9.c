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





jugar(int bolillero[], TipoCarton cartones[], int n)
{
	int huboLinea=0, bolilla, cantBolillas = MAX;
	int lineas, resultado, i, bingo=0;


	do
	{
		/* Imprimir los cartones de cada jugador */
		for (i=0; i < n; i++)
		{
			printf("\nJugador %2d\n", i+1);
			imprimirCarton(cartones[i]);
		}
		
		/* Extraer una bolilla */
		bolilla = sacarBolilla( bolillero, &cantBolillas);
		printf("Bolilla extraida: %d\n",bolilla);


		/* Controlar si alguno hizo linea */
		/* Otra opcion seria tener un vector auxiliar en donde 
		** v[I]= 1 o 0 si el jugador I hizo linea o no
		*/
		for (lineas=0, i=0; i < n; i++)
		{
			resultado = controlarCarton( cartones[i], bolilla) ;
			lineas |= resultado << i;
		
			/* Encendemos un bit en la variable bingo por cada jugador */
			if ( resultado == 3 )
				bingo |= 1 << i;
		}
		if (! huboLinea )
			for ( i=0; i < n; i++)
				if ( lineas & (1 << i))
				{
					printf ("El jugador %2d hizo linea\n", i+1);
					huboLinea = 1 ;
				}	
		PAUSA
	} while (bingo == 0);


	return bingo;
}

int
main (void)
{
	TipoCarton * cartones;
	int bolillero[MAX];
	int i, jugadores;


	int bingo;


	/* setear la semilla */
	randomize();


	for (i=0; i < MAX; i++)
		bolillero[i] = i+1;


	/* Preguntar la cantidad de jugadores */
	do
	{
		jugadores = getint("Cantidad de jugadores :");
	} while ( jugadores < 1 );	


	/* Crea el arreglo dinámico de cartones */
	if (((cartones = malloc(sizeof(TipoCarton)*jugadores))) == NULL)
	{
		printf("Hubo un error al reservar memoria.\n");
		return 1;
	}


	/* generar los cartones */
	for (i=0; i < jugadores; i++)
		generarCarton (cartones[i]);


	bingo = jugar(bolillero, cartones, jugadores);


	for (i=0; i < jugadores; i++)
		if (bingo & (1 << i))
			printf ("El jugador %d hizo bingo\n",i+1);
	free(cartones);
	return 0;
}



