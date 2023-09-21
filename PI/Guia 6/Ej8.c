#define END -1
#define CHECKA (r[c-1]!=a[i])
#define CHECKB (r[c-1]!=b[j])
#define CHECKC (c==0)
void
unirArreglos(const int a[], const int b[], int r[]){
    int i = 0, j = 0, c = 0;

    while ((a[i]!= END)||(b[j]!=END))
    {
        if ( (a[i]!= END) && (b[j]!=END) && ( CHECKA || CHECKB || CHECKC ) ){
            if ((a[i]==b[j])  && (CHECKC || ( CHECKA && CHECKB ) ) ){
                r[c++]=a[i];
                i++;
                j++;
            }
            else if (a[i]<b[j] &&  (CHECKA||CHECKC)){
                r[c++]=a[i];
                i++;
            }
            else if (b[j]<a[i] && (CHECKB||CHECKC)){
                r[c++]=b[j];
                j++;
            }
        }
        else if (a[i]!= END && CHECKA){
            r[c++]=a[i];
            i++;
        }
        else if (b[j]!= END && CHECKB){
            r[c++]=b[j];
            j++;
        } 
        if (!(CHECKA)){
            i++;
        }
        if (!(CHECKB)){
            j++;
        }
    }
    r[c++]=-1;  
}

