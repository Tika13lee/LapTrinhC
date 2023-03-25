#include <stdio.h>
int main()
{
    int n,i,s;
    s=0;
    for(i=1;i<=10;i++)
    {
        printf("Nhap so thu %d : ", i);
        scanf("%d", &n);
        s+=n;
    }
    float tb;
    tb=1.0*s/10;
    printf("Tong la: %d\n", s);
    printf("Trung binh la: %.1f\n", tb);
}