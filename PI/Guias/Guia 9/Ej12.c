int
balance(char*str){
    if (!*str)
        return 0;
    if (*str=='(')
        return -1 + balance(str+1);
    if (*str==')')
        return 1 + balance(str+1);
}