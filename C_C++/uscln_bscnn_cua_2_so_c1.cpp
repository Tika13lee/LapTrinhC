#include <stdio.h>
int main() 
{
    int a,b,bscnn,uscln;
    printf("Nhap a, b: ");
    scanf("%d %d", &a,&b);
    if(a<b)
        bscnn=b;
    else bscnn=a;
    while(bscnn % a != 0 || bscnn %b != 0)
        bscnn++;
    printf("Boi so chung nho nhat cua %d va %d la: %d\n",a,b,bscnn);
    if(a<b)
        uscln=a;
    else uscln=b;
    while(a % uscln != 0 || b % uscln != 0)
        uscln--;
    printf("Uoc so chung nho nhat cua %d va %d la: %d\n",a,b,uscln);
    return 0;
}