#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <NEW>

struct MAY_TINH
{
	int MaMay;
	char TenMay[100];
	int NamSX;	
	int GiaTriMay;
	int ThoiGian;
	int ThanhTien;
	int Tien1h;
};
struct Node{
	MAY_TINH key;
	Node* left;
	Node* right;
};
typedef Node* tree;
void NhapMay(MAY_TINH &x);
void XuatMay(MAY_TINH x);
Node* getNode(MAY_TINH x);
void themNodeVaoCay(Node* p, tree &c);
void nhap(tree &c);
void xuat(tree c);
Node* searchNode(tree c, int ma);
void searchStandFor(tree &p, tree &q);
void xoa(tree &c, int ma);
int max(tree c);
int max1(int a, int b);
Node* searchNode1(tree c, int tg);
void tieuDe();
void menu();
// Chuong trinh chinh
int main()
{
	tree c = NULL;
	int chon = 0;
	do{
		menu();
		printf("Nhap lua chon: ");
		scanf("%d", &chon);
		switch(chon){
			case 1:
				nhap(c);
				break;
			case 2:
				tieuDe();
				xuat(c);
				break;
			case 3:{
				int ma;
				printf("Nhap ma may can tim: ");
				scanf("%d", &ma);
				Node* p = searchNode(c, ma);
				if(p != NULL){
					tieuDe();
					XuatMay(p->key);
				}	
				break;
			}
			case 4:{
				int ma;
				printf("Nhap ma may can xoa: ");
				scanf("%d", &ma);
				xoa(c, ma);
				tieuDe();
				xuat(c);
				break;
			case 5:{
				int t = max(c);
				printf("%d", t);
				Node* p = searchNode1(c, t);
				if(p != NULL)
					XuatMay(p->key);
				break;
			}
			}
		}
	}while(chon != 0);
 
	return 0;
}
void menu(){
	printf("\n-------------Quan ly phong game-------------\n");
	printf("1. Tao cay nhi phan tim kiem\n");
	printf("2. Xuat thong tin cac may\n");
	printf("3. Tim va hien thi thong tin may theo ma\n");
	printf("4. Xoa 1 may theo ma\n");
	printf("5. Thong tin may co thoi gian truy cap lon nhat\n");
	printf("0. Thoat chuong trinh\n");
	printf("\n--------------------------------------------\n");
}

int max1(int a, int b){
	return a > b ? a : b;
}

int max(tree c){
	int m = c->key.ThoiGian;
	if(c){
		if(c->left == NULL && c->right == NULL)
			return m;
		else if(c->left == NULL){
			m = c->key.ThoiGian;
			return max(c->right) > m ? max(c->right) : m;
		}
		else if(c->right == NULL){
			m = c->key.ThoiGian;
			return max(c->left) > m ? max(c->left) : m;
		}
		else{
			return max1(max(c->right),max(c->left));
		}	
	}
	return 0;
}
Node* searchNode1(tree c, int tg){
	if(c){
		if(c->key.ThoiGian == tg)
			return c;
		else if(c->key.ThoiGian > tg)
			return searchNode(c->left, tg);
		else
			return searchNode(c->right, tg);
	}
	return NULL;
}

void searchStandFor(tree &p, tree &q){
	if(q->left)
		searchStandFor(p, q->left);
	else{
		p->key = q->key;
		p = q;
		q = q->right;
	}
}
void xoa(tree &c, int ma){
	if(c == NULL)
		return;
	else{
		if(c->key.MaMay > ma)
			xoa(c->left, ma);
		else if(c->key.MaMay < ma)
			xoa(c->right, ma);
		else{
			Node* p = c;
			if(c->left == NULL)
				c = c->right;
			else if(c->right == NULL)
				c = c->left;
			else	searchStandFor(p, c->right);
			delete p;
		}
	}
}
Node* searchNode(tree c, int ma){
	if(c){
		if(c->key.MaMay == ma)
			return c;
		else if(c->key.MaMay > ma)
			return searchNode(c->left, ma);
		else
			return searchNode(c->right, ma);
	}
	return NULL;
}
Node* getNode(MAY_TINH x){
	Node* p = new Node;
	if(p == NULL)
		return NULL;
	p->key = x;
	p->left = p->right = NULL;
	return p;
}
void themNodeVaoCay(Node* p, tree &c){
	if(c == NULL)
		c = p;
	else{
		if(c->key.MaMay > p->key.MaMay)
			themNodeVaoCay(p, c->left);
		else if(c->key.MaMay < p->key.MaMay)
			themNodeVaoCay(p, c->right);
		return;
	}
}
void nhap(tree &c){
	int chon;
	do{
		
		MAY_TINH x;
		NhapMay(x);
		Node* p = getNode(x);
		themNodeVaoCay(p, c);
		printf("Ban muon nhap tiep khong ? 1.CO , 0.KHONG -> ");
		scanf("%d", &chon);
	}while(chon);
}
void tieuDe(){
	printf("\n%10s %20s %10s %20s %10s %20s", "Ma May", "Ten May", "Nam SX", "Gia Tri May",
		"Thoi Gian", "Tien Truy Cap");
}
void xuat(tree c){
	if(c){
		if(c->left)
			xuat(c->left);
		XuatMay(c->key);
		if(c->right)
			xuat(c->right);
	}
	else	printf("Rong\n");
}
void NhapMay(MAY_TINH &x)
{
	fflush(stdin);
	printf("\nMa may: ");
	scanf("%d", &x.MaMay);
	
	printf("Ten may : ");
	fflush(stdin);
	gets(x.TenMay);
	
	printf("Nam san xuat: ");
	scanf("%d", &x.NamSX);
	
	printf("Gia tri may: ");
	scanf("%d", &x.GiaTriMay);
	
	printf("Thoi gian truy cap : ");
	scanf("%d", &x.ThoiGian);
	
	printf("Tien truy cap trong 1h: ");
	scanf("%d", &x.Tien1h);
	
	x.ThanhTien = x.Tien1h * x.ThoiGian;
}

void XuatMay(MAY_TINH x)
{
	printf("\n%10d %20s %10d %20d %10d %20d", x.MaMay, x.TenMay, x.NamSX, x.GiaTriMay,x.ThoiGian,x.ThanhTien);
	 
}
