#include <stdio.h>
int gcd(int a, int b);
int lcm(int a, int b);
int main()
{
    int a,b;
    do
    {
        printf("Nhap 2 so nguyen duong: ");
        scanf("%d %d", &a,&b);
    }
    while(a<=0 || b<=0);
    int d=gcd(a,b);
    int m=lcm(a,b);
    printf("Uoc so chung lon nhat cua %d va %d la: %d\n",a,b,d);
    printf("Boi so chung nho nhat cua %d va %d la: %d\n",a,b,m);
}
int gcd(int a, int b)
{
    while(a!=b)
        if(a>b)
            a-=b;
        else
            b-=a;
    return a;
}
int lcm(int a, int b)
{
    return a*b/gcd(a,b);
}