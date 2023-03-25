#include <stdio.h>
#include <stdlib.h>
int main()
{
    int n,m;
    float *A, *B;
    printf("Nhap so luong sinh vien lop DHTH17A: ");
    scanf("%d", &n);
    printf("Nhap so luong sinh vien lop DHTH17B: ");
    scanf("%d", &m);
    A = (float *) calloc(n, sizeof(int));
    B = (float *) calloc(m, sizeof(int));
    printf("\n***Nhap diem cho sinh vien lop DHTH17A***\n");
    for(int i=0; i<n; i++)
    {
        do
        {
            printf("Sinh vien thu %d: ", i+1);
            scanf("%f", A+i);
        }while(*(A+i) <= 0 || *(A+i) > 10);
    }
    printf("\n***Nhap diem cho sinh vien lop DHTH17B***\n");
    for(int i=0; i<m; i++)
    {
        do
        {
            printf("Sinh vien thu %d: ", i+1);
            scanf("%f", B+i);
        }while(*(B+i) <= 0 || *(B+i) > 10);
    }
    int demA=0, demB=0;
    for(int i=0; i<n; i++)
    {
        if(*(A+i)<3)
            demA++;
    }
    for(int i=0; i<m; i++)
    {
        if(*(B+i)<3)
            demB++;
    }
    float tlA = 100*(1.0*demA)/n;
    float tlB = 100*(1.0*demB)/m;
    printf("Ti le sinh vien hoc lai cua lop DHTH17A la: %.2f\n", tlA);
    printf("Ti le sinh vien hoc lai cua lop DHTH17B la: %.2f\n", tlB);
    tlA > tlB ? printf("Ti le sinh vien lop 17A hoc lai nhieu hon\n") : printf("Ti le sinh vien lop 17B hoc lai nhieu hon\n");
    return 0;
}