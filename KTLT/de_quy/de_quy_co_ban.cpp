#include <stdio.h>
#include <conio.h>
int sobeo(int n);
int giaithua(int n);
int csc(int n, int a, int r);
int csn(int n, int a, int q);
int fibo(int n);
int F(int n);
int G(int n);
int DS(int n);
int main()
{
    int n;
    printf("Nhap n: ");
    scanf("%d", &n);
    //Tính số bèo hoa dâu trong n ngày 
    printf("So beo trong %d ngay la %d\n", n, sobeo(n));
    //Tính giai thừa của số n
    printf("Giai thua cua %d la %d\n", n, giaithua(n));
    //Tính trị phần tử thứ n của 1 cấp số cộng có số hạng đầu là a, công sai là r
    int a, r;
    printf("Nhap so hang dau a: ");
    scanf("%d",&a);
    printf("Nhap cong sai r: ");
    scanf("%d",&r);
    printf("Phan tu thu %d cua 1 cap so cong la %d\n", n, csc(n, a, r));
    //Tính trị phần tử thứ n của 1 cấp số nhân có số hạng đầu là a, công bội là q
    int q;
    printf("Nhap cong boi q: ");
    scanf("%d", &q);
    printf("Phan tu thu %d cua 1 cap so nhan la %d\n", n, csn(n, a, q));
    //Tìm số fibonacci thứ n 
    printf("So fibonacci thu %d la %d\n",n, fibo(n));
    //Ví dụ về đệ qui tương hỗ 
    printf("F(%d) la %d\n",n,F(n));
    //Đếm số chữ số nguyên dương
    printf("So chu so cua n la: %d\n", DS(n));
    return 0;
}
int DS(int n)
{
    if(n<10)
        return (1);
    else
        return (DS(n/10) +1);
}
int F(int n)
{
    if(n<=1)
        return (1);
    else
        return (n * G(n-1));
}
int G(int n)
{
    if(n==0)
        return (0);
    else 
        return (n + F(n-1));
}
int fibo(int n)
{
    if(n==1 || n==2)
        return (1);
    else
        return (fibo(n-2) + fibo(n-1));
}
int csn(int n, int a, int q)
{
    if(n==1)
        return (a);
    else
        return (q * csn(n-1, a, q));
}
int csc(int n, int a, int r)
{
    if(n==1)
        return (a);
    else
        return (r + csc(n-1, a, r));
}
int giaithua(int n)
{
    if(n==1)
        return (1);
    else
        return (n*giaithua(n-1));
}
int sobeo(int n)
{
    if(n==0)
        return (1);
    else
        return (2*sobeo(n-1));
}