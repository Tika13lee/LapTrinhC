#include <stdio.h>
#include <math.h>
#define MAX 100

void nhapmang(int arr[], int &n);
void xuatmang(int arr[], int n);
int laSNT(int n);
void inSNT(int arr[], int n);
void ingiatritrongkhoang(int arr[], int n, int &a, int &b);
int tong(int arr[], int n);
int lasochan(int n);
int tongchan(int arr[], int n);
void them(int arr[], int &n, int P, int X);
void xoa(int arr[], int &n, int P);
int timkiem(int arr[], int n, int Y);

int main()
{
    int arr[MAX];
    int n;
    nhapmang(arr, n);
    xuatmang(arr, n);
    printf("\n");
    
    inSNT(arr, n);
    printf("\n");
    
    int a,b;
    ingiatritrongkhoang(arr, n, a, b);
    printf("\n");

    int s1,s2;
    s1=tong(arr, n);
    printf("Tong cac gia tri trong mang la: %d\n",s1);
    s2=tongchan(arr, n);
    printf("Tong cac so chan trong mang la: %d\n",s2);

    int P,X;
    them(arr, n, P, X);
    xuatmang(arr, n);
    printf("\n");

    int P1;
    xoa(arr, n, P1);
    xuatmang(arr, n);
    printf("\n");

    int Y,t,i;
    t=timkiem(arr, n, Y);
    if(t==-1)
        printf("Khong tim thay !!!");
    else
        printf("Gia tri can tim o vi tri: %d",t);
}

int timkiem(int arr[], int n, int Y)
{
    printf("Nhap gia tri Y can tim: ");
    scanf("%d", &Y);
    for(int i=0; i<n; i++)
    {
        if(arr[i]==Y)
            return i;
    }
    return -1;
}
void xoa(int arr[], int &n, int P)
{
    printf("Nhap vi tri can xoa: ");
    scanf("%d", &P);
    if(P>=0 && P<=n)
    {
        for(int i=P; i<n-1; i++)
            arr[i]=arr[i+1];
        n--;
    }
}
void them(int arr[], int &n, int P, int X)
{
    printf("Nhap gia tri X can them: ");
    scanf("%d", &X);
    printf("Nhap vi tri can them: ");
    scanf("%d", &P);
    if(P>=0 && P<=n)
    {
        for(int i=n; i>P; i--)
            arr[i]=arr[i-1];
        arr[P]=X;
        n++;
    }
}
int tong(int arr[], int n)
{
    int s=0;
    for(int i=0; i<n; i++)
        s+=arr[i];
    return s;
}
int lasochan(int n)
{
    if(n%2==0)
        return 1;
    return 0;
}
int tongchan(int arr[], int n)
{
    int s=0;
    for(int i=0; i<n; i++)
    {
        if(lasochan(arr[i]))
            s+=arr[i];
    }
    return s;
}
void ingiatritrongkhoang(int arr[], int n, int &a, int &b)
{
    do
    {
        printf("Nhap a, b (0<a<b<n): ");
        scanf("%d %d", &a,&b);
    }
    while(a<0 || a>b || b>n);
    printf("Cac phan tu co gia tri nam trong khoang [%d,%d] la: ",a,b);
    for(int i=a; i<=b; i++)
        printf("%d ", arr[i]);
}
void inSNT(int arr[], int n)

{
    printf("Cac so nguyen to co trong mang la: ");
    for(int i=0; i<n; i++)
    {
        if(laSNT(arr[i])==1)
            printf("%d ",arr[i]);
    }
}
int laSNT(int n)
{
    int m=sqrt(n);
    if(n<2)
        return 0;
    for(int i=2; i<=m; i++)
        if(n%i==0)
            return 0;
    return 1;
}
void nhapmang(int arr[], int &n)
{
    printf("Nhap vao so luong phan tu: ");
    scanf("%d", &n);
    for(int i=0; i<n; i++) 
    {
        printf("Nhap phan tu thu %d: ",i);
        scanf("%d", &arr[i]);
    }
}
void xuatmang(int arr[], int n)
{
    for(int i=0; i<n; i++)
        printf("%d ",arr[i]);
}