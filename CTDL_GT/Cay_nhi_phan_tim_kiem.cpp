#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Date{
	int ngay;
	int thang;
	int nam;
};
struct items
{
	char maHang[8];
	char tenHang[15];
	Date ngay;
	int soLuong;
	long donGia;
	long thanhTien;
};
struct Node{
	items data;
	Node* left;
	Node* right;
};
typedef Node* tree;

void init(tree &c){
	c = NULL;
}
Node* getNode(items x){
	Node* p = new Node;
	if(p == NULL)
		return NULL;
	p->data = x;
	p->left = p->right = NULL;
	return p;
}
void themNodeVaoCay(Node* p, tree &c){
	if(c == NULL)
		c = p;
	else{
		if(strcmp(c->data.maHang, p->data.maHang) > 0)
			themNodeVaoCay(p, c->left);
		else if(strcmp(c->data.maHang, p->data.maHang) < 0)
			themNodeVaoCay(p, c->right);
		return;
	}
}
int checkMa(tree c, char* ma){
	while(c != NULL){
		if(strcmp(c->data.maHang, ma) == 0)
			return 1;
	}
	return 0;
}
void nhapHang(items &x){
	fflush(stdin);

	printf("\nMa hang: ");	gets(x.maHang);
	printf("Ten hang: "); 	gets(x.tenHang);
	printf("Ngay nhap: ");
	scanf("%d/%d/%d", &x.ngay.ngay, &x.ngay.thang, &x.ngay.nam);
	printf("So luong: ");	scanf("%d", &x.soLuong);
	printf("Don gia: "); 	scanf("%d", &x.donGia);
	x.thanhTien = x.soLuong*x.donGia;
}
void nhap(tree &c){
	int n;
	printf("\nNhap so luong mat hang: "); 	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		items x;
		nhapHang(x);
		Node* p = getNode(x);
		themNodeVaoCay(p, c);
	}
	
	// int chon = 0;
	// do{
	// 	items x;
	// 	nhapHang(x);
	// 	Node* p = getNode(x);
	// 	themNodeVaoCay(p, c);
	// 	printf("1.tiep / 0.khong"); 	scanf("%d", &chon);
	// }while(chon);
}
void xuatHang(items x){
	printf("%-15s %-15s %d/%d/%d %10d %15d %15d\n", x.maHang, x.tenHang,
		x.ngay.ngay, x.ngay.thang, x.ngay.nam, x.soLuong, x.donGia, x.thanhTien);
}
void xuat(tree c){
	if(c){
		if(c->left)
			xuat(c->left);
		xuatHang(c->data);
		if(c->right)
			xuat(c->right);
	}
	else
		printf("Rong\n");
}
Node* searchNode(tree c, char* ma){
	if(c){
		if(strcmp(c->data.maHang, ma) == 0)
			return c;
		else if (strcmp(c->data.maHang, ma) > 0)
			return searchNode(c->left, ma);
		else return searchNode(c->right, ma);
	}
	else return NULL;
}
int insertNode(tree &c, items x){
	if(c){
		if(strcmp(c->data.maHang, x.maHang) == 0)
			return 0;
		else if (strcmp(c->data.maHang, x.maHang) > 0)		
			return insertNode(c->left, x);
		else return insertNode(c->right, x);
	}
	c = new Node;
	if(c == NULL)	return -1;
	c->data = x;
	c->left = c->right = NULL;
	return 1;
}
void searchStandFor(tree &p, tree &q){
	if(q->left)
		searchStandFor(p, q->left);
	else{
		p->data = q->data;
		p = q;
		q = q->right;
	}
}
void xoa(tree &c, char* ma){
	if(c ==  NULL)
		return;
	else{
		if(strcmp(c->data.maHang, ma) > 0)
			xoa(c->left, ma);
		else if(strcmp(c->data.maHang, ma) < 0)
			xoa(c->right, ma);
		else{
			Node*p = c;
			if(c->left == NULL)
				c = c->right;
			else if (c->right == NULL)
				c = c->left;
			else	searchStandFor(p, c->right);
			delete p;
		}
	}
}
char isLeaf(Node* p){
	return (p->left == NULL && p->right == NULL);
}
int countLeaf(tree c){
	if(c == NULL)
		return 0;
	else{
		if(isLeaf(c))
			return 1;
		else
			return countLeaf(c->left) + countLeaf(c->right);
	}
}
int countNode(tree c){
	if(c == NULL)
		return 0;
	else
		return 1 + countNode(c->left) + countNode(c->right);
}
int max(int a, int b){
	if(a>b)
		return a;
	else
		return b;
}
int heightTree(tree c){
	if(c == NULL)
		return 0;
	else{
		return max(heightTree(c->left), heightTree(c->right)) + 1;
	}
}
void sua(tree c, char* ma){
	if(c){
		if(searchNode(c, ma) != NULL){
			printf("Nhap thong tin can sua\n");
			nhapHang(c->data);
			Node* p = getNode(c->data);
			themNodeVaoCay(p, c);
			printf("Sua thanh cong\n");
		}
	}
}
void tieuDe(){
	printf("%-15s %-15s %10s %10s %15s %15s\n", "Ma Hang", "Ten Hang",
		"Ngay Nhap", "So Luong", "Don Gia", "Thanh Tien");
}
void menu(){
	printf("\n----------Quan ly mat hang----------\n");
	printf("1. Nhap danh sach mat hang\n");
	printf("2. Xuat danh sach mat hang\n");
	printf("3. Tim hang theo ma\n");
	printf("4. Them hang vao danh sach\n");
	printf("5. Xoa mat hang theo ma\n");
	printf("6. Dem so nut la cua cay\n");
	printf("7. Dem so nut cua cay\n");
	printf("8. Chieu cao cua cay\n");
	printf("9. Sua thong tin mat hang\n");
	printf("0. Thoat chuong trinh\n");
	printf("\n------------------------------------\n");
}
int main(){
	tree c;
	init(c);
	int chon = 0;
	do
	{
		menu();
		printf("Nhap lua chon: "); scanf("%d", &chon);
		switch(chon){
			case 1:
				nhap(c);
				break;
			case 2:
				tieuDe();
				xuat(c);
				break;
			case 3:{
				char ma[10];
				fflush(stdin);
				printf("Nhap ma hang can tim: "); 	gets(ma);
				Node* p = searchNode(c, ma);
				if(p != NULL){
					tieuDe();
					xuatHang(p->data);
				}
				else	printf("Khong tim thay\n");
				break;
			}
			case 4:{
				items x;
				printf("Nhap thong tin mat hang can them\n");
				nhapHang(x);
				int t = insertNode(c, x);
				if(t == 1)
					printf("Them thanh cong\n");
				else if(t == 0)
					printf("Them khong thanh cong - Trung ma\n");
				else	printf("Them khong thanh cong - Day bo nho\n");
				break;
			}
			case 5:{
				char ma[10];
				fflush(stdin);
				printf("Nhap ma hang can xoa: "); 	gets(ma);
				xoa(c, ma);
				break;
			}
			case 6:{
				int l = countLeaf(c);
				printf("So nut la cua cay la: %d\n", l);
				break;
			}
			case 7:{
				int n = countNode(c);
				printf("So nut cua cay la: %d\n", n);
				break;
			}
			case 8:{
				int h = heightTree(c);
				printf("Chieu cao cua cay la: %d\n", h);
				break;
			}
			case 9:{
				char ma[10];
				fflush(stdin);
				printf("Nhap ma hang can xoa: "); 	gets(ma);
				sua(c, ma);
			}
		}
	} while (chon != 0);
	return 0;
}