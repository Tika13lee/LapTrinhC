#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define max 50
typedef struct {
    char hodem[20];
    char ten[7];
}HOTEN;
typedef struct {
    char MSSV[10];
    HOTEN hoVaTen;
    char hoTen[30];
    char gioiTinh[4];
    char diaChi[50];
    float diemTB;
}SINHVIEN;

SINHVIEN a[max];

void inMenu();
void input_one(SINHVIEN &p);
void noichuoi(SINHVIEN &p);
void input(SINHVIEN a[], int &n);
void output_one(SINHVIEN p);
void output(SINHVIEN a[], int n);
void inTieuDe();
int search(SINHVIEN a[], int n, char x[]);
void output_search(SINHVIEN a[], int n, char x[]);
int swap(SINHVIEN a[], int i, int j, SINHVIEN temp);
void sort_diemTB(SINHVIEN a[], int n);
void sort_hoVaTen(SINHVIEN a[], int n);

int main(){
    int n, chon=0;
    char x[10];
    do{
        inMenu();
        printf("Ban chon: ");   scanf("%d", &chon);
        fflush(stdin);
        system("cls");
        switch(chon){
            case 1:
                input(a, n);
                break;
            case 2:
                output(a, n);
                break;
            case 3:
                output_search(a, n, x);
                break;
            case 4: 
                sort_diemTB(a ,n);
                break;
            case 5: 
                sort_hoVaTen(a, n);
                break;
        }
    }while(chon !=0);
}
void inMenu(){
    printf("\n----------Quan li sinh vien----------\n");
    printf("1. Nhap thong tin cac sinh vien vao danh sach\n");
    printf("2. In danh sach sinh vien\n");
    printf("3. Xuat thong tin sinh vien theo ma so\n");
    printf("4. Sap xep danh sach sinh vien theo diem trung binh\n");
    printf("5. Sap xep danh sach sinh vien theo ho va ten\n");
    printf("0. Thoat\n");
    printf("----------Quan li sinh vien----------\n");
}
void sort_hoVaTen(SINHVIEN a[], int n){
    SINHVIEN temp;
    for(int i=0; i<n-1; i++){
        for(int j=i+1; j<n; j++)
            if(strcmp(a[j-1].hoVaTen.ten, a[j].hoVaTen.ten) >0)
            swap(a, i, j, temp);
    } 
    output(a, n); 
}
void sort_diemTB(SINHVIEN a[], int n){
    SINHVIEN temp;
    for(int i=0; i<n-1; i++){
        for(int j=i+1; j<n; j++)
            if(a[i].diemTB > a[j].diemTB)
                swap(a, i, j, temp);
    }
    output(a, n); 
}
int swap(SINHVIEN a[], int i, int j, SINHVIEN temp){
    temp = a[i];
    a[i] = a[j];
    a[j] = temp;
}
void output_search(SINHVIEN a[], int n, char x[]){
    printf("Nhap ma sinh vien can tim: ");  gets(x);
    int kq = search(a, n, x);
    if(kq == -1)    printf("Khong tim thay\n");
    else{
        inTieuDe();
        output_one(a[kq]); 
    }       
}
int search(SINHVIEN a[], int n, char x[]){
	int i=0;
	while(i<n && strcmp(a[i].MSSV, x)!=0) i++;
	if(i<n)
        return(i);
	return(-1);
}
void inTieuDe(){
    printf("%-15s %-30s %-10s %-30s %10s\n", "Ma SV", "Ho va ten", "Gioi tinh", "Dia chi", "Diem trung binh");
    printf("\n--------------------------------------------------------------------------------------------------------\n");
}
void output(SINHVIEN a[], int n){
    inTieuDe();
    for(int i=0; i<n; i++){
        output_one(a[i]);
    }
}
void output_one(SINHVIEN p){
    noichuoi(p);
    printf("%-15s %-30s %-10s %-30s %10.2f\n", p.MSSV, p.hoTen, p.gioiTinh, p.diaChi, p.diemTB);
    printf("\n--------------------------------------------------------------------------------------------------------\n");
}
void input(SINHVIEN a[], int &n){
    printf("So luong sinh vien: "); scanf("%d", &n);
    for(int i=0; i<n; i++){
        printf("Sinh vien thu %d\n", i+1);
        input_one(a[i]);
    }
}
void noichuoi(SINHVIEN &p) {
    strcpy(p.hoTen, p.hoVaTen.hodem);
    strcat(p.hoTen, " ");
    strcat(p.hoTen, p.hoVaTen.ten);
}
void input_one(SINHVIEN &p){
    char s[50];
    float temp;
    fflush(stdin);
    printf("Ma so sinh vien: ");    gets(s);
    strcpy(p.MSSV, s);
    printf("Ho dem sinh vien: ");    gets(s);
    strcpy(p.hoVaTen.hodem, s);
    printf("Ten sinh vien: ");    gets(s);
    strcpy(p.hoVaTen.ten, s);
    printf("Gioi tinh: ");  gets(s);
    strcpy(p.gioiTinh, s);
    printf("Dia chi: ");    gets(s);
    strcpy(p.diaChi, s);
    do{
        printf("Diem trung binh: ");
        scanf("%f", &temp);
    }while(temp<0);
    p.diemTB = temp;
}