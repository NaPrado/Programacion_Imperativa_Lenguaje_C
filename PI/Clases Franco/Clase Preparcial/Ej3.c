#define COLS 5
#define FILS 6

int
Wordle(const char * secretWord, char m[][COLS],unsigned int attemps, char out[][COLS]){
    int count,i;
    for (i = 0; i < attemps && count==COLS; i++){
        count=0;
        char * pointer=secretWord;
        for (int j = 0; j < COLS && count==COLS; j++)
        {
            int EsGris=1;
            if (*pointer==m[i][j]){
                pointer++;
                out[i][j]='V';
                count++;
                EsGris=0;
            }
            else{
                char * pWord=secretWord;
                for (int q = 0; q < COLS; q++)
                    if (*(pWord+q)==m[i][j]){
                        out[i][j]='A';
                        EsGris=0;
                    }
            }
            if (EsGris)
               out[i][j]='G';
        }
        
    }
    if (count==COLS)
        return i;
    else
        return -1;
}