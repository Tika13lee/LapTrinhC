#include <stdio.h>
int gtnn(int a, int b, int c, int d);
int main()
{
    int a, b, c, d, min;
    printf("Nhap a, b, c, d: ");
    scanf("%d %d %d %d", &a,&b,&c,&d);
    min=gtnn(a, b, c, d);
    printf("Gia tri nho nhat la: %d\n", min);
}
int gtnn(int a, int b, int c, int d)
{
    int min=a;
    if(min>=b) min=b;
    if(min>=c) min=c;
    if(min>=d) min=d;
    return min;
}