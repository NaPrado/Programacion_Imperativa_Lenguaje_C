#include <stdio.h>
int main(int argc, char const *argv[])
{
    int cant,d,m,y;
    do
    {        
        printf("Ingrese la fecha: ");
        cant=scanf("%d/%d/%d",&d,&m,&y); // guarda en d el primer numero hasta / 
        // luego el numero entre / y / en m
        // finalmente en y el ultimo numero desde /
        while (getchar()!='\n'); //limpia el buffer

        if (cant!=3)
            printf("dato erroneo");
    } while (cant!=3);
    
    return 0;
}
