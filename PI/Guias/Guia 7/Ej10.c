#include "../../Librerias/getnum.h"
#include "../../Librerias/random/random.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <time.h>
#define VIDAS 5
#define BORRA_BUFFER while (getchar() != '\n')
typedef char * str;


str //devuelve un null terminated
randPalabra(){
    randomize();
    str palabras[]={"occidente", "explorar",
    "calvinista", "autista", "ausencia", "dependencia", "cefalopodo",
    "mendigo", "sinusitis", "eficiencia", "borrador"};
    return palabras[randInt(0,10)];
}

int
verificaLetra(char letra,str palabra, str adivinadas){
    int cant=0;
    for (int i = 0;palabra[i]; i++)
    {
        if (palabra[i]==letra)
        {
            if(adivinadas[i]!=letra){
            adivinadas[i]=letra;
            cant++;
            }
        }
    }
    if (cant>0)
        printf("La letra \"%c\" es correcta\n", letra);
    else
        printf("La letra \"%c\" es incorrecta\n", letra);
    return cant;
}

str//genera un arreglo de guiones bajos null terminated
genera(int largo,str generado){
    int i;
    for (i = 0; i < largo; i++)
        generado[i]='_';
    generado[i]=0;
    return generado;
}



char
getletra(){
    int letra;
    int numero=0;
    do
    {
        printf("Ingrese letra\n");
        letra=tolower(getchar());
        if ((numero=isdigit(letra)))
            printf("Ingresaste un numero\n");
        BORRA_BUFFER;
    } while (!isalpha(letra));
    return letra;
}

int
main()
{
    int intentos=VIDAS;
    str palabra=randPalabra();
    int largo=strlen(palabra);
    char generado[largo];
    str adivinadas=genera(largo, generado);
    int ganar=0;
    int cantAdivinadas=0;
    int anterior=0;
    while (!ganar && intentos)
    {
        printf("%s\n", adivinadas);
        cantAdivinadas=+verificaLetra(getletra(),palabra,adivinadas);
        ganar=(cantAdivinadas==largo);
        if (anterior==cantAdivinadas)
            intentos--;
        anterior=cantAdivinadas;
        printf("Te quedan %d intentos\n", intentos);
    }
    if (intentos)
        printf("sos un capo\n");
    else
        printf("perdiste\n");
    
    return 0;
}
