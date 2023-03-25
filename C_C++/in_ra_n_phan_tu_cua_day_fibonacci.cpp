#include <stdio.h>
int fibo(int n);
int main()
{
    int n,i;
    do
    {
        printf("Nhap n: ");
        scanf("%d",&n);
    }
    while(n<1);
    printf("%d phan tu cua day Fibonacci la: ",n);
    for (i=1;i<=n;i++) 
    {
        printf("%d ", fibo(i));
    }
}
int fibo(int n)
{
    int i,t1=1,t2=1,f=1;
    for(i=3;i<=n;i++)
    {
        f=t1+t2;
        t1=t2;
        t2=f;
    }
    return f;
}