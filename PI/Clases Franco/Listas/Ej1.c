#include <stdlib.h>

typedef struct node
{
    int head;
    struct node * tail;
} tNode;

typedef tNode * TList;

int
isEmpty(TList l){
    return l= NULL;
}

size_t
size(TList l){
    if (l == NULL)
        return 0;
    return 1 + size(l->tail);
}
