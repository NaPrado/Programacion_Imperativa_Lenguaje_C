
int
apareados(char * str){
    if (!*str)
        return 0;
    int aux=apareados(str+1);
    if (aux<0)
        return aux;
    return aux + (*str == '(' ? -1 : 1);
}