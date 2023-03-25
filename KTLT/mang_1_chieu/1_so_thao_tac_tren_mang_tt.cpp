#include <stdio.h>
#define MAX 100
#include <stdlib.h>
#include <time.h>
void nhap(int a[], int &n);
void xuat(int a[], int n);
void tongDuong(int a[], int n);
void xoaVitri(int a[], int &n, int vt);
void them(int a[], int &n, int vt, int x);
void tronHoanHao(int a[], int n);
void ktTonglevitrichanVStongchanvitrile(int a[], int n);
void demsochiahetcho4tancungla6(int a[], int n);

int main() 
{
    int a[MAX], n, vt, x;
    int b[MAX], m, c[MAX], p;
    nhap(a, n);
    xuat(a, n);
    //tongDuong(a, n);
    //xoaVitri(a, n, vt);
    them(a, n, vt, x);
    // tronHoanHao(a, n);
    //ktTonglevitrichanVStongchanvitrile(a, n);
    //demsochiahetcho4tancungla6(a, n);
    
    return 0;
}
void demsochiahetcho4tancungla6(int a[], int n)
{
    int dem=0;
    for(int i=0; i<n; i++)
        if(a[i] % 4 == 0 && a[i] % 10 == 6)
            dem++;
    printf("Co %d phan tu chia het cho 4 va tan cung la 6\n", dem);
}
void ktTonglevitrichanVStongchanvitrile(int a[], int n)
{
    int Sc=0, Sl=0;
    for(int i=0; i<n; i++)
    {
        if(i%2 == 0 && a[i]%2 != 0)     Sl+=a[i];
        if(i%2 != 0 && a[i]%2 == 0)     Sc+=a[i];
    }
    if(Sc==Sl)
        printf("Tong le o vi tri chan (%d) bang tong chan o vi tri le (%d)\n", Sl, Sc);
    else
        printf("Tong le o vi tri chan (%d) khac tong chan o vi tri le (%d)\n", Sl, Sc);
}
void tronHoanHao(int a[], int n)
{
    int t[MAX];
    for(int i=0; i<n/2; i++)
    {
        t[2*i] = a[i];
        t[2*i + 1] = a[n/2 + i];
    }
    xuat(t, n);
}
void them(int a[], int &n, int vt, int x)
{
    printf("Nhap vi tri can them: ");
    scanf("%d", &vt);
    printf("Nhap gia tri can them: ");
    scanf("%d", &x);
    if(vt >= 0 && vt <= n)
    {    
        for(int i=n; i>vt; i--)
            a[i] = a[i-1];
        a[vt] = x;
        n++;
    }
    xuat(a, n);
}
void xoaVitri(int a[], int &n, int vt)
{
    printf("Nhap vi tri can xoa: ");
    scanf("%d", &vt);
    if(vt >= 0 && vt <= n)
    {
        for(int i=vt; i<n-1; i++)
            a[i] = a[i+1];
        n--;
    }
    xuat(a, n);
}
void tongDuong(int a[], int n)
{
    int sum=0;
    for(int i=0; i<n; i++)
        if(a[i] > 0)
            sum+=a[i];
    printf("Tong cac so nguyen duong co trong mang la: %d\n", sum);
}
void nhap(int a[], int &n)
{
    printf("Nhap so luong phan tu: ");
    scanf("%d", &n);
    srand(time(NULL));
    for(int i=0; i<n; i++)
        a[i] = rand() % 201;
}
void xuat(int a[], int n)
{
    printf("Cac phan tu cua mang la: \n");
    for(int i=0; i<n; i++)
        printf("%d\t", a[i]);
    printf("\n");
}
