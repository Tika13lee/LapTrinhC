#include <stdio.h>
int main()
{
    int n,i;
    printf("Nhap n: ");
    scanf("%d", &n);
    int t=9;
    int sum=0;
    for(i=1;i<=n;i++)
    {
        sum+=t;
        if(i<n) printf("%d+",t);
        else printf("%d\n",t);
        t=t*10+9;
    }
    printf("Tong = %d\n", sum);
    return 0;
}