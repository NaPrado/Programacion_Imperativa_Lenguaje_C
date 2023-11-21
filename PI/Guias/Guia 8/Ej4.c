#include <stdio.h>


#include "../../Librerias/getnum.h"
#include "../../Librerias/random/random.h"



#define CANTNUM 13
#define CANTPALOS 4
#define CANTCARTAS CANTNUM*CANTPALOS
#define CANTREP 5
#define JUEGOS 3

/* enum n {As=0,Dos,Tres,Cuatro,Cinco,Seis,Siete,Ocho,Nueve,Diez,J,Q,K};
enum p {Diamantes=0,Corazones,Picas,Treboles}; */

typedef struct carta
{
    int numero;
    int palo;
}carta;

typedef enum {NADA=1, PAR, PIERNA, POKER} tipoConfiguraciones;

void
generaMazo(carta  mazo[]){
    for (int i = 0; i < CANTCARTAS; i++){
        mazo[i].numero=i%CANTNUM;
        mazo[i].palo=i/CANTPALOS;
    }
    return;
}

void
mezclaMazo(carta mazo[CANTCARTAS]){
    int posicion;
    carta auxCarta;
    for (int i = 0; i < CANTCARTAS; i++){
        auxCarta = mazo[i];
        posicion = rand() % CANTCARTAS;
        mazo[i] = mazo[posicion];
        mazo[posicion] = auxCarta;
    }
}

void
reparteCartas(carta mazo[CANTCARTAS],carta repartidas[CANTREP],int cantJugadores){
/*     if (cantJugadores>10){
        repartidas=NULL;
        return;
    } */
    for (int i = 0; i < CANTREP-1; i++)
        mazo[i+cantJugadores]=repartidas[i+cantJugadores];
}

// cant=2 par  cant=3 pierna cant=4 poker 
void
verificaJuegos(const carta juego[])
{
    int i,j;
    char *cFiguras[] = {"Dos", "Tres", "Cuatro", "Cinco", "Seis",
                "Siete", "Ocho", "Nueve", "Diez", "J", "Q", "K", "As"};
    char *cPalos[] = {"Diamante", "Trebol", "Corazon", "Pique"};
    char *cResultados[] = {"Nada", "Par", "Pierna", "Poker"};


    tipoConfiguraciones total=NADA, parcial;


    for (i=0; i<CANTREP-1; i++)
    {
        parcial=NADA;
        for(j=i+1; j<CANTREP; j++)
            if (juego[i].numero == juego[j].numero)
                parcial++;


        if (total < parcial)
            total = parcial;
    }


    printf("\nSu juego es: \n");
    for (i=0; i<CANTREP; i++)
        printf("%s %s\n", cFiguras[juego[i].numero], cPalos[juego[i].palo]);


    printf("El resultado es: %s\n", cResultados[total-1]);
}


void
jugar(){
    int cantjugadores=1;
    carta mazo[CANTCARTAS];
    carta repartidas[CANTREP];
    generaMazo(mazo);
    mezclaMazo(mazo);
    reparteCartas(mazo,repartidas,cantjugadores);
    verificaJuegos(repartidas);
} 

int main(void)
{
    randomize();
    jugar();
    
    return 0;
}
