#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define max 100
int n = 0, m = 0;

typedef struct 
{
    char *ma_mh;
    char *ten_mh;
    int so_tc;
}_monhoc;
_monhoc DSMH[max];

typedef struct 
{
    char *ma_gv;
    char *hoten_gv;
    char *DSMGV[max];
    int soluong_MGV = 0;
} _giangvien;
_giangvien DSGV[max];

void input_list1(int &n);
void input_list2(int &m);
void output_list1(int n);
int dinhvi(_monhoc DSMH[], int n, char *Bma_mh);
void danh_sach_mon_cua_gv(_giangvien DSGV[], char *Bmagv);
void danh_sach_giangvien(_giangvien DSGV[], char *Bma_mon);

int main () {
    input_list1(n);
    output_list1(n);
    input_list2(m);
    char *st;
    st = (char*) malloc (30);
    fflush(stdin);
    printf("Nhap ma gv can tim: ");
    gets(st);
    danh_sach_mon_cua_gv(DSGV, st);
    printf("Nhap ma mon hoc can tim: ");
    gets(st);
    danh_sach_giangvien(DSGV, st);
}

void input_list1(int &n) 
{
    int t;
    bool check;
    char *st;
    st = (char*) malloc (30);
    printf("\tNHAP THONG TIN MON HOC\n");
    do {
        fflush(stdin);
        printf("Nhap du lieu mon hoc thu %d: \n", n+1);
        do {
            check = 0;
            printf("Nhap ma mon hoc: "); gets(st);
            for (int i = 0; i < n; i++) {
                if (strcmp(DSMH[i].ma_mh, st) == 0) {
                    check = 1;
                    break;
                }
            }
        } while(check);
        t = strcmp(st, "\0");
        if (t) {
            DSMH[n].ma_mh = (char*) malloc (sizeof(st));
            strcpy(DSMH[n].ma_mh, st);
            printf("Nhap ten mon hoc: "); gets(st);
            DSMH[n].ten_mh = (char*) malloc (sizeof(st));
            strcpy(DSMH[n].ten_mh, st);
            printf("Nhap so tin chi: "); scanf("%d", &DSMH[n].so_tc);
            n++;
        }
    } while (t);
}

void input_list2(int &m) 
{
    int t1,t2,tmp;
    bool check1, check2;
    char *st;
    st = (char*) malloc (30);
    printf("\tNHAP THONG TIN GIANG VIEN\n");
    do {
        fflush(stdin);
        printf("\nNhap du lieu giang vien thu %d: \n", m+1);
        do {
            check1 = 0;
            printf("Nhap ma giang vien: "); gets(st);
            t1 = strcmp(st, "\0");
            if (!t1) break;
            for (int i = 0; i < m; i++) {
                if (strcmp(DSGV[i].ma_gv, st) == 0) {
                    check1 = 1;
                    break;
                }
            }
        } while(check1);
        if (t1) {
            DSGV[m].ma_gv = (char*) malloc (sizeof(st));
            strcpy(DSGV[m].ma_gv, st);
            printf("Nhap ho ten giang vien: "); gets(st);
            DSGV[m].hoten_gv = (char*) malloc (sizeof(st));
            strcpy(DSGV[m].hoten_gv, st);
            //nhap mon gv dang ky
            do {
                check1 = 0;
                check2 = 0;
                //nhap va kiem tra mon nhap cua gv
                do 
                {
                    printf("Nhap ma mon giang vien day thu %d: ", DSGV[m].soluong_MGV+1);
                    gets(st);
                    t2 = strcmp(st, "\0");
                    if (!t2) break;
                    //kiem tra co mon trong DSMH khong?
                    for (int i = 0; i < n; i++) {
                        if (strcmp(DSMH[i].ma_mh,st) == 0) check2 = 1;
                    }
                    //Kiem tra GV dang ki mon truoc do chua?
                    for (int i = 0; i < DSGV[m].soluong_MGV; i++)
                        if (strcmp(DSGV[m].DSMGV[i],st) == 0) check1 = 1;
                    if (!check1 && check2) {
                        int sl = DSGV[m].soluong_MGV;
                        DSGV[m].DSMGV[sl] = (char*) malloc (sizeof(st));
                        strcpy(DSGV[m].DSMGV[sl],st);
                        DSGV[m].soluong_MGV++;
                    }
                } while (check1 || !check2);

            }while(t2);
            m++;
        }
    } while (t1);
    printf("\n");
}

void output_list1(int n)
{
	printf("\n                DANH SACH MON HOC");
	printf("\n|\tSTT\t|\tMa MH\t|\tTen mon hoc\t\t|\tSo TC\t|");
	for(int i=0; i<n; i++)printf("\n|\t%d\t|\t%s\t|\t%s\t|\t%d\t|", i+1, DSMH[i].ma_mh,DSMH[i].ten_mh, DSMH[i].so_tc);
	printf("\n");
}

int dinhvi(_monhoc DSMH[], int n, char *Bma_mh)
{
	int i=0;
	while (i < n && strcmp(DSMH[i].ma_mh, Bma_mh) != 0) i++;
	if (i < n) return (i);
    return (-1);
}

void danh_sach_mon_cua_gv(_giangvien DSGV[], char *Bmagv) {
    for (int i = 0; i < m; i++) {
        if (strcmp(DSGV[i].ma_gv,Bmagv)==0) {
            printf("THONG TIN MON HOC CUA GIANG VIEN: %s\n", DSGV[i].hoten_gv);
            printf("STT\tTEN MON HOC\tSO TC\n");
            for (int j = 0; j < DSGV[i].soluong_MGV; j++) {
                printf("%d\t", j+1);
                for (int k = 0; k < n; k++) {
                    if (strcmp(DSGV[i].DSMGV[j], DSMH[k].ma_mh)==0) {
                        printf("%s\t%d\n", DSMH[k].ten_mh,DSMH[k].so_tc);
                        break;
                    }
                }
            }
        }
    }
    printf("\n");
}

void danh_sach_giangvien(_giangvien DSGV[], char *Bma_mon) {
    int stt = 1;
    printf("STT\tTEN GIANG VIEN\tMA GV\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < DSGV[i].soluong_MGV; j++) {
            if (strcmp(Bma_mon, DSGV[i].DSMGV[j])==0) {
                printf("%d\t%s\t%s\n", stt++, DSGV[i].hoten_gv,DSGV[i].ma_gv);
            }
        }
    }
    printf("\n");
}