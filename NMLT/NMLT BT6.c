#include <stdio.h>
int main()
{
	int sl, dg, tien;
	float VAT;
	printf("Nhap so luong, don gia: ");
	scanf("%d %d", &sl,&dg);
	tien=sl*dg;
	VAT=tien*0.1;
	printf("Tien la: %d\n", tien);
	printf("Thue gia tri gia tang VAT la: %1.f\n", VAT);
}
