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
    while(n<=0);
    float s=0;
    for(i=1;i<=n;i++)
    {
        s+=(pow(-1,i-1)/pow(2*i,2));
    }
    printf("%f", s);
    return 0;
}