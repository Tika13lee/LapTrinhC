#include <stdio.h>
int main()
{
    int n, s=0, i=0;
    do
    {
        printf("Nhap so nguyen duong n: ");
        scanf("%d", &n);
    }
    while(n<=0);
    while(s+i < n)
    {
        i++;
        s+=i;
    }
    printf("Gia tri nguyen duong k lon nhat sao cho s(k) = 1+2+...+k < n la %d\n",i);
    return 0;
}