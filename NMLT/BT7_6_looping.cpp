#include <stdio.h>
int main()
{
    int n,i,s=0;
    do
    {
        printf("Nhap n: ");
        scanf("%d",&n);
        if(n!=0) s+=n;
    }
    while(n!=0);
    printf("Tong = %d",s);
}