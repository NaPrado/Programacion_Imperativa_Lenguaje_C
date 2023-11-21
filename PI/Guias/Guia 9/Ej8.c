/* 
ACK ( 0,N ) = N + 1
ACK ( M,0 ) = ACK ( M - 1, 1 )
ACK ( M,N ) = ACK ( M - 1, ACK ( M , N - 1 ) )
*/

ACKERMANN(int M,int N){
    if (M==0)
        return N+1;
    if (N==0)
        return ACKERMANN(M-1,1);
    ACKERMANN(M-1,ACKERMANN(M,N-1));
}