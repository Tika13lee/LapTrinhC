#include <stdio.h>
void ISBN(int n);
int main()
{
    int n;
    printf("Nhap n: ");
    scanf("%d", &n);
    ISBN(n);
    return 0;
}
void ISBN(int n)
{
    int sum=0;
    for(int i=1; i<11; i++)
    {
        int chs;
        chs=n%10;
        chs*=i;
        sum+=chs;
        n/=10;
    }
    sum+=(n%10);
    if(sum%11==0)
        printf("Valid\n");
    else
        printf("Invalid\n");
}