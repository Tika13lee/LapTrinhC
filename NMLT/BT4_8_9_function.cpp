#include <stdio.h>
int tinhGiaiThua(int n);
int main()
{
    int n,i;
    do
    {
        printf("Nhap so nguyen duong n: ");
        scanf("%d", &n);
    }
    while(n<=0);
    int t=tinhGiaiThua(n);
    printf("Giai thua cua %d la: %d\n", n,t);
    return 0;
}
int tinhGiaiThua(int n)
{
    int i;
    int p=1;
    for(i=2;i<=n;i++)
    {
        p*=i;
    }
    return p;
}