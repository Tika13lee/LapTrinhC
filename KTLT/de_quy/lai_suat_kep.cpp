#include <stdio.h>
float lai_kep(float y, float x, int n)
{
    float X=x/100;
    if(n==0)
        return (y);
    return (lai_kep(y,x, n-1) * (1+X));
}
int main()
{
    int n; 
    float y,x;
    printf("Nhap nam n = ");
    scanf("%d", &n);
    printf("Nhap so tien gui y = ");
    scanf("%f", &y);
    printf("Nhap lai xuat x = ");
    scanf("%f", &x);
    printf("%.1f", lai_kep(y, x, n));
    return 0;
}