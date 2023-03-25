#include<stdio.h>
int tong(int n)
{
    int t=0;
    while(n>0)
    {
        t += n % 10;
        n/=10;
    }
    return (t);
}
int main()
{
    int n;
    printf("Nhap n: ");
    scanf("%d", &n);
    printf("Kq = %d\n", tong(n));
    return 0;
}