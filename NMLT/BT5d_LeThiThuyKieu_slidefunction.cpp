#include <stdio.h>
int soln(int a, int b, int c, int d);
int main()
{
    int a,b,c,d,max;
    printf("Nhap a, b, c, d: ");
    scanf("%d %d %d %d", &a,&b,&c,&d);
    int t=soln(a, b, c, d);
    printf("So lon nhat la: %d\n", t);
}
int soln(int a, int b, int c, int d)
{
    int max=a;
    if(b>=max) max=b;
    if(c>=max) max=c;
    if(d>=max) max=d;
    return max;
}