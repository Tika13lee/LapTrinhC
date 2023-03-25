#include <stdio.h>
#include <string.h>
#include <math.h>

typedef struct
{
    int ts,ms;
}PS;
PS p;

void input(PS &phanso);
void output(PS phanso);
int UCLN(int a, int b);
void toigian(PS &phanso);
int main()
{
    PS p;
    printf("Nhap phan so\n");
    input(p);
    printf("\nPhan so vua nhap: ");
    output(p);
    toigian(p);
    printf("\nPhan so sau khi toi gian: ");
    output(p);
    return 0;
}
void toigian(PS &phanso)
{
    int t=UCLN(abs(phanso.ts),abs(phanso.ms));
    phanso.ts/=t;
    phanso.ms/=t;
}
int UCLN(int a, int b)
{
    if(a==b)
        return a;
    else if(a>b)
        return (UCLN(a-b,b));
    else
        return (UCLN(a,b-a));
}
void input(PS &phanso)
{
    printf("Nhap tu so: ");
    scanf("%d", &phanso.ts);
    do
    {
        printf("Nhap mau so: ");
        scanf("%d", &phanso.ms);
    }
    while(phanso.ms <= 0);
}
void output(PS phanso)
{
    printf("%d/%d\n", phanso.ts, phanso.ms);
}