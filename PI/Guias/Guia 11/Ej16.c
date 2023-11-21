#include <stdio.h>
#include <stdlib.h>

/* 
La información de alumnos de los cursos activos (los del cuatrimestre) de una universidad, 
donde se sabe que todos los cursos tienen un cupo máximo de 50 alumnos. 
Los accesos más comunes serán por Nombre del curso, 
y para un curso por legajo de alumno (para buscar un alumno se indica nombre de curso y legajo).
 */
struct curso
{
    char* alumnos[50];
    size_t legajos[50];
};

/* 
Los horarios que cursa un alumno de una universidad, distinguiendo por materia 
*/

typedef struct horarios * THorarios;

enum dias{
    lunes=0,
    martes,
    miercoles,
    jueves,
    viernes,
    sabado,
    domingo,
};
struct horarios
{
    char * horas
};

struct semana
{
    THorarios dia[domingo];    
};
