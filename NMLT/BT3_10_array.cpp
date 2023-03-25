#include <stdio.h>
#define MAX 100

void nhapmang(int a[], int &n);
void xuatmang(int a[], int n);
void gopmang(int a[], int na, int b[], int nb, int c[], int &nc);
void hoanvi(int &a, int &b);
void sapxepgiam(int a[], int n);

int main()
{
    int a[MAX], b[MAX], c[MAX];
    int na,nb,nc;
    nhapmang(a, na);
    nhapmang(b, nb);
    gopmang(a, na, b, nb, c, nc);
    printf("Sau khi sap xep: \n");
    sapxepgiam(c, nc);
    xuatmang(c, nc);

}
void nhapmang(int a[], int &n)
{
    printf("Nhap so phan tu cua mang: ");
    scanf("%d", &n);
    for(int i=0; i<n; i++)
    {
        printf("Nhap phan tu thu %d: ",i);
        scanf("%d", &a[i]);
    }
}
void xuatmang(int a[], int n)
{
    for(int i=0; i<n; i++)
        printf("%d ", a[i]);
}
void gopmang(int a[], int na, int b[], int nb, int c[], int &nc)
{
    nc=0;
    for(int i=0; i<na; i++)
    {   
        c[nc]=a[i];
        nc++;
    }
    for(int i=0; i<nb; i++)
    {    
        c[nc]=b[i];
        nc++;
    }
}
void hoanvi(int &a, int &b)
{
    int temp=a;
    a=b;
    b=temp;
}
void sapxepgiam(int a[], int n)
{
    for(int i=0; i<n-1; i++)
    {
        for(int j=i+1; j<n; j++)
        {
            if(a[i] < a[j])
                hoanvi(a[i], a[j]);
        }
    }
}