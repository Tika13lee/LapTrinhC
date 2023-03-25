#include <stdio.h>
#include <math.h>
int main()
{
    int n,i;
    do
    {
        printf("Nhap so nguyen duong n: ");
        scanf("%d", &n);
    }
    while(n<0);
    int s=1;
    if(n==0) s=0;
    if(n%2!=0)
    {
        for(i=1;i<=n;i+=2)
        {
            s*=i;
        }
    }
    else
    {
        for(i=2;i<=n;i+=2)
        {
            s*=i;
        }
    }
    printf("%d",s);
    return 0;
}