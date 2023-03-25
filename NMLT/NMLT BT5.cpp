#include <stdio.h>
int main()
{
	int a, b, tong, hieu, tich;
	float thuong;
	printf("Nhap a, b: ");
	scanf("%d %d", &a,&b);
	tong=a+b;
	hieu=a-b;
	tich=a*b;
	thuong=a*1.0/b;
	printf("Tong la: %d\n", tong);
	printf("Hieu la: %d\n", hieu);
	printf("Tich la: %d\n", tich);
	printf("Thuong la: %.1f\n", thuong);
}
