#include <stdio.h>
int main()
{
	int n,t;
	printf("Nhap n: ");
	scanf("%d", &n);
	if(n<=0)
	   t=0;
	else if (n<=100) 
	   t=n*950;
	else if (n<=150)
	   t=100*950 + (n-100)*1250 ;
	else if (n<=200)
	   t=100*950 + 50*1250 + (n-150)*1350;
	else 
	   t=100*950 + 50*1250 + 50*1350 + (n-200)*1550; 
	printf("So tien phai tra khi su dung dien la: %d\n", t);   
}