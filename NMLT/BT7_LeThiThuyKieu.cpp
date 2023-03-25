#include <stdio.h>
int main()
{
	int a,b,c; 
	printf("Nhap a, b, c: "); 
	scanf("%d %d %d", &a,&b,&c);
	if ((a + b > c) && (a + c > b) && (b + c > a) && (a>0) && (b > 0) && (c > 0))
    {
	    if ((a == b) && (b == c) && (c == a)) 
		    printf ("Day la tam giac deu \n");
        else if (( a == b) || (b == c) || (a == c)) 
		    printf ("Day la tam giac can \n");
        else
            printf ("Day la tam giac thuong  \n");
	}
    else printf("Day khong phai la tam giac \n"); 
}