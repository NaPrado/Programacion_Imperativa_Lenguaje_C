#include <stdlib.h>
#include <stdio.h>
#include "../../Librerias/utillist.h"



TList
Delete(TList list, int num){
    if (list==NULL)
        return list;
    if (list->elem==num)
    {
        TList aux = list->tail;
        free(list);
        return aux;
    }
    list->tail=Delete(list->tail,num);
    return list;
}

int get(const TList list, unsigned int i){
    if (list==NULL)
        exit(1);
    if (i==0)
        return list->elem;
    get(list->tail,--i);
}