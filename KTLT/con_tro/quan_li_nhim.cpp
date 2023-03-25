#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define max 100
typedef struct
{
    char *HegID, *HegSpe;
    int don_gia, so_luong;
}Hedgehog;
void input(Hedgehog HedArr[], int &n)
{
    do
    {
        printf("Nhap so luong loai nhim: ");
        scanf("%d", &n);
    }while(n<0 || n>10);
    int temp;
    char *s;
    s=(char *) malloc(80);
    for(int i=0; i<n; i++)
    {
        fflush(stdin);
        printf("\nTen loai nhim thu %d: ",i+1);  gets(s);
        HedArr[i].HegSpe = (char *) malloc(sizeof(s));
        strcpy(HedArr[i].HegSpe, s);
        printf("Ma nhim: ");    gets(s);
        HedArr[i].HegID = (char *) malloc(sizeof(s));
        strcpy(HedArr[i].HegID, s);
        printf("Don gia: "); scanf("%d", &temp);
        HedArr[i].don_gia=temp;
        printf("So luong: ");   scanf("%d", &temp);
        HedArr[i].so_luong=temp;
    }
}
void output_max(Hedgehog HedArr[], int n)
{
    int stt=1;
    int max1=HedArr[0].don_gia;
    for(int i=1; i<n; i++)
    {
        if(max1<HedArr[i].don_gia)   max1=HedArr[i].don_gia;
    }
    for(int i=0; i<n; i++)
    {
        if(HedArr[i].don_gia==max1)
            printf("\n%d \t %s \t %s \t %d \t %d\n", stt++, HedArr[i].HegID, HedArr[i].HegSpe, HedArr[i].don_gia, HedArr[i].so_luong);
    }
}
int main()
{
    Hedgehog HedArr[max];
    int n;
    input(HedArr, n);
    output_max(HedArr, n);
    return 0;
}