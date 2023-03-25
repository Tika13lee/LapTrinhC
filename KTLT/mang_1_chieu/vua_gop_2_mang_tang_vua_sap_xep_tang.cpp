#include <stdio.h>
#define MAX 100
#include <stdlib.h>
#include <time.h>
void nhap(int a[], int &n);
void xuat(int a[], int n);
void gopmangsapxep(int a[], int n, int b[], int m, int c[], int &p);
int main() 
{
    int a[MAX], n, vt, x;
    int b[MAX], m, c[MAX], p;
    nhap(a, n);
    xuat(a, n);
    nhap(b, m);
    xuat(b, m);
    gopmangsapxep(a, n, b, m, c, p);
    xuat(c, p);
    return 0;
}
void gopmangsapxep(int a[], int n, int b[], int m, int c[], int &p)
{
    p= n + m;
    int i=0, j=0, k=0;
    while(i<n && j<m)
    {
        if(a[i] < b[j])
            c[k++] = a[i++];
        else
            c[k++] = b[j++];
    }
    while(i<n)
        c[k++] = a[i++];
    while(j<m)
        c[k++] = b[j++];
}
void nhap(int a[], int &n)
{
    printf("Nhap so luong phan tu: ");
    scanf("%d", &n);
    srand(time(NULL));
    a[0] = 0 + rand() % 11;
    for(int i=1; i<n; i++)
        a[i] = a[i-1] + rand() % 100;
}
void xuat(int a[], int n)
{
    printf("Cac phan tu cua mang la: \n");
    for(int i=0; i<n; i++)
        printf("%d\t", a[i]);
    printf("\n");
}