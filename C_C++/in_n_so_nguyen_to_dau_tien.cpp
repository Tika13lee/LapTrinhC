#include <stdio.h>
#include <math.h>
int main()
{
    int n,i,count=0,step=2;
    do
    {
        printf("Nhap so nguyen duong n: ");
        scanf("%d", &n);
    }
    while(n<=0);
    while(count!=n)
    {
        int check=1;
        for(i=2;i<= sqrt(step); i++)
        {
            if(step % i==0)
            {
                check=0;
                break;
            }
        }
        if(check ==1)
        {
            printf("%d ", step);
            count++;
        }
        step++;
    }
    return 0;
}