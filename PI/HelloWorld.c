#include <stdio.h>
#include <ctype.h>
#include <unistd.h> 

int main(void){
    char HW[]="Jony la tiene chiquita";
    char printable[200]={0};
    for (int i = 0; HW[i] ; i++){
        for (char j = 0; HW[i]!=j-1 ; j++){
                for (int q = 0; q < 100; q++)
                  sleep(0.5);
                if (isalnum(j)|| j==' '|| j== '!' || j=='?'){
                  printable[i]=j;
                  printf("%s\n",printable);
                }
            }
    }
    return 0;
}