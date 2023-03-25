#include <stdio.h>
#include <math.h>
void giaiptbachai(int a, int b, int c);
int main()
{
    int a, b, c;
    do
    {
        printf("Nhap a, b, c: ");
        scanf("%d %d %d", &a,&b,&c);
    }
    while(a==0);
    giaiptbachai(a, b, c);

}
void giaiptbachai(int a, int b, int c)
{
    int denta;
    float x1,x2;
    denta= b*b - 4*a*c;
    x1=(-b+sqrt(denta))/(2*a);
    x2=(-b-sqrt(denta))/(2*a);
    if(denta==0)
        printf("Phuong trinh co nghiem kep x = %d\n" ,-b/(2*a));
    if(denta<0)
        printf("Phuong trinh vo nghiem\n");
    if(denta>0)
        printf("Phuong trinh co 2 nghiem phan biet x1 = %.1f va x2 = %.1f", x1,x2);
}