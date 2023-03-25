#include <stdio.h>
int main()
{
	float T,L,H,hsT,hsL,hsH,dtb;
	printf("Nhap diem T, He so T: \n");
	scanf("%f %f", &T,&hsT);
	printf("Nhap diem L, He so L: \n");
	scanf("%f %f", &L,&hsL);
	printf("Nhap diem H, He so H: \n");
	scanf("%f %f", &H,&hsH);
	dtb=(T*hsT+L*hsL+H*hsH)/(hsT+hsL+hsH);
	printf("Diem trung binh la: %.1f\n", dtb);

}
