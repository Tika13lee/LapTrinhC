#include <stdio.h>
#include <string.h>
typedef struct {
	char maHang[8];
	char tenHang[15];
	long donGia;
	int soLuong;
	char ngayBan[11];
	float thanhTien;
}ITEMS;

struct Node{
	ITEMS data;
	Node *link;
};
struct List{
	Node *first, *last;
};
void init(List &l);
Node *createNode(ITEMS x);
Node *searchMaHang(List l, char* ma);
void addLast(List &l, Node *p);
void insertLast(List &l, ITEMS x);
void nhapHang(List l, ITEMS &x);
void nhapDS(List &l);
float thanhTien();
void inTieuDe();
void xuatHang(ITEMS x);
void xuatDS(List l);
void xoaTheoMa(List &l, char* ma);
void interchangeSort(List &l);
void lonNhat(List l);
void menu();
int main(){
	List l;
	init(l);
	int chon=0;
	do{
		menu();
		printf("Nhap lua chon: ");	 scanf("%d", &chon);
		switch(chon){
			case 1:
				nhapDS(l);
				break;
			case 2:
				inTieuDe();
				xuatDS(l);
				break;
			case 3: 
				char ma[8];
				fflush(stdin);
				printf("Nhap ma can xoa: "); 	gets(ma);
				xoaTheoMa(l, ma);	
				break;
			case4:
				interchangeSort(l);
				break;
			case 5:
				lonNhat(l);
				break;
		}
	}while(chon !=0 );
}
void menu(){
	printf("-------------------------------------\n");
	printf("1. Nhap danh sach mat hang\n");
	printf("2. Xuat danh sach cac mat hang\n");
	printf("3. Xoa hang theo ma\n");
	printf("4. Sap xep danh sach theo ten\n");
	printf("5. In thong tin phan tu co thanh tien lon nhat\n");
	printf("0. Thoat chuong trinh\n");
	printf("-------------------------------------\n");
}
void lonNhat(List l){
	Node*p=l.first;
	float max = p->data.thanhTien;
	while(p != NULL){
		if(p->data.thanhTien > max)
			max = p->data.thanhTien;
		p = p->link;
	}
}     
void interchangeSort(List &l){
    for(Node *p=l.first; p!=l.last; p=p->link){
        for(Node *q=p->link; q!=NULL; q=q->link){
            if(strcmp(p->data.tenHang, q->data.tenHang) > 0){ 
 				ITEMS temp = p->data;
 				p->data = q->data;
 				q->data = temp;
            }   
        }
    }
    xuatDS(l);
} 
void xoaTheoMa(List &l, char* ma){
	Node *p = l.first;
	Node *q = NULL;
	
	while(p!=NULL){
		if(strcmp(p->data.maHang, ma)==0) 
			break;
		q = p;
		p = p->link;
		
	}
	if(p == NULL)
		printf("Khong tim thay\n");
	else if(q!= NULL){
		if(p == l.last){
			l.last = q; 
        	q->link = p->link; 
        	delete p;
		}
	} 
	//p là phần tử đầu xâu
	else{ 
        l.first = p->link; 
    	if (l.first == NULL) 	
			l.last = NULL; //ds có 1phần tử
  	} 
	inTieuDe();
	xuatDS(l);
}
void xuatDS(List l){
	Node* p;
	if(l.first == NULL)
		printf("Danh sach rong\n");
	else{
		for(Node *p = l.first; p != NULL; p= p->link){
			xuatHang(p->data);
 		}
	}
}
void xuatHang(ITEMS x){
	printf("%-15s %-15s %-15s %-15d %-15d %-15.1f\n", x.maHang, x.tenHang, x.ngayBan, x.donGia, x.soLuong, x.thanhTien);
}
void inTieuDe(){
	printf("%-15s %-15s %-15s %-15s %-15s %-15s\n", "Ma Hang", "Ten Hang", "Ngay", "Don Gia", "So Luong", "Thanh Tien");

}
void nhapDS(List &l){
	int n;
	ITEMS x;
	printf("Nhap so luong hang: ");	 scanf("%d", &n);
	for(int i=0; i<n; i++){
		nhapHang(l, x);
		insertLast(l, x);
	}
}
void nhapHang(List l, ITEMS &x){
	do{
		fflush(stdin);
		printf("Nhap ma hang: "); 	gets(x.maHang);
		if(searchMaHang(l, x.maHang) == NULL)
			break;
		else
			printf("Trung ma - Nhap lai ma hang\n");
	}while(1);
	printf("Nhap ten hang: "); 	gets(x.tenHang);
	printf("Nhap don gia: ");	 scanf("%d", &x.donGia);
	printf("Nhap so luong: "); scanf("%d", &x.soLuong);
	fflush(stdin);
	printf("Nhap ngay thang nam ban: "); 	gets(x.ngayBan);
	x.thanhTien = x.soLuong*x.donGia;
}
void insertLast(List &l, ITEMS x){
	Node *p = createNode(x);
	if(p !=NULL)
		addLast(l, p);
}
void addLast(List &l, Node *p){
	if(l.first == NULL)
		l.first = l.last = p;
	else{
		l.last->link = p;
		l.last = p;
	}
}
Node *searchMaHang(List l, char* ma){
	for(Node *p= l.first; p!= NULL; p = p->link)
		if(strcmp(p->data.maHang, ma) == 0)
			return p;
	return NULL;
}
void init(List &l){
	l.first = l.last = NULL;
}
Node *createNode(ITEMS x){
	Node* p =new Node;
	if(p == NULL)
		return NULL;
	p->data = x;
	p->link = NULL;
}
