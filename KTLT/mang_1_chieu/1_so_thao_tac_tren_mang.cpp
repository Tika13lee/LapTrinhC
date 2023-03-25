#include <stdio.h>
#define max 100

//prototype
void nhapmang(int a[], int &n);
void xuatmang(int a[], int n);
int timkiem(int a[], int n, int x);
void hoanvi(int &a, int &b);
void sapxeptang(int a[], int n);
void them(int a[], int &n, int vt, int x);
void xoa(int a[], int &n, int vt);
int gtln(int a[], int n);

//main
int main()
{
    int a[max];
    int n,x,vt;
    nhapmang(a, n);
    xuatmang(a, n);

    //tìm kiếm 1 giá trị trong mảng 
    int t=timkiem(a, n, x);
    if(t==-1)
        printf("Khong tim thay !!!\n");
    else 
        printf("Gia tri can tim o vi tri: %d\n", t);

    //sắp xếp các giá trị trong mảng
    printf("Sau khi sap xep: \n");
    sapxeptang(a, n);
    xuatmang(a, n);

    //thêm 1 phần tử vào mảng
    them(a, n, vt, x);
    xuatmang(a, n); 

    //xóa 1 phần tử trong mảng
    xoa(a, n, vt);
    xuatmang(a, n); 

    //tìm giá trị lớn nhất trong mảng
    int l=gtln(a, n);
    printf("Gia tri lon nhat trong mang la: %d", l);


    return 0;
}

int gtln(int a[], int n)
{
    int u=a[0];
    for(int i=1; i<n; i++)
        if(a[i]>u)    u=a[i];
    return u;
}

void xoa(int a[], int &n, int vt)
{
    printf("Chon vi tri can xoa: ");
    scanf("%d", &vt);
    if(vt>=0 && vt<n)
    {
        for(int i=vt; i<n-1; i++)
            a[i]=a[i+1];
        n--;
    }
}

void them(int a[], int &n, int vt, int x)
{
    printf("Nhap gia tri can them: ");
    scanf("%d", &x);
    printf("Chon vi tri can them: ");
    scanf("%d", &vt);
    if(vt>=0 && vt<=n)
    {
        for(int i=n; i>vt; i--)
            a[i]=a[i-1];
        a[vt]=x;
        n++;
    }
}

void sapxeptang(int a[], int n)
{
    for(int i=0; i<n-1; i++)
    {
        for(int j=i+1; j<n; j++)
        {
            if(a[i] > a[j])
                hoanvi(a[i], a[j]);
        }
    }
}

void hoanvi(int &a, int &b)
{
    int temp =a;
    a=b;
    b=temp;
}

int timkiem(int a[], int n, int x)
{
    printf("Nhap gia tri can tim: ");
    scanf("%d", &x);
    for(int i=0; i<n; i++)
    {
        if(a[i]==x)
            return i;
    }
    return -1;
}

void nhapmang(int a[], int &n)
{
    printf("Nhap vao so luong phan tu: ");
    scanf("%d", &n);
    for(int i=0; i<n; i++) 
    {
        printf("a[%d] = ",i);
        scanf("%d", &a[i]);
    }
}

void xuatmang(int a[], int n)
{
    printf("Cac phan tu cua mang la: \n");
    for(int i=0; i<n; i++)
        printf("%d\t",a[i]);
    printf("\n");
}

 