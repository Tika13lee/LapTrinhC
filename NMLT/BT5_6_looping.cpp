#include <stdio.h>
int main() 
{
    int a,b,uscln;
    printf("Nhap a, b: ");
    scanf("%d %d", &a,&b);
    if(a<b)
        uscln=a;
    else uscln=b;
    while(a%uscln!=0 || b%uscln!=0)
        uscln--;
    printf("Uoc so chung lon nhat cua %d va %d la: %d\n",a,b,uscln);
    return 0;
}