#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef unsigned int uInt ;


int 
esBisiesto(int anio) {
    if ((anio % 4 == 0 && anio % 100 != 0) || (anio % 400 == 0)) {
        return 1; // Es un año bisiesto
    } else {
        return 0; // No es un año bisiesto
    }
}



int
valorFecha( const char * fecha, uInt *dia, uInt *mes, uInt * anio){
    uInt day,month,year;
    uInt mDay[12]={31,28,31,30,31,30,31,31,30,31,30,31};

    if (strlen(fecha)==10)
    {
        day = atoi(fecha);
        month = atoi(fecha+3);
        year = atoi(fecha+6);
        if (esBisiesto(year))
            mDay[1]=29;
        if (month>12 || day>mDay[month-1])
            return 0;

        *dia = day;
        *mes = month;
        *anio = year;
        return 1;
    }
    else
        return 0;
}
