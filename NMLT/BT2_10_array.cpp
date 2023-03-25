#include <stdio.h>
#define MAX 100

void nhapmang(int a[], int &n);
int gtln(int a[], int n);
int gtnn(int a[], int n);

int main()
{
    int a[MAX];
    int n;
    nhapmang(a, n);
    printf("Phan tu lon nhat trong mang la: %d\n", gtln(a, n));
    printf("Phan tu nho nhat trong mang la: %d\n", gtnn(a, n));
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
int gtln(int a[], int n)
{
    int ln=a[0];
    for(int i=1; i<n; i++)
        if(a[i]>=ln)
            ln=a[i];
    return ln;
}
int gtnn(int a[], int n)
{
    int nn=a[0];
    for(int i=1; i<n; i++)
        if(a[i]<=nn)
            nn=a[i];
    return nn;
}