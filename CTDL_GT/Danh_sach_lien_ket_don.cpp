#include <stdio.h>
#include <stdlib.h>
//khai bao Node
struct Node {
    int Key;
    Node *pNext;
};
//khai bao danh sach lien ket
struct List {
    Node* pHead;
    Node* pTail;
};
Node* createNode (int Data);
void Init(List &l);
void addHead(List &l, Node* p);
void addTail(List &l, Node *p);
void insertFirst(List &l, int x);
void insertLast(List &l, int x);
void createList(List &l);
void printList(List l);
void sumList(List l);
void countList(List l);
void countSearch(List l, int x);
void maxList(List l);
void removeHead(List &l);
void removeTail(List &l);
void removeAll(List &l);
void menu();
int main()
{
    List l;
    Init(l);  
    int chon = 0, x;
    do{
        menu();
        printf("Chon chuc nang: ");
        scanf("%d", &chon);
        system("cls");
        switch(chon){
            case 1:
                createList(l);
                break;
            case 2: 
                printList(l);
                break;
            case 3:
                countList(l);
                break;
            case 4:
                sumList(l);
                break;
            case 5:
                printf("Nhap du lieu can them: ");  scanf("%d", &x);
                insertFirst(l, x);
                break;
            case 6:
                printf("Nhap du lieu can them: ");  scanf("%d", &x);
                insertLast(l, x);
                break; 
            case 7:
                removeHead(l);
                break;
            case 8:
                removeTail(l);
                break;
            case 9:
                printf("Nhap du lieu x can tim so luong: ");  scanf("%d", &x);
                countSearch(l, x);
                break;
            case 10:
                maxList(l);
                break;
            case 11:
                removeAll(l);
                break;
        }
    }while(chon != 0);
}
//tao Node moi 
Node* createNode (int Data) {
    Node *p;
    p = new Node; //cap phat vung nho cho Node
    if(p==NULL) 
        return NULL;
    p->Key = Data;
    p->pNext = NULL;
    return p;
}
//khoi tao danh sach rong
void Init(List &l) {
    l.pHead = l.pTail = NULL;
}
//them phan tu vao dau danh sach 
void addHead(List &l, Node* p) {
    if(l.pHead == NULL)
        l.pHead = l.pTail = p;
    else {
        p->pNext = l.pHead;
        l.pHead = p;
    }
}
//them phan tu vao cuoi danh sach
void addTail(List &l, Node *p) {
    if(l.pHead == NULL)
        l.pHead = l.pTail = p;
    else {
        l.pTail->pNext = p;
        l.pTail = p;
    }
}
//them thanh phan du lieu vao dau danh sach
void insertFirst(List &l, int x) {
    Node* p = createNode(x); //tao phan tu moi cho danh sach
    if(p == NULL)
        printf("Them khong thanh cong\n");
    else
        addHead(l, p);
}
void insertLast(List &l, int x) {
    Node* p = createNode(x);
    if(p == NULL)
        printf("Them khong thanh cong\n");
    else
        addTail(l, p);
}
//tao danh sach lien ket
void createList(List &l) {
    int data;
    printf("Nhap du lieu khac -1: ");
    scanf("%d", &data);
    while(data != -1){
        insertFirst(l, data);
        printf("Nhap du lieu: ");   scanf("%d", &data);
    }
    printf("Da nhap du lieu xong\n");
}
//in danh sach
void printList(List l) {
    Node *p = l.pHead; 
    printf("Cac phan tu tren danh sach: \n");
    while (p != NULL){
        printf("%d\t", p->Key);
        p = p->pNext; 
    }
    printf("\n");
}
//dem so phan tu cua danh sach
void countList(List l) {
    int count = 0;
    Node *p = l.pHead;
    while(p != NULL){
        count++;
        p = p->pNext;
    }
    printf("So phan tu cua danh sach lien ket la: %d\n", count);
}
//tong gia tri
void sumList(List l) {
    int sum = 0;
    Node *p = l.pHead;
    while (p != NULL){
        sum += p->Key;
        p = p->pNext;
    }
    printf("Tong gia tri cac phan tu tren danh sach la: %d\n", sum);
}
//dem so phan tu co gia tri trung voi x
void countSearch(List l, int x) {
    int count =0;
    Node *p = l.pHead;
    while(p != NULL){
        if(p->Key == x)
            count++;
        p = p->pNext;
    }
    printf("So phan tu tren danh dach co gia tri trung voi x: %d\n", count);
}
//xoa phan tu dau danh sach
void removeHead(List &l) {
    if(l.pHead == NULL)
        printf("Danh sach rong\n");
    Node *p = l.pHead;
    l.pHead = p->pNext;
    p->pNext = NULL;
    delete p;
    printf("Xoa thanh cong\n");
}
//xoa phan tu cuoi danh sach
void removeTail(List &l) {
    // if(l.pHead == NULL)
    //     printf("Danh sach rong\n");
    for(Node* p = l.pHead; p != NULL; p = p->pNext){
        if(p->pNext == l.pTail){
            delete l.pTail;
            p->pNext = NULL;
            l.pTail = p;
        }
    }
    printf("Xoa thanh cong\n");
}
//xoa toan bo danh sach
void removeAll(List &l) {
    Node *p;
    while(l.pHead != NULL){
        p = l.pHead;
        l.pHead = p->pNext;
        delete p;
    }
    l.pTail = NULL;
}
//gia tri lon nhat trong danh sach
void maxList(List l) {
    Node *p = l.pHead;
    int max = p->Key;
    while(p != NULL){
        if(p->Key > max)    
            max = p->Key;
        p = p->pNext;
    }
    printf("Gia tri nguyen lon nhat la: %d\n", max);
}
void menu() {
    printf("--------Danh sach lien ket--------\n");
    printf("1. Tao danh sach lien ket\n");
    printf("2. In danh sach lien ket\n");
    printf("3. So luong cac phan tu cua danh sach\n");
    printf("4. Tong gia tri cac phan tu tren danh sach\n");
    printf("5. Them phan tu vao dau danh sach\n");
    printf("6. Them phan tu vao cuoi danh sach\n");
    printf("7. Xoa phan tu dau danh sach\n");
    printf("8. Xoa phan tu cuoi danh sach\n");
    printf("9. So luong cac phan tu trung voi gia tri x\n");
    printf("10. Gia tri lon nhat trong danh sach\n");
    printf("11. Xoa tat ca cac phan tu trong danh sach\n");
    printf("0. Thoat\n");
    printf("----------------------------------\n");
}