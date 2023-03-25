#include <stdio.h>
#include <math.h>
int giaithua(int n);
float tinhEmuX(float x, int n);
int main()
{
    int n;
    float x;
    do
    {
        printf("Nhap so nguyen duong n: ");
        scanf("%d", &n);
    }
    while(n<=1);
    printf("Nhap x: ");
    scanf("%f", &x);
    float S=tinhEmuX(x,n);
    printf("Ket qua la: %.1f\n", S);
}
int giaithua(int n)
{
    int i,t=1;
    for(i=1;i<=n;i++)
        t*=i;
    return t;
}
float tinhEmuX(float x, int n)
{
    int i;
    float s=0;
    for(i=0;i<=n;i++)
    {
        s+=(1.0*pow(x,i))/(giaithua(i));
    }
    return s;
}