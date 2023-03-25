#include <stdio.h>
int main()
{
	int a,b;
	printf("Nhap a, b: ");
	scanf("%d %d", &a,&b);
	if (b==0) 
	{
	     printf("Nhap lai b: ");
	     scanf("%d", &b);	
    } 
    if (a%b==0) 
         printf("b la uoc so cua a \n");
    else 
	     printf("b khong phai la uoc so cua a \n"); 
} 