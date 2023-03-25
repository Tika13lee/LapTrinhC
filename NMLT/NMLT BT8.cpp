#include <stdio.h>
#include <math.h> 
int main()
{
	float R, chuvi, dientich; 
	printf("Nhap ban kinh R: ");
	scanf("%f", &R); 
	const float PI=3.1415;
	chuvi=2*PI*R;
	dientich=PI*R*R;
	printf("Chu Vi la: %.4f\n", chuvi);
	printf("Dien tich la: %.4f\n", dientich); 
}
