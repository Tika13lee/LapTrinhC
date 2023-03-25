#include <stdio.h>
int main()
{
	float a, b, c, max;
	printf("Nhap a, b, c: ");
	scanf("%f %f %f", &a,&b,&c);
	max=a;
	if(max<b) max=b;
	if(max<c) max=c;
	printf("So lon nhat trong ba so la: %.1f\n", max);
} 