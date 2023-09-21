#include <stdio.h>
void
horasSimples(int segundos,int*hora,int*min,int*seg){
    *hora=(segundos)/3600;
    *min=(segundos%3600)/60;
    *seg=(segundos%60);
}

int
main(void){
    int segundos=3700;
    int hora,min,seg;
    horasSimples(segundos,&hora,&min,&seg);
    printf("%d segundos son %d horas, %d minutos, %d segundos\n",segundos,hora,min,seg);
    return 0;
}
