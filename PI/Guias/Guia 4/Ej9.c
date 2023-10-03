#include<stdio.h>
int ENT_HORA = 8, ENT_MINUTOS = 0;
int 
llegaTemprano (const int hora, const int minutos)
{
	return (hora < ENT_HORA||(hora <= ENT_HORA && minutos <= ENT_MINUTOS));
}

int main(void)
{
    printf("%d",llegaTemprano(6,00));
    return 0;
}

