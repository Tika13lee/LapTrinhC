#include <stdio.h>
int main()
{
	char c;
	printf("Nhap ky tu: ");
	scanf("%c", &c);
	if (c=='a' || c=='e' || c=='o' || c=='u' || c=='i')
	   printf("Day la nguyen am \n");
	else 
	   printf("Day la phu am \n"); 
}