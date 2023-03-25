#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 50
void nhap(int a[], int &n);
void xuat(int a[], int n);
void tinhtb(int a[], int n);
int laSNT(int n);
int SNTdautien(int a[], int n);
int SNTlonnhat(int a[], int n);
int main()
{
    int a[MAX], n, choice;
    nhap(a, n);
    xuat(a, n);
    tinhtb(a, n);
    int kq = SNTlonnhat(a, n);
    if(kq == -1) 
        printf("Mang khong co so nguyen to\n");
    else 
        printf("So nguyen to lon nhat trong mang la %d\n", kq); 
    return 0;
}
int SNTlonnhat(int a[], int n)
{
    int ln = SNTdautien(a, n);
    if(ln == -1)
        return -1;
    for(int i=n-1; i>=0; i--)
        if(laSNT(a[i]) && a[i] > ln)
            ln = a[i];
    return ln;
}
int SNTdautien(int a[], int n)
{
    for(int i=0; i<n;i++)
        if(laSNT(a[i]))
            return a[i];
    return -1;
}
int laSNT(int n)
{
    int dem = 0;
    if(n<=1)
        return 0;
    for(int i=1; i<=n; i++)
        if(n % i == 0)
            dem++;
    if(dem == 2)
        return 1;
    return 0;
}
void tinhtb(int a[], int n)
{
    int s=0;
    float tb;
    for(int i=0; i<n; i++)
        s += a[i];
    tb = 1.0*s/n;
    printf("Gia tri trung binh cua mang la: %.1f\n", tb);
}
void nhap(int a[], int &n)
{
    printf("Nhap so luong phan tu cua mang: ");
    scanf("%d", &n);
    srand(time(NULL));
    for(int i=0; i<n; i++)
        a[i] = 1 + rand() % (10-1+1);
}
void xuat(int a[], int n)
{
    printf("Cac phan tu cua mang la: \n");
    for(int i=0; i<n; i++)
        printf("%d\t", a[i]);
    printf("\n");
}