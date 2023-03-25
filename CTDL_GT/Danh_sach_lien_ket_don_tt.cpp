#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Ngay{
    int ngay, thang, nam;
};
struct SinhVien{
    char maSV[8];
    char hoTen[50];
    int gioiTinh;
    Ngay ngaySinh;
    char diaChi[100];
    char lop[12];
    char khoa[7];
};
struct Node{
    SinhVien data;
    Node* link;
};
struct List{
    Node *first;
    Node *last;
};
Node* getNode(SinhVien x);
void init(List &l);
void addLast(List &l, Node* p);
void insertLast(List &l, SinhVien x);
int nhapSV(SinhVien &x);
void nhapDSSV(List &l);
void xuatSV(SinhVien x);
void xuatDS(List l);
void inTieuDe();
void xoaSV(List &l, char* ma);
void sort_HoTen(List &l);
void ghiFileText_SV(const char filename[], SinhVien x);
void ghiFileText_List(const char filename[], List l);
void docFile_List(const char filename[], List &l);
Node* searchMa(List l, char *ma);
void them(List &l);

void menu();

int main(){
    List l;
    int chon = 0;
    do{
        menu();
        printf("Nhap lua chon: ");
        scanf("%d", &chon);
        switch(chon){
            case 1: 
                nhapDSSV(l);
                break;
            case 2:
                xuatDS(l);
                break;
            case 3:
            	ghiFileText_List("Test.txt", l);
            	break;
//            case 4:
//            	docFile_List("Test.txt", l);
//            	break;
            case 5:
            	them(l);
   				break;
            case 6:
            	char ma[8];
            	fflush(stdin);
            	printf("Nhap ma sinh vien can xoa: "); 	gets(ma);
            	xoaSV(l, ma);
            	break;
            case 7:
            	sort_HoTen(l);
            	break;
        }
    }while(chon != 0);
}
void menu(){
    printf("\n----------------------------------\n");
    printf("1. Nhap danh sach sinh vien\n");
    printf("2. Xuat danh sach\n");
    printf("3. Ghi danh sach vao file\n");
    printf("4. Doc danh sach tu file\n");
    printf("5. Them sinh vien\n");
    printf("6. Xoa sinh vien\n");
    printf("7. Sap xep theo ten\n");
    printf("\n----------------------------------\n");
}
//void docFile_List(const char filename[], List &l){
//	FILE *f = fopen("Test.txt", "r");
//	Node *p = l.first;
//	char a[100];
//	while(p != NULL){
//		SinhVien x;
//		
//		
////		while(fgets(a, 100, f) != NULL){
////			printf("%s", a);
////			
////		}
//
//		fgets(x.maSV, 8, f);
//		fgets(x.hoTen, 50, f);
//		fgets(x.gioiTinh, f);
//		fgets(x.diaChi, 100, f);
//		fgets(x.khoa, 12, f);
//		fgets(x.lop, 7, f);
//		fgets(x.maSV, 8, f);
//		Node* p = getNode(x);
//		insertLast(l, x);
//	}
//	fclose(f);
//}
void ghiFileText_List(const char filename[], List l){
	FILE *f = fopen(filename, "a");
	Node *p = l.first;
	while(p != NULL){
		ghiFileText_SV(filename, p->data);
		p = p->link;
	}
	printf("Da ghi file xong\n");
	fclose(f);
}
void ghiFileText_SV(const char filename[], SinhVien x){
	FILE* f= fopen(filename, "a");
	if(f==NULL)
		printf("ERROR !!!\n");
	else{
		fprintf(f, "%-15s", x.maSV);
		fprintf(f, "%-15s", x.hoTen);
		fprintf(f, "%d/%d/%-15d", x.ngaySinh.ngay, x.ngaySinh.thang, x.ngaySinh.nam);
		fprintf(f, "%-15d", x.gioiTinh);
		fprintf(f, "%-15s", x.diaChi);
		fprintf(f, "%-15s", x.khoa);
		fprintf(f, "%-15s\n", x.lop);
	}
	fclose(f);
}
Node* searchMa(List l, char *ma){
	for(Node* p = l.first; p != NULL; p = p->link){
		if(strcmp(p->data.maSV, ma) == 0)
			return p;
	}
	return NULL;
}
void them(List &l){
	SinhVien x;
	nhapSV(x);
	if(searchMa(l, x.maSV) == NULL){
		insertLast(l, x);
		printf("Them thanh cong\n");
	}	
	else
		printf("Them khong thanh cong - Ma sinh vien bi trung\n");
}
void sort_HoTen(List &l){
	SinhVien temp;
	for(Node *p=l.first; p!=l.last; p=p->link){
        for(Node *q=p->link; q!=NULL; q=q->link){
            if(strcmp(p->data.hoTen, q->data.hoTen) > 0){ 
 				temp = p->data;
 				p->data = q->data;
 				q->data = temp;
            }   
        }
    }
    xuatDS(l);
}
void xoaSV(List &l, char* ma){
	Node *p = l.first;
	Node *q = NULL;
	while(p != NULL){
		if(strcmp(p->data.maSV, ma) == 0)
			break;
		q = p;
		p = p->link;
	}
	if(p == NULL)
		printf("Khong tim thay\n");
	else if(q != NULL){
		if(p == l.last){
			l.last = q;
			q->link = p->link;
			delete p;
		}
	}
	else{
		l.first = p->link;
		if(l.first == NULL)
			l.last = NULL;
	}
	xuatDS(l);
}
void inTieuDe(){
    printf("%-15s %-15s %-15s %-15s %-15s %-15s %-15s\n", "Ma SV", "Ho Ten", "Ngay sinh",
        "Gioi Tinh", "Dia Chi", "Khoa", "Lop");
}
void xuatDS(List l){
    inTieuDe();
    Node* p = l.first;
    while(p){
        xuatSV(p->data);
        p = p->link;
    }
}
void xuatSV(SinhVien x){
    char gt[4];
    if(x.gioiTinh == 0)
        strcpy(gt, "Nam");
    else if(x.gioiTinh == 1)
        strcpy(gt, "Nu");
    else if(x.gioiTinh == 2)
    	strcpy(gt, "Khac");
    printf("%-15s %-15s %d/%d/%-9d %-15s %-15s %-15s %-15s\n", x.maSV, x.hoTen,
        x.ngaySinh.ngay, x.ngaySinh.thang, x.ngaySinh.nam, gt, 
        x.diaChi, x.khoa, x.lop);

}
void nhapDSSV(List &l){
    printf("Nhap danh sach sinh vien. Nhap ma sinh vien = 0 de dung\n");
    SinhVien x;
    int flag = nhapSV(x);
    while (flag){
        insertLast(l, x);
        flag = nhapSV(x);
    }
}
int nhapSV(SinhVien &x){
    fflush(stdin);
    printf("\nNhap ma sinh vien: ");  gets(x.maSV);
    if(strcmp(x.maSV, "0") == 0)
        return 0;
    printf("Nhap ho ten sinh vien: ");  gets(x.hoTen);
    printf("0. Nam\n");
    printf("1. Nu\n");
    printf("2. Khac\n");
    printf("Chon gioi tinh: ");     scanf("%d", &x.gioiTinh);
    printf("Nhap ngay thang nam: ");
    scanf("%d %d %d", &x.ngaySinh.ngay, &x.ngaySinh.thang, &x.ngaySinh.nam);
    fflush(stdin);
    printf("Nhap dia chi: ");   gets(x.diaChi);
    printf("Nhap lop: ");   gets(x.lop);
    printf("Nhap khoa: ");  gets(x.khoa);
    return 1;
}
Node* getNode(SinhVien x){
    Node* p = new Node;
    if(p == NULL)
        return NULL;
    p->data = x;
    p->link = NULL;
    return p;
}
void init(List &l){
    l.first = l.last = NULL;
}
void addLast(List &l, Node* p){
    if(l.first == NULL)
        l.first = l.last  = p;
    else{
        l.last->link = p;
        l.last = p;
    }
}
void insertLast(List &l, SinhVien x){
    Node* p = getNode(x);
    if(p == NULL)
        printf("Khong them duoc !!!\n");
    else
        addLast(l, p);
}
