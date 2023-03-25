#include <stdio.h>
int main()
{
    int n,i;
    printf("Nhap n: ");
    scanf("%d",&n);
    printf("Cac uoc so la: ");
    for(i=1;i<=n;i++)
    {
        if(n%i==0) 
        {
            printf("%d  ", i);
        }
    }
}