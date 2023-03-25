#include <stdio.h>
#include <string.h>
struct NgaySinh
{
    int ngay;
    int thang;
    int nam;
};
struct SinhVien{
    int ma;
    char ten[20];
    NgaySinh ngay;
};
struct Node
{
    SinhVien data;
    Node* link;
};
struct List
{
    Node* first;
    Node* last;
};
void init(List &l){
    l.first = l.last = NULL;
}
Node* getNode(SinhVien x){
    Node* p = new Node;
    if(p==NULL)
        return NULL;
    p->data = x;
    p->link = NULL;
    return p;
}
// void addHead(List &l, Node* p){
//     if(l.first == NULL)
//         l.first = l.last = p;
//     else{
//         p->link = l.first;
//         l.first = p;
//     }
// }
// void insertFisrt(List &l, SinhVien x){
//     Node* p = getNode(x);
//     if(p == NULL)
//         return;
//     else
//         addHead(l, p); 
// }
void addLast(List &l, Node* p){
    if(l.first == NULL)
        l.first = l.last = p;
    else{
        l.last->link = p;
        l.last = p;
    }
}
void insertLast(List &l, SinhVien x){
    Node* p = getNode(x);
    if(p == NULL)
        return;
    else
        addLast(l, p);
}
// void nhapSV(SinhVien &x){

// }
// void nhapDS(List &l){
//     int n;
//     printf("Nhap so luong sinh vien: ");
//     scanf("%d", &n);
//     SinhVien x;
//     for(int i = 0; i<n; i++){
//         nhapSV(x);
//         Node* p = getNode(x);
//         insertLast(l, p->data);
//     } 
// }
void RemoveList (List &L)
{	
	Node *p;
	while (L.first != NULL) 
	{
		p = L.first;
		L.first = p->link;
	    delete p;
	}
	L.last = NULL;
}
void tach(List L, List &L1, List L2){
    init(L1);
    init(L2);
    Node* p =L.first;
    while(p != NULL){
        if(strcmp(p->data.ten, "Kieu")==0)
            insertLast(L1, p->data);
        else
            insertLast(L2, p->data);
    }
    RemoveList(L);
}
int count(List L){
    int count = 0;
    Node* p = L.first;
    while (p!=NULL)
    {
        count ++;
        p = p->link;
    }
    return count;
}
// void interchange(SinhVien a[], int n){
//     for(int i=0; i<n-1; i++){
//         for(int j=i+1; j<n; j++){
//             if(a[i].ma < a[j].ma){
//                 SinhVien temp = a[i];
//                 a[i] = a[j];
//                 a[j] = temp;
//             }
//         }
//     }
// }
// void bubble(SinhVien a[], int n){
//     for(int i=0; i<n-1; i++){
//         for(int j=n-1; j>i; j--){
//             if(a[j].ma > a[j-1].ma){
//                 SinhVien temp = a[j];
//                 a[j] = a[j-1];
//                 a[j-1] = temp;
//             }
//         }
//     }
// }
// void selection(SinhVien a[], int n){
//     for(int i=0; i<n-1; i++){
//         int min = i;
//         for(int j=i+1; j<n; j++){
//             if(a[j].ma > a[min].ma){
//                 min = j;
//             }
//         }
//         if(min != i){
//             SinhVien temp = a[min];
//             a[min] = a[i];
//             a[i] = temp;
//         }
//     }
// }
// void insert(SinhVien a[], int n){
//     for(int i=1; i<n; i++){
//         int x = a[i].ma;
//         int pos = i-1;
//         while(pos >= 0 && a[pos].ma < x){
//             a[pos+1] = a[pos];
//             pos--;
//         }
//         a[pos+1].ma = x;
//     }
// }