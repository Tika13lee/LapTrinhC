#include <stdio.h>
void nhiphan(int n)
{
    if(n>=0)
    {
        if(n/2 > 0)
            nhiphan(n/2);
        printf("%d", n%2);
    }
    
}
int main()
{
    int n;
    do
    {
        printf("Nhap so nguyen duong n: ");
        scanf("%d", &n);
    }
    while(n<=0);
    nhiphan(n);
    return 0;
}