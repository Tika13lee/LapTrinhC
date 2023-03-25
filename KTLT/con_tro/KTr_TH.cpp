#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define max 100
typedef struct 
{
    char *ma_mh;
    char *ten_mh;
    int so_tc_lt;
    int so_tc_th;
}monhoc;

int dinhvi(monhoc DSMH[], int n, char *Bma_mh);
void input_list(monhoc DSMH[], int &n);
void output_list(monhoc DSMH[], int n);
void del_mh(monhoc DSMH[], int &n, char *Dma_mh);
void output_lythuyet(monhoc DSMH[], int n);
int main()
{
    monhoc DSMH[max];
    int n, chon;
    char *Dma_mh;
    do
    {
        printf("\n*******MENU*******\n");
        printf("1. Nhap du lieu danh sach mon hoc\n");
        printf("2. Xuat du lieu danh sach mon hoc\n");
        printf("3. Xoa mon hoc\n");
        printf("4. In danh sach mon hoc chi co tin chi ly thuyet\n");
        printf("5. Ket thuc\n");
        printf("BAN CHON ? ");
        scanf("%d", &chon);
        switch (chon)
        {
            case 1:
                input_list(DSMH, n);
                break;
            case 2:
                output_list(DSMH, n);
                break;
            case 3:
                Dma_mh = (char *) malloc(30);
                fflush(stdin);
                printf("\nNhap ma mon hoc can xoa: ");   gets(Dma_mh);
                del_mh(DSMH, n, Dma_mh);
                output_list(DSMH, n);
                break;
            case 4:
                output_lythuyet(DSMH, n);
                break;
            case 5:
                break;
            default:
                printf("Sai chuc nang, vui long chon lai !\n");
                break;
        }
    }while(chon>5 || chon<5);
    return 0;
}
int dinhvi(monhoc DSMH[], int n, char *Bma_mh)
{
    int i=0;
    while(i<n && strcmp(DSMH[n].ma_mh, Bma_mh) != 0)     i++;
    if(i<n)
        return (i);
    else   return (-1);
}
void input_list(monhoc DSMH[], int &n)
{
    n=0;
    bool check;
    char *s;
    s = (char *) malloc(100);
    int dk,temp;
    printf("\n*****NHAP DANH SACH MON HOC*****\n");
    do
    {
        printf("\nMon hoc thu %d\n", n+1);
        do
        {
        	check = 0;
            fflush(stdin);
            printf("Ma mon hoc: ");     gets(s);
            for(int i=0; i<n; i++)
            {
                if(strcmp(DSMH[i].ma_mh, s) == 0 )
                {
                    check = 1;
                    break;
                }
            }
        }while(check);
        dk = strcmp(s, "\0");
        if(dk != 0)
        {
            DSMH[n].ma_mh = (char *) malloc(sizeof(s));
            strcpy(DSMH[n].ma_mh, s);
            printf("Ten mon hoc: ");    gets(s);
            DSMH[n].ten_mh = (char *) malloc(sizeof(s));
            strcpy(DSMH[n].ten_mh, s);
            do
            {
                printf("So tin chi li thuyet: ");
                scanf("%d", &temp);
            }while(temp<0);
            DSMH[n].so_tc_lt = temp;
            do
            {
                printf("So tin chi thuc hanh: ");
                scanf("%d", &temp);
            }while(temp<0);
            DSMH[n].so_tc_th = temp;
            n++;
        }
    }while(dk != 0);
}
void output_list(monhoc DSMH[], int n)
{
    printf("\nDANH SACH MON HOC\n");
    printf("\n");
    printf("\nSTT \t MA MON HOC \t TEN MON HOC \t SO_TC_LT \t SO_TC_TH\n");
    for(int i=0; i<n; i++)
    {
        printf("\n%d \t %s \t\t %s \t %d \t\t %d\n", i+1, DSMH[i].ma_mh, DSMH[i].ten_mh, DSMH[i].so_tc_lt, DSMH[i].so_tc_th); 
    }
}
void del_mh(monhoc DSMH[], int &n, char *Dma_mh)
{
    for(int i=0; i<n; i++)
    {
        if(strcmp(DSMH[i].ma_mh, Dma_mh) == 0)
        {
            for(int j=i; j<n-1; j++)
            {
                DSMH[j].ma_mh = DSMH[j+1].ma_mh;
                DSMH[j].ten_mh = DSMH[j+1].ten_mh;
                DSMH[j].so_tc_lt = DSMH[j+1].so_tc_lt;
                DSMH[j].so_tc_th = DSMH[j+1].so_tc_th;
            }
            n--;
        }
    }
}
void output_lythuyet(monhoc DSMH[], int n)
{
	int stt=1;
    printf("\n+------------+--------------------------------+------------+\n");
    printf("| %-10s | %-30s | %-10s |\n", "STT", "TEN MON HOC", "SO TC LT");
    for(int i=0; i<n; i++)
    {
        if(DSMH[i].so_tc_lt>0 && DSMH[i].so_tc_th==0)
        {
            printf("\n+------------+--------------------------------+------------+\n");
            printf("| %-10d | %-30s | %-10d |\n", stt++, DSMH[i].ten_mh, DSMH[i].so_tc_lt); 
        }
    }
    printf("\n+------------+--------------------------------+------------+\n");
}
