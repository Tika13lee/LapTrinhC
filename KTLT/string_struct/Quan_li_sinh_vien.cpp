#include <stdio.h>
#include <string.h>
#include <math.h>
#define max 100
typedef struct sv
{
	char hoten[20], maSV[12];
	float TK, GK, CK, TH, DTB;
}SINHVIEN;
void input_one(SINHVIEN &p);
void output_one(SINHVIEN p);
void input_list(SINHVIEN a[], int &n);
void tb(SINHVIEN a[], int n);
void output_list(SINHVIEN a[], int n);
int _search(SINHVIEN a[], int n, char x[]);
void output_search(SINHVIEN a[], int n, char x[]);
int main()
{
	SINHVIEN S,a[max];
	int n;
	char s[10];
	input_list(a,n);
	tb(a,n);
	output_list(a,n);
	printf("\n");
	fflush(stdin);
	printf("Nhap ma sinh vien can tim: ");	gets(s);
	output_search(a, n, s);
	return 0;
}
void input_one(SINHVIEN &p)
{
	char s[20]; //char *st;
	float temp;
	fflush(stdin);
    printf("\nHo ten sinh vien: ");gets(s); strcpy(p.hoten, s);
	printf("Ma sinh vien: ");gets(s); strcpy(p.maSV, s);
	do
	{
		printf("Nhap diem thuong ky: "); scanf("%f", &temp);	
	}while(temp<0||temp>11);
	p.TK=temp;
	do
	{
		printf("Nhap diem giua ky: "); scanf("%f", &temp);	
	}while(temp<0||temp>11);
	p.GK=temp;
	do
	{
		printf("Nhap diem cuoi ky: "); scanf("%f", &temp);	
	}while(temp<0||temp>11);
	p.CK=temp;
	do
	{
		printf("Nhap diem thuc hanh: "); scanf("%f", &temp);	
	}while(temp<0||temp>11);
	p.TH=temp;
}
void output_one(SINHVIEN p)
{
	printf("%s\t%s\t%.1f\t%.1f\t%.1f\t%.1f", p.hoten, p.maSV, p.TK, p.GK, p.CK, p.TH);
}
void input_list(SINHVIEN a[], int &n)
{
	SINHVIEN S;
	do
	{
		printf("So luong sinh vien: "); 
        scanf("%d", &n);
	}while (n<0||n>max);
	printf("\nNHAP DIEM CUA LOP\n");
	for(int i=0; i<n; i++)
	{
		input_one(S);
		a[i]=S;
	}
}
void tb(SINHVIEN a[], int n)
{
	for(int i=0; i<n; i++)
	{
		a[i].DTB = (((2*a[i].TK + 3*a[i].GK + 5*a[i].CK)/10)*2 + a[i].TH)/3;
	}
}
void output_list(SINHVIEN a[], int n)
{
	printf("STT\t HO TEN\t\t MA SV\t\t DTB");
	for(int i=0; i<n; i++)
	printf("\n%d\t%s\t%s\t%.1f",i+1,a[i].hoten, a[i].maSV, a[i].DTB);
}
int search(SINHVIEN a[], int n, char x[])
{
	int i=0;
	while(i<n && strcmp(a[i].maSV, x)!=0) i++;
	if(i<n)return(i);
	return(-1);
}
void output_search(SINHVIEN a[], int n, char x[])
{

	int kq = search(a,n,x);
	if(kq==-1)printf("\nKhong tim thay");
	else output_one(a[kq]);
	printf("\n");
}