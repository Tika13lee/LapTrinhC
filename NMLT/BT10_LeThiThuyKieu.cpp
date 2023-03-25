#include <stdio.h>
int main()
{
	int n, t;
	printf("Nhap so ao thun: ");
	scanf("%d", &n);
	if (n<=3) 
	   t=n*120000;
	if (n>3 && n<=6)
	   t=3*120000 + (n-3)*90000;
	if (n>6 && n<=10)
	   t=3*120000 + 3*90000 + (n-6)*85000;
	if (n>10)
       t=3*120000 + 3*90000 + 4*85000 + (n-10)*70000; 
    printf("So tien phai tra la: %d\n", t);
} 