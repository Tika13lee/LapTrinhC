#include <stdio.h>
#include <math.h>
int main()
{
    int n, cannguyen;
    printf("Nhap n: ");
    scanf("%d",&n);
    cannguyen=int(sqrt(n));
    if (cannguyen*cannguyen==n)
        printf("%d la so chinh phuong \n", n);
    else 
        printf("%d khong la so chinh phuong \n", n);
    return 0;
}