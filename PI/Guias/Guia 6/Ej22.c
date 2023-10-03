void
secuenciaAsc(const int v[], int dim, int * comienzo, int * longitud){
    int anterior=v[0], cantCadena=1,com=0,la=0,ca=0;
    if (dim==0)
    {
        * longitud = 0;
        * comienzo = 0;
    }
    else{
        for (int i = 1; i < dim; i++){
            if (anterior<v[i]){
                if (cantCadena==1)
                    com=i-1;
                cantCadena++;
                anterior=v[i];
            }
            else{
                if (cantCadena>la){
                    la = cantCadena;
                    ca = com;
                }
                * longitud = la;
                * comienzo = ca;
                cantCadena=1;
            }
        }
        if (cantCadena==dim)
        {
            * longitud = cantCadena;
            * comienzo = 0;
        }
    }
}