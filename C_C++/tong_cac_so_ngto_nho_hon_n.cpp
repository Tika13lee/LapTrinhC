#include <stdio.h>
int main()
{
    int n,i,s=0,j;
    do
    {
        printf("Nhap n: ");
        scanf("%d", &n);
    }
    while(n>=50 || n<=0);
    for(i=2;i<n;i++)
    {
        int dem=0;
        for(j=1;j<=i;j++)
        {
            if(i%j==0) dem++;
        }
        if(dem==2) s+=i;
    }
    printf("Tong la: %d", s);
    return 0;
}