#include <stdio.h>
#include <math.h>
int main()
{
    int n,i;
    do
    {
        printf("Nhap so nguyen duong n: ");
        scanf("%d", &n);
    }
    while(n==0);
    float s1=0,s2=0,s3=1,s4=0;
    for(i=1;i<=n;i++)
    {
        s1+=1.0*i/n;
        s2+=pow(i,2);
        s3*=1.0*(2*i-1)/(2*i);
        s4+=i*(i+1)*(i+2);
    }
    printf("S1 la: %.1f\n", s1);
    printf("S2 la: %.4f\n", sqrt(s2));
    printf("S3 la: %.6f\n", s3);
    printf("S4 la: %.0f\n", s4);
    return 0;
}