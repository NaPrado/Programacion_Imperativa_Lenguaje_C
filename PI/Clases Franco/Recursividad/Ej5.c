#include <string.h>
static int
esCapicuaRec(const char *s,int dim){
    if ( dim <= 1 )
        return 1;
    return (s[0]==s[dim-1]) && esCapicuaRec(s+1,dim-2);
}
int
esCapicua(const char *s){
    return esCapicuaRec(s,strlen(s));
}