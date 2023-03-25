#include <stdio.h>
#define MAX 100
void nhap(int a[], int &n);
void xuat(int a[], int n, int &k);
int main()
{
    int a[MAX], n, k;
    nhap(a, n);
    xuat(a, n, k);
}
void nhap(int a[], int &n)
{
    printf("Nhap so phan tu cua mang: ");
    scanf("%d", &n);
    for(int i=0; i<n; i++)
    {
        printf("a[%d] = ", i);
        scanf("%d", &a[i]);
    }
}
void xuat(int a[], int n, int &k)
{
    printf("So phan tu can in tren 1 dong: ");
    scanf("%d", &k);
    printf("Cac phan tu cua day: \n");
    int p=1;
    for(int i=0; i<n; i++)
    {
        printf("%d\t", a[i]);
        if(p%k == 0  )
            printf("\n");
        p++;
    }
    printf("\n");
}
