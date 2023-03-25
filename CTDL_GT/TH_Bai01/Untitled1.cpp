#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100
struct WORD {
    char Name[256];
    char Meaning[512];
};
WORD dict[MAX];
int n;
void inputWord(WORD &w);
void inputDict(WORD dict[], int &n);
void outputWord(WORD w);
void outputDict(WORD dict[], int n);
void writeFileWord(char *filename[], WORD w);
void writeFileDict(char filename[], WORD dict[], int n);
void readFileDict(char filename[], WORD dict[], int &n);
void deleteWord(WORD dict[], int &n, WORD w);
void searchWord(WORD dict[], int n, WORD w);
 

int main()
{
    WORD w;
	
	int chon=0;
	do {
		printf("-----------------MENU-----------------\n");		
		printf("1. Nhap tu vao tu dien\n");
		printf("2. Xuat tu dien\n");
		printf("3. Tra tu\n");
		printf("4. Xoa tu\n");
		printf("5. Ghi file tu dien\n");
		printf("0. Thoat\n");
		printf("Nhap lua chon cua ban: ");	scanf("%d", &chon);
		system("cls");
		switch(chon){
			case 1:
				inputDict(dict, n);
				break;
			case 2:
				outputDict(dict, n);
				break;
			case 3:
				searchWord(dict, n, w);
				break;
			case 4: 
				deleteWord(dict, n, w);
			case 5:
				writeFileDict("Bai1.txt", dict, n);
				break;
		}
	}while(chon !=0);
}
void searchWord(WORD dict[], int n, WORD w) {
	fflush(stdin);
	printf("Nhap tu can tra: ");	gets(w.Name);
	int i=0;
	while(i<n && strcmp(dict[i].Name, w.Name) !=0)
		i++;
	if(i<n)
		outputWord(dict[i]);
	else
		printf("Khong tim thay\n");
}
void deleteWord(WORD dict[], int &n, WORD w) {
 	fflush(stdin);
	printf("Nhap tu can xoa: ");	gets(w.Name);
	for(int i=0; i<n; i++) {
		if(strcmp(dict[i].Name, w.Name) == 0) {
			for(int j=i; j<n-1; j++) {
				strcpy(dict[j].Name, dict[j+1].Name);
				strcpy(dict[j].Meaning, dict[j+1].Meaning);				
			}
			n--;
		}
	}
	outputDict(dict, n);
}
void readFileDict(char filename[], WORD dict[], int &n) {
	FILE *f = fopen("Bai1.txt", "a");
	if(!f)
		printf("Khong mo duoc file\n");
	int i=0;
	while(!feof(f)){
		fscanf(f, "%s\t%s\t", &dict[i].Name, &dict[i].Name);
		i++;
	}	
	n=i;
	fclose(f);
}
void writeFileDict(char filename[], WORD dict[], int n) {
	FILE *f = fopen("Bai1.txt", "a");
	if(!f)
		printf("Khong mo duoc file\n");
	else {
		for(int i=0; i<n; i++) {
			fprintf(f, "%s\t%s\n", dict[i].Name, dict[i].Meaning);
		}
			printf("Ghi file thanh cong\n");
	} 
	fclose(f);
 }
void writeFileWord(char *filename, WORD w) {
	FILE *f = fopen("bai1.txt", "w");
	if(!f){
		printf("Khong mo duoc file\n");
	}
	else{
		fprintf(f, "%s", w.Name);
		fprintf(f, "%s", w.Meaning);
		printf("Ghi file thanh cong\n");
	}
	fclose(f);
}
void outputDict(WORD dict[], int n) {
	printf("--------------------------------\n");
	printf("Cac tu trong tu dien la: \n"); 
    for(int i=0; i<n; i++) {
        outputWord(dict[i]);
    }
}
void outputWord(WORD w) {
    printf("%-30s \t %-30s\n", w.Name, w.Meaning);
}
void inputDict(WORD dict[], int &n) {
	WORD w;
    printf("So luong tu: ");    scanf("%d", &n);
    for(int i=0; i<n; i++) {
        inputWord(dict[i]);
    }
}
void inputWord(WORD &w) {
    char s[30];
    fflush(stdin);
    printf("Nhap tu: ");    gets(s);    strcpy(w.Name, s);
    printf("Nhap nghia: "); gets(s);    strcpy(w.Meaning, s);
}
