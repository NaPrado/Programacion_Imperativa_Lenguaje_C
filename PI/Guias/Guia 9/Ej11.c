#define DIM 100


negBool(int m[][DIM],int dim,int fill, int cols,int radio){
    int fallas=0;
    if (fill+radio<dim && cols+radio<dim){
        m[fill+radio][cols+radio]= !(m[fill+radio][cols+radio]);
        fallas++;
    }
    if (fill-radio>0 && cols+radio<dim){
        m[fill-radio][cols+radio]= !(m[fill-radio][cols+radio]);
        fallas++;
    }
    if (fill-radio>0 && cols-radio>0){
        m[fill-radio][cols-radio]= !(m[fill-radio][cols-radio]);
        fallas++;
    }
    if (fill+radio<dim && cols-radio>0){
        m[fill+radio][cols-radio]= !(m[fill+radio][cols-radio]);
        fallas++;
    }
    if (fallas==4)
        return;
    negBool(m,dim,fill,cols,radio+1);
}

repNegBool(int m[][DIM],int dim,int fill, int cols){
    if (fill<0 || fill>dim || cols<0 || cols>dim)
        return;
    m[fill][cols] = !(m[fill][cols]);
    negBool(m,dim,fill,cols,1);
}