#include <stdio.h>
int main()
{
	float a,b,c; 
	printf("Nhap a,b,c: "); 
	scanf("%f %f %f", &a,&b,&c);
	if ((a + b > c) && (a + c > b) && (b + c > a) && (a>0) && (b > 0) && (c > 0))
    {
	    if ((a == b) && (b == c) && (c == a)) 
		    printf ("Day la tam giac deu \n");
        else if (((a * a + b * b == c * c) && (a == b)) || ((a * a + c * c == b * b) && (a == c))
         || (( c* c + b * b == a * a) && (c == b))) 
		    printf ("Day la tam giac vuong can \n");
        else if (( a == b) || (b == c) || (a == c)) 
		    printf ("Day la tam giac can \n");
        else if ((a * a == b * b + c * c) || (b * b == a * a + c * c) || (c * c == a * a + b * b))
            printf ("Day la tam giac vuong \n");
        else
            printf ("Day la tam giac thuong  \n");
	}
    else printf("Day khong phai la tam giac \n"); 
    return 0; 
} 