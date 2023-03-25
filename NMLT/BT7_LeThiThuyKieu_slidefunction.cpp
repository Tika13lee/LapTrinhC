#include <stdio.h>
#include <math.h>

int giaithua(int n);
void tinh(int n);

int main()
{
    int n;
    do
    {
        printf("Nhap so nguyen duong n: ");
        scanf("%d",&n);
    }
    while(n<=0);
    tinh(n);
}

int giaithua(int n)
{
    int i;
    int t=1,sum=0;
    for(i=1;i<=n;i++)
    {
        t*=i;
        sum+=t;
    }
    return sum;
}

void tinh(int n)
{
    int i,s1=0,s2=0,s4=1,s5=0;
    float s3=0;
    for(i=1;i<=n;i++)
    {
        s1+=i;
        s2+=pow(i,2);
        s3+=1.0*1/i;
        s4*=i;
        s5= giaithua(n);

    }
    printf("s1= %d\ns2= %d\ns3= %.1f\ns4= %d\ns5= %d\n",s1,s2,s3,s4,s5);
}
