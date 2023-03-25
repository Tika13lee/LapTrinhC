#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node{
    int data;
    Node *link;
};
struct stack{
    Node *top;
};
void init(stack &s);
int isEmpty(stack s);
void push(stack &s, int x);
int pop(stack &s);
void docTu(char s[], char tu[], int &vt);
int laToanTu(char s[]);
float tinhToan(float toanHang1, float toanHang2, char toanTu);
float tinhBieuThuc(stack &s, char bieuThuc[]);

int main(){
    stack s;
    init(s);
    char bieuThuc[100] = "";
    printf("Nhap bieu thuc dang hau to: ");
    gets(bieuThuc);
    float kq = tinhBieuThuc(s, bieuThuc);
    printf("Gia tri cua bieu thuc la: %.1f", kq);
}

float tinhBieuThuc(stack &s, char bieuThuc[]){
    float kq;
    char t[10];
    int i=0;
    do{
        docTu(bieuThuc, t, i);
//        char *p = strtok(bieuThuc, " ");
//        while(p != '\0'){
//            puts(p);
//            p = strtok(NULL, " ");   
//        }
        if(laToanTu(t)){
            char toanTu = t[0];
            float toanHang1 = pop(s);
            float toanHang2 = pop(s);
            kq = tinhToan(toanHang2, toanHang1, toanTu);
            push(s, kq);
        }
        else{
            float toanHang = atof(t);
            push(s, toanHang);
        }
        i++;
    }while(bieuThuc[i] != '\0');
    return pop(s);
}
float tinhToan(float toanHang1, float toanHang2, char toanTu){
    float kq;
    switch(toanTu){
        case '+': kq = toanHang1 + toanHang2;   break;
        case '-': kq = toanHang1 - toanHang2;   break;
        case '*': kq = toanHang1 * toanHang2;   break;
        case '/': kq = toanHang1 / toanHang2;  
    }
    return kq;
}

int laToanTu(char* s){
    char c = s[0];
    if(c == '+' || c == '-' || c == '*' || c == '/')
        return 1;
    return 0;
}
void docTu(char s[], char tu[], int &vt){
    for(int i=0; i<strlen(tu); i++)
        tu[i] = ' ';
    int i=0;
    while(s[vt] != ' '){
        tu[i] = s[vt];
        vt++;
        i++;
    }
}
void init(stack &s){
    s.top = NULL;
}
int isEmpty(stack s){
    if(s.top == NULL)
        return 1;
    else
        return 0;
}
void push(stack &s, int x){
    Node *p = new Node;
    if(p==NULL)
        printf("Khong du bo nho\n");
    else{
        p->data = x;
        p->link = s.top;
        s.top = p;
    }
}
int pop(stack &s){
    int x;
    if(!isEmpty(s)){
        Node *p = s.top;
        s.top = p->link;
        x = p->data;
        delete(p);
        return x;
    }
}
