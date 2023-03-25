#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 100
void input(int a[], int &n);
void output(int a[], int n);
int sum(int a[], int n);
int min(int a[], int n);
int tim(int a[], int n, int x);
int main()
{
    int a[MAX], n;
    input(a, n);
    output(a, n);
    //Tính tổng mảng
    printf("Tong mang la %d\n", sum(a, n));
    //Trị nhor nhất của mảng
    printf("Gia tri nho nhat cua mang la %d\n", min(a, n));
    return 0;
}
int tim(int a[], int n, int x)
{
    printf("Nhap x: ");
    scanf("%d", &x);
    if(n<0)
        return (-1);
    else if (a[n-1] == x)
        return (n-1);
}
int min(int a[], int n)
{
    if(n==1)
        return (a[0]);
    else
        return (a[n-1] < min(a, n-1) ? a[n-1] : min(a, n-1));
}
int sum(int a[], int n)
{
    if(n==0)
        return (0);
    else 
        return (a[n-1] + sum(a, n-1));
}
void input(int a[], int &n)
{
    printf("Nhap so phan tu cua mang: ");
    scanf("%d",&n);
    srand(time(NULL));
    for(int i=0; i<n; i++)
        a[i] = rand() % 100;
}
void output(int a[], int n)
{
    printf("Cac phan tu cua mang la: \n");
    for(int i=0; i<n ;i++)
        printf("Index[%d] = %d\n", i,a[i]);
    printf("\n");
}