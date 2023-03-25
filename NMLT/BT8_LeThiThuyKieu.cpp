#include <stdio.h>
int main()
{
	char c;
	printf("Nhap ky tu: ");
	scanf("%c", &c);
	if(((c>='A') && (c<='Z'))||((c>='a') && (c<='z')))
	   printf("Day la chu cai \n");
    else if((c>='0')&&(c<='9'))
       printf("Day la chu so \n");
    else 
       printf("Day la ky tu dac biet \n");
}