#include <stdio.h>
#define MAX 100

void nhapmang(int a[], int &n);
void xuatmang(int a[], int n);
void xuatmangnguoc(int a[], int n);

int main()
{
    int a[MAX];
    int n;
    nhapmang(a, n);
    printf("Cac phan tu cua mang: ");
    xuatmang(a, n);
    printf("\nCac phan tu cua mang theo thu tu nguoc lai: ");
    xuatmangnguoc(a, n);
    return 0;
}
void nhapmang(int a[], int &n)
{
    printf("Nhap so phan tu cua mang: ");
    scanf("%d", &n);
    for(int i=0; i<n; i++)
    {
        printf("Nhap phan tu thu %d: ", i);
        scanf("%d", &a[i]);
    }
}
void xuatmang(int a[], int n)
{
    for(int i=0; i<n; i++)
        printf("%d ", a[i]);
}
void xuatmangnguoc(int a[], int n)
{
    for(int i=n-1; i>=0; i--)
        printf("%d ", a[i]);
}