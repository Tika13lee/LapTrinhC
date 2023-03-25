#include <stdio.h>
int main()
{
	int n, min, max, donvi;
    scanf("%d",&n);
	min=n%10;
	max=min;
	n/=10;
	while(n>0)
	{
		donvi=n%10;
		n/=10;
		if(donvi<min) min=donvi;
		if(donvi>max) max=donvi; 
	} 
	printf("so NN = %d , so LN = %d",min,max);
	return 0;	 
}