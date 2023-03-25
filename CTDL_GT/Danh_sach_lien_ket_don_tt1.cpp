#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    char tenSach[20];
    char tacGia[20];
    char nhaXB[20];
    int namXB;
}SACH;
struct Node{
    SACH data;
    Node* link;
};
struct List{
    Node* first;
    Node* last;
};
void menu();
void init(List &l);
Node* getNode(SACH x);
void addTail(List &l, Node* p);
void addTail(List &l, Node* p);
void insertTail(List &l, SACH x);
void nhapSach(List l, SACH &x);
void nhapDS(List &l);
void xuat(SACH x);
void inTieuDe();
void xuatDS(List l);
void count(List l, char* tenTG);
void infor(List l, int nam, char* NXB, List &l1);

int main(){
    int chon = 0;
    List l;
    init(l);
    do{
        menu();
        printf("Nhap lua chon cua ban: ");
        scanf("%d", &chon);
        switch(chon){
            case 1:
                nhapDS(l);
                xuatDS(l);
                break;
            case 2:
                char tenTG[20];
                fflush(stdin);
                printf("Nhap ten tac gia can tim so luong cac quyen sach: ");
                gets(tenTG);
                count(l, tenTG);
                break;
            case 3:
                char NXB[20];
                int nam;
                List l1;
                init(l1);
                printf("Nhap nam xuat ban: ");
                scanf("%d", &nam);
                fflush(stdin);
                printf("Nhap nha xuat ban: ");
                gets(NXB);
                infor(l, nam, NXB, l1);
        }
    }while(chon!=0);
}

void menu(){
    printf("-----------------------------------------------\n");
    printf("1. Nhap thong tin cac quyen sach trong thu vien\n");
    printf("2. So luong cac quyen sach cua tac gia\n");
    printf("3. Nhung quyen sach da phat hanh trong nam ? nha xuat ban ?\n");
    printf("0. Thoat\n");
    printf("-----------------------------------------------\n");
}

void infor(List l, int nam, char* NXB, List &l1){
    for(Node* p = l.first; p!= NULL; p = p->link){
        if(strcmp(p->data.nhaXB, NXB) == 0 && p->data.namXB == nam )
            insertTail(l1, p->data);
    }
    xuatDS(l1);
}

void count(List l, char* tenTG){
    int dem = 0;
    for(Node* p = l.first; p!= NULL; p = p->link){
        if(strcmp(p->data.tacGia, tenTG) == 0 )
            dem ++;
    }
    printf("So luong cac quyen sach cua tac gia duoc nhap la: %d\n", dem);
}

void init(List &l){
    l.first = l.last = NULL;
}
Node* getNode(SACH x){
    Node* p = new Node;
    if(p == NULL)
        return NULL;
    p->data = x;
    p->link = NULL;
    return p;
}
void addTail(List &l, Node* p){
    if(l.first == NULL)
        l.first = l.last = p;
    else{
        l.last -> link = p;
        l.last = p;
    }
}
void insertTail(List &l, SACH x){
    Node* p = getNode(x);
    if(p == NULL)
        printf("Khong thanh cong");
    else
        addTail(l, p);
}
void nhapSach(List l, SACH &x){
    fflush(stdin);
    printf("\nNhap ten sach: ");  gets(x.tenSach);
    printf("Nhap ten tac gia: ");   gets(x.tacGia);
    printf("Nhap nha xuat ban: ");  gets(x.nhaXB);
    printf("Nhap nam xuat ban: ");  scanf("%d", &x.namXB);
}
void nhapDS(List &l){
    SACH x;
    int n;
    printf("Nhap so luong sach: "); scanf("%d", &n);
    for(int i=0; i<n; i++){
        nhapSach(l, x);
        insertTail(l, x);
    }
}
void xuat(SACH x){
    printf("%-20s %-20s %-20s %-20d\n", x.tenSach, x.tacGia, x.nhaXB, x.namXB);
}
void inTieuDe(){
    printf("%-20s %-20s %-20s %-20s\n", "Ten Sach", "Tac Gia", "Nha Xuat Ban", "Nam Xuat Ban");
}
void xuatDS(List l){
    Node* p = l.first;
    inTieuDe();
    while(p!= NULL){
        xuat(p->data);
        p = p->link;
    }
}