void
eliminaBlancos (char c[]){
    int j=0;
    for (int i = 0; c[i]!=0 ; i++)
    {
        if (c[i]!=' ')
            c[j++]=c[i];
        else if (c[i-1]!=' ')
            c[j++]=' ';   
    }
    c[j]=0;
}