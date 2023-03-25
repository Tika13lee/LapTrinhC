#include <stdio.h>
int main()
{
	int a,b;
	printf("Nhap a,b: ");
	scanf("%d %d", &a,&b);
	if(a>b) 
	    printf("a max, b min \n");
	else 
	    printf("a min, b max \n"); 
} 