#include <stdio.h>
double fibo(int n);
int main()
{
    int n;
    do 
    {
        printf("Nhap so nguyen duong n: ");
        scanf("%d", &n);
    }
    while(n<1);
    int t=fibo(n);
    printf("So hang thu %d cua day so Fibonacci la: %d\n",n,t);
}
double fibo(int n)
{
    int t1=1,t2=1,f=1,i;
    for(i=3;i<=n;i++)
    {
        f=t1+t2;
        t1=t2;
        t2=f;
    }
    return f;
}