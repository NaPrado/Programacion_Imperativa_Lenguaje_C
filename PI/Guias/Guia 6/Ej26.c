void insertaDesde(char * s1, const char * s2, char c){
    int j=0;
    for (int i = 0; s1[i]!=0 || s2[j]!=0 ; i++){
        if (s1[i]==c||j){
            s1[i]=s2[j++];
        }
    }
}