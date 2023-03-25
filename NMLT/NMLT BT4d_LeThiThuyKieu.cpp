#include <stdio.h>
int main()
{
	int n,i,t;
	printf("Nhap n: "); 
	scanf("%d",&n);
 	t=1;
	for(i=1;i<=n;i++)
	   t*=i;
	printf("%d\n",t);
	return 0; 
} 