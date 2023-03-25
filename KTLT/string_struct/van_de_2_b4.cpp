#include <stdio.h>
#include <string.h>
#include <math.h>
#define MAX 100

typedef struct
{
    int x, y;
}Point;

void input_one(Point &P);
void input_list(Point A[], int &n);
float P1P2(Point P1, Point P2);
float S_tamgiac(Point P1, Point P2, Point P3);
float S_dagiac(Point A[], int n);

int main()
{
    Point A[MAX];
    int n;
    printf("NHAP TOA DO n DINH CUA DA GIAC\n");
    input_list(A, n);
    printf("\nDien tich cua da giac: %.2f", S_dagiac(A, n));
}

float S_dagiac(Point A[], int n)
{
    float s=0;
    for(int i=1; i<n-1; i++)
        s+=S_tamgiac(A[0], A[i], A[i+1]);
    return s;
}
float S_tamgiac(Point P1, Point P2, Point P3)
{
    float a,b,c,p,s;
    a=P1P2(P1, P2);
    b=P1P2(P2, P3);
    c=P1P2(P1, P3);
    p=(a+b+c)/2;
    s=sqrt(p*(p-a)*(p-b)*(p-c));
    if(a+b==c || a+c==b || b+c==a)
        return 0;
    else
        return s;
}
float P1P2(Point P1, Point P2)
{
    return (sqrt(pow(P1.x - P2.x, 2) + pow(P1.y -P2.y, 2)));
}
void input_list(Point A[], int &n)
{
    do
    {
        printf("\nNhap so luong dinh cua da giac: ");
        scanf("%d", &n);
    }
    while(n<=0 || n>MAX);
    for(int i=0; i<n; i++)
        input_one(A[i]);
}
void input_one(Point &P)
{
    printf("Nhap hoanh do x= ");
    scanf("%d", &P.x);
    printf("Nhap tung do y= ");
    scanf("%d", &P.y);
}