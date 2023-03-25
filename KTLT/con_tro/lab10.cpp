#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define max 100
typedef struct 
{
    char *ma_mh, *ten_mh;
    int so_tc;
}monhoc;
typedef char mamonhoc[20];
typedef struct 
{
    char *ma_gv, *hoten_gv;
    int so_luong_mon;
    mamonhoc DSMMH[max];
}giangvien;
void input_mh(monhoc DSMH[], int &n);
void output_mh(monhoc DSMH[], int n);
int dinhvi(monhoc DSMH[], int n, char *Bma_mh);
void xoa_mon_hoc(monhoc DSMH[], int &n, char *x);
void input_gv(giangvien DSGV[], int &m, monhoc DSMH[], int n);
monhoc find(monhoc DSMH[], int n, char *Bma_mh);
void danh_sach_mon_cua_gv(giangvien DSGV[], int m, char *Bma_gv, monhoc DSMH[], int n);
void danh_sach_gv(giangvien DSGV[], int m, char *Bma_mh);
int main()
{
    monhoc DSMH[max];
    giangvien DSGV[max];
    int n,m;
    char *x, *Bma_gv, *Bma_mh;
    input_mh(DSMH, n);
    output_mh(DSMH, n);

    // x = (char *) malloc(20);
    // printf("Nhap ma mon hoc can xoa: ");    gets(x);
    // xoa_mon_hoc(DSMH, n, x);
    // output_mh(DSMH, n);
    
    input_gv(DSGV, m, DSMH, n);

    Bma_gv = (char *) malloc(20);
    printf("\nNhap ma giang vien can biet thong tin: ");     gets(Bma_gv);
    danh_sach_mon_cua_gv(DSGV, m, Bma_gv, DSMH, n);

    Bma_mh = (char *) malloc(20);
    printf("\nNhap ma mon can biet thong tin: ");   gets(Bma_mh);
    danh_sach_gv(DSGV, m, Bma_mh);
    return 0;
}
void input_mh(monhoc DSMH[], int &n)
{
    n=0;
    bool check;
    char *s;
    int dk, temp;
    s = (char *) malloc(50);
    printf("\nNHAP DANH SACH MON HOC\n");
    do
    {
        printf("\nMon hoc thu %d\n", n+1);
        do
        {
            check=0;
            fflush(stdin);
            printf("Ma mon hoc: ");    gets(s);
            for(int i=0; i<n; i++)
            {
                if(strcmp(DSMH[i].ma_mh, s) == 0)
                {
                    check = 1;
                    break;
                }
            }
        }while (check);
        dk = strcmp(s, "\0");
        if(dk != 0)
        {
            DSMH[n].ma_mh = (char *) malloc(sizeof(s));
            strcpy(DSMH[n].ma_mh, s);
            printf("Ten mon hoc: ");   gets(s);
            DSMH[n].ten_mh = (char *) malloc(sizeof(s));
            strcpy(DSMH[n].ten_mh, s);
            do
            {
                printf("So tin chi: ");
                scanf("%d", &temp);
            }while (temp<=0);
            DSMH[n].so_tc = temp;
            n++;
        }
    }while(dk != 0);
}
void output_mh(monhoc DSMH[], int n)
{
    printf("\n****DANH SACH MON HOC****\n");
    printf("\n");
    printf("STT \t Ma mon hoc \t Ten mon hoc \t\t So tin chi\n");
    for(int i=0; i<n; i++)
        printf(" %d \t %s \t\t %s \t\t %d\n", i+1, DSMH[i].ma_mh, DSMH[i].ten_mh, DSMH[i].so_tc);
}
int dinhvi(monhoc DSMH[], int n, char *Bma_mh)
{
    int i=0;
	while(i<n &&strcmp(DSMH[i].ma_mh,Bma_mh)!=0)    i++;
	if(i<n)
        return(i);
    else return(-1);
}
void xoa_mon_hoc(monhoc DSMH[], int &n, char *x)
{
    for(int i=0; i<n; i++)
    {
        if(strcmp(DSMH[i].ma_mh, x) != 0)
            printf("Ma mon hoc khong ton tai\n");
        else
        {
            for(int j=i; j<n-1; j++)
                DSMH[j].ma_mh= DSMH[j+1].ma_mh;
            n--;
        }
    }
}
void input_gv(giangvien DSGV[], int &m, monhoc DSMH[], int n)
{
    m=0;
    char *s;
    int dk1, dk2, temp;
    s = (char *) malloc(50);
    printf("\n NHAP DANH SACH GIANG VIEN\n");
    do
    {
        printf("\nGiang vien thu %d\n", m+1);
        fflush(stdin);
        printf("Ma giang vien: ");     gets(s);
        dk1 = strcmp(s, "\0");
        if(dk1 != 0)
        {
            DSGV[m].ma_gv = (char *) malloc(sizeof(s));
            strcpy(DSGV[m].ma_gv, s);
            printf("Ten giang vien: ");    gets(s);
            DSGV[m].hoten_gv = (char *) malloc(sizeof(s));
            strcpy(DSGV[m].hoten_gv, s);
            printf("So luong mon hoc cua giang vien: ");
            scanf("%d", &temp);
            DSGV[m].so_luong_mon = temp;
            printf("Danh sach mon hoc giang vien dam nhan\n");
            for(int i=0; i < DSGV[m].so_luong_mon; i++)
            {
                do
                {
                    fflush(stdin);
                    printf("Nhap ma mo hoc thu %d: ", i+1);     gets(s);
                    dk2 = dinhvi(DSMH, n, s);
                    if(dk2!=-1)
                        strcpy(DSGV[m].DSMMH[i], s);
                }while (dk2==-1);
            }
            m++;
        }
    }while(dk1!=0);
}
monhoc find(monhoc DSMH[], int n, char *Bma_mh)
{
    for(int i=0; i<n; i++)
    {
        if(strcmp(DSMH[i].ma_mh, Bma_mh) == 0)
            return DSMH[i];
    }
}
void danh_sach_mon_cua_gv(giangvien DSGV[], int m, char *Bma_gv, monhoc DSMH[], int n)
{
    printf("\n+------------+--------------------------------+-------------\n");
    printf("| %-10s | %-30s | %-10s |\n", "STT", "TEN MON HOC", " SO TC");
    for(int i=0; i<m; i++)
    {
        if(strcmp(DSGV[i].ma_gv, Bma_gv) == 0)
        {
            for(int k=0; k<DSGV[i].so_luong_mon; k++)
            {
                char *temp = DSGV[i].DSMMH[k];
                monhoc mh = find(DSMH, n, temp);
                printf("\n+------------+--------------------------------+-------------\n");
                printf("| %-10d | %-30s | %-10d |\n", k+1, mh.ten_mh, mh.so_tc);
            }
            printf("\n+------------+--------------------------------+-------------\n");
            break;
        }
    }
}
void danh_sach_gv(giangvien DSGV[], int m, char *Bma_mh)
{
    int stt=1;
    printf("\n+------------+--------------------------------+-------------\n");
    printf("| %-10s | %-30s | %-10s |\n", "STT", "TEN GIANG VIEN", "MA GV");
    for(int i=0; i<m; i++)
    {
        for(int j=0; j<DSGV[i].so_luong_mon; j++)
        {
            if(strcmp(DSGV[i].DSMMH[j], Bma_mh) == 0)
            {
                printf("\n+------------+--------------------------------+-------------\n");
                printf("| %-10d | %-30s | %-10s |\n", stt++, DSGV[i].hoten_gv, DSGV[i].ma_gv);
            }
        }
    }
    printf("\n+------------+--------------------------------+-------------\n");
}
