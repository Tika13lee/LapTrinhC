#include <stdio.h>
int main()
{
	float dtb;
	printf("Nhap diem trung binh: ");
	scanf("%f", &dtb);
	if (dtb>10)
	   printf("Nhap sai \n");
	else if (dtb>=9)
	   printf("Xuat sac \n");
    else if (dtb>=8)
       printf("Gioi \n");
    else if (dtb>=7)
       printf("Kha \n");
    else if (dtb>=6)
       printf("Trung binh kha \n");
    else if (dtb>=5)
       printf("Trung binh \n");
    else
       printf("Yeu \n");
}