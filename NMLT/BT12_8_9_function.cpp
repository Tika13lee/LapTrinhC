#include <stdio.h>
#include <math.h>
void isVowel(char c)
{
    if(c=='u' || c=='e' || c=='o' || c=='a' || c=='i')
        printf("%c la nguyen am\n",c);
    else 
        printf("%c khong la nguyen am\n",c);
}
int tinhtong(int n)
{
    int i,s=0;
    for(i=1;i<=n/2;i++)
        if(n%i==0)
            s+=i;
    return s;
}
void soChinhPhuong(int a)
{
    float b=sqrt(a);
    if (b*b==a)
        printf("%d la so chinh phuong \n", a);
    else 
        printf("%d khong la so chinh phuong \n", a);
}
int main()
{
    int choice;
    do
    {
        printf("\n-------------------------------------------\n");
        printf("1_Kiem tra ky tu co phai la nguyen am hay khong.\n");
        printf("2_Tinh tong cac uoc so cua n.\n");
        printf("3_Kiem tra mot so nguyen co phai la so chinh phuong hay khong.\n");
        printf("4_Thoat.\n");
        printf("Chon chuc nang: ");
        scanf("%d",&choice);
        getchar();
        switch(choice)
        {
            case 1:
                char d;
                printf("Nhap ky tu: ");
                scanf("%c", &d);
                isVowel(d);
                break;
            case 2:
                int n,sum;
                printf("Nhap n: ");
                scanf("%d", &n);
                sum=tinhtong(n);
                printf("Tong cac uoc so cua %d la: %d\n",n,sum);
                break;
            case 3:
                int a;
                printf("Nhap so nguyen a: ");
                scanf("%d",&a);
                soChinhPhuong(a);
                break;
        }
    }
    while(choice >= 1 && choice <= 3);
}