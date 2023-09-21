int 
dcm (int a, int b)
{
	int auxi;
    if (b > a){
        auxi = a;
        a = b;
        b = auxi;
    }
	while (auxi>0)
	{	
        auxi = a % b ;
        a = b;
        b = auxi;}


	return a;
}
