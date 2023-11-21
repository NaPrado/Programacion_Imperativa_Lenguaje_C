#ifndef Ej8_h
#define Ej8_h

#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
typedef struct setCDT * setADT;
typedef char * elemType;
typedef int (*compare)(elemType,elemType);


setADT newSet(compare fcmp);
void freeSet(setADT set);
int isEmptySet(const setADT set);
int sizeSet(const setADT set);
int containsSet(const setADT set, elemType elem);
int addElementSet(setADT set, elemType elem);
void deleteElementSet(setADT set, elemType elem);
setADT unionSet(const setADT set1, const setADT set2);
setADT interSET(const setADT set1, const setADT set2);
setADT deffSet(const setADT set1, const setADT set2);

#endif
