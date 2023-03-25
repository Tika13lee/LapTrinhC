#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#define MAX 100
void input(int Q[], int &n)
{
    printf("Nhap so phan tu n: ");
    scanf("%d", &n);
    srand(time(NULL));
    for(int i=0; i<n; i++)
        Q[i] = 1 + rand()%(100);
}
void output(int Q[], int n)
{
    printf("Cac phan tu cua mang: \n");
    for(int i=0; i<n; i++)
        printf("%d\t", Q[i]);
    printf("\n");
}
long sum_rec(int Q[], int n)
{
    if(n==0)
        return (0);
    return (Q[n-1] + sum_rec(Q, n-1));
}
int max_rec(int Q[], int n)
{
    if(n==1)
        return (Q[0]);
    return (Q[n-1] > max_rec(Q, n-1) ? Q[n-1] : max_rec(Q, n-1));
}
int min_rec(int Q[], int n)
{
    if(n==1)
        return (Q[0]);
    return (Q[n-1] < min_rec(Q, n-1) ? Q[n-1] : min_rec(Q, n-1));
}
int main()
{
    int Q[MAX], n;
    input(Q, n);
    output(Q, n);
    printf("Tong cac phan tu trong mang la : %d\n", sum_rec(Q, n));
    printf("Phan tu lon nhat trong mang la: %d\n", max_rec(Q, n));
    printf("Phan tu nho nhat trong mang la: %d\n", min_rec(Q, n));
    return 0;
}