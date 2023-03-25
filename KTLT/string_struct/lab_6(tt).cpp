#include <stdio.h>
#include <string.h>
#include <math.h> 

typedef struct {
	char holot[30], ten[30], ngaysinh[9], noisinh[40];
}HOTEN;

typedef struct {
	int WIN, WORD, EXCEL, TONG; 
	char Xeploai[20];
}DIEM;

typedef struct {
	HOTEN hoten;
	DIEM diem;
}HOCVIEN;

void nhaphoten(HOTEN &ten) {
	char s[40];
	fflush(stdin);
	printf("\nNhap ho lot: "); gets(s); strcpy(ten.holot,s);
	printf("\nNhap ten: "); gets(s); strcpy(ten.ten,s);
	printf("\nNhap ngay sinh: "); gets(s); strcpy(ten.ngaysinh,s);
	printf("\nNhap noi sinh: "); gets(s); strcpy(ten.noisinh,s);
}

void nhapdiem(DIEM &diem) {
	int temp;
	do{
		printf("\nNhap diem WIN: ");
		scanf("%d", &temp);
	}while(temp < 0 || temp > 10);
	diem.WIN = temp;
	do{
		printf("\nNhap diem WORD: ");
		scanf("%d", &temp);
	}while(temp < 0 || temp > 10);
	diem.WORD = temp;
	do{
		printf("\nNhap diem EXCEL: ");
		scanf("%d", &temp);
	}while(temp < 0 || temp > 10);
	diem.EXCEL = temp;
	
	diem.TONG = (diem.WIN + diem.WORD + diem.EXCEL);
	if(diem.TONG >= 24) strcpy(diem.Xeploai,"Gioi");
	else if(diem.TONG >= 18) strcpy(diem.Xeploai,"Kha");
	else if(diem.TONG >= 15) strcpy(diem.Xeploai,"Trung binh");
	else strcpy(diem.Xeploai,"Kem");
}

void output_one1(HOCVIEN hv) {
	printf("| %-10s| %-10s| %-10s| %-10s|           |\n",
	hv.hoten.holot, hv.hoten.ten, hv.hoten.ngaysinh, hv.hoten.noisinh);
}

void output_kq(HOCVIEN hv) {
	printf("| %-10s| %-10s| %-10s| %-10s| %-10d| %-10d| %-10d| %-10d| %-10s|\n", 
	hv.hoten.holot, hv.hoten.ten, hv.hoten.ngaysinh, hv.hoten.noisinh,
	hv.diem.WIN, hv.diem.WORD, hv.diem.EXCEL, hv.diem.TONG,hv.diem.Xeploai);
}

void SapXepTheoDiem(HOCVIEN A[], int slhv) {
	int i, j;
	for(i = 0; i < slhv - 1; i++) {
		for(j = slhv - 1; j > i; j --) {
			if(A[j].diem.TONG > A[j - 1].diem.TONG) {
				HOCVIEN hv = A[j];
				A[j] = A[j - 1];
				A[j - 1] = hv;
			}
		}
	}
}

void HienThiTenCot1() {
	printf("\n____________________________________________________________\n");
	printf("| %-10s| %-10s| %-10s| %-10s| %-10s|", "Ho lot", "Ten","Ngay sinh","Noi sinh", "Ghi chu");
	printf("\n____________________________________________________________\n");
}
void HienThiTenCot2() {
	printf("\n_____________________________________________________________________________________________________________\n");
	printf("| %-10s| %-10s| %-10s| %-10s| %-10s| %-10s| %-10s| %-10s| %-10s|", 
		 "Ho lot", "Ten", "Ngay sinh", "Noi sinh", "Diem WIN", "Diem WORD", "Diem EXCEL", "Diem TONG", "Xep loai");
	printf("\n_____________________________________________________________________________________________________________\n");
}
int main() {
	HOCVIEN A[100];
	int slhv = 0;
	int luachon;
	do {
		printf("\n************* MENU *************\n");
		printf("\n1. Them hoc vien vao danh sach.");
		printf("\n2. Hien thi danh sach hoc vien.");
		printf("\n3. Nhap diem cho hoc vien.");
		printf("\n4. Hien thi ket qua thi.");
		printf("\n0. Thoat chuong trinh.");
		printf("\nBan chon ? ");
		scanf("%d", &luachon);
		HOCVIEN hv;
		int i;
		switch(luachon) {
			case 0:
				break;
			case 1:
				nhaphoten(hv.hoten);
				A[slhv++] = hv;
				break;
			case 2:
				HienThiTenCot1();
				for(i = 0; i < slhv; i++) {
					output_one1(A[i]);
				}
				break;
			case 3:
				for(i=0; i<slhv; i++){
					printf("\nNhap diem cho hoc vien %d", i+1); 
					nhapdiem(A[i].diem);
				}
				break;
			case 4:
				SapXepTheoDiem(A,slhv); 
				HienThiTenCot2();
				for(i = 0; i < slhv; i++) {
					output_kq(A[i]);
				}
				break;
			default:
				printf("Sai chuc nang, vui long chon lai!\n");
				break;
		}		
	} while(luachon);	
	return 0;
}

