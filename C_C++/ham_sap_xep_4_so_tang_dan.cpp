#include <stdio.h>
void sapxep(int &a,int &b);
int main()
{
    int a,b,c,d;
    printf("nhap vao 4 so nguyen: ");
    scanf("%d %d %d %d",&a,&b,&c,&d);
    sapxep(a,b);
    sapxep(a,c);
    sapxep(a,d);
    sapxep(b,c);
    sapxep(b,d);
    sapxep(c,d);
    printf("4 so sap xep tang dan la :%d %d %d %d",a,b,c,d);
}
void sapxep(int &a,int &b)
{
    if(a>b) 
    {
        int temp=a;
        a=b;
        b=temp;
    }
}