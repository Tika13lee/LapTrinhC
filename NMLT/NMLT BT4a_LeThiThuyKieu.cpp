#include <stdio.h>
int main()
{
	int n,i,S;
	printf("Nhap n: "); 
	scanf("%d", &n);
	S=0; 
    for(i=1;i<=n;i++)
       S+=i; 
    printf("%d \n", S);
	return 0; 
} 