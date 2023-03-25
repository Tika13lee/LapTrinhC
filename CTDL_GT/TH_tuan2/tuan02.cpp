#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int slHoanVi;

void inputArr(int a[], int &n);
void outputArr(int a[], int n);
int ghiFile(char *filename, int a[], int n);
int docFile(char *filename, int a[], int &n);
void Swap(int &a, int &b);
void SelectionSort(int a[], int n );
void InsertionSort(int a[], int n);
void BubbleSort(int a[], int n);
void InterchangeSort(int a[], int n);
void QuickSort(int a[], int l, int r, int &slHoanVi);


int main()
{
	int a[100000], n, chon;
	clock_t start, end;
	double t;
	do{
		printf("-------------------------------------------\n");
		printf("1. Phat sinh mang\n");
		printf("2. Xuat mang\n");
		printf("3. Ghi mang vao file\n");
		printf("4. Doc mang tu file\n");
		printf("5. SelectionSort\n");
		printf("6. InsertionSort\n");
		printf("7. InterchangeSort\n");
		printf("8. BubbleSort\n");
		printf("9. QuickSort\n");
		printf("0. Thoat\n");
		printf("Ban chon: ");	scanf("%d", &chon);
		fflush(stdin);
		system("cls");
		switch(chon){
			case 1:
				inputArr(a, n);
				break;
			case 2:
				outputArr(a, n);
				break;
			case 3:
				ghiFile("mang5.txt", a, n);
				break;
			case 4: 
				docFile("mang5.txt", a, n);
				break;
			case 5:
				start = clock();
				SelectionSort(a, n);
				end = clock();
				t = end - start;
				printf("Thoi gian sap xep SelectionSort la: %f\n", t);
				break;
			case 6:
				start = clock();
				InsertionSort(a, n);
				end = clock();
				t = end - start;
				printf("Thoi gian sap xep InsertionSort la: %f\n", t);
				break;
			case 7:
				start = clock();
				InterchangeSort(a, n);
				end = clock();
				t = end - start;
				printf("Thoi gian sap xep InterchageSort la: %f\n", t);
				break;
			case 8:
				start = clock();
				BubbleSort(a, n);
				end = clock();
				t = end - start;
				printf("Thoi gian sap xep BubbleSort la: %f\n", t);
				break;
			case 9:
				slHoanVi=0;
				start = clock();
				QuickSort(a, 0, n-1, slHoanVi);
				end = clock();
				t = end - start;
				printf("Thoi gian sap xep QuickSort la: %f\n", t);
				printf("So lan hoan vi cac phan tu trong mang la: %d\n", slHoanVi);
				break;
		}
	}while(chon != 0);
}
//sap xep nhanh
void QuickSort(int a[], int l, int r, int &slHoanVi)
{ 	
	int	i, j, N, x;
	N=r;
  	x = a[(l+r)/2]; 
  	i = l; j = r;
  	do{
     	while(a[i] < x) i++;
     	while(a[j] > x) j--;
     	if(i <= j) { 
			Swap(a[i], a[j]);
			slHoanVi++;
       		i++ ; j--;
	 	}
	} while(i < j);
	if(l<j) QuickSort(a, l, j, slHoanVi);
	if(i<r) QuickSort(a, i, r, slHoanVi);
}	
//noi bot
void BubbleSort(int a[], int n)
{	
	slHoanVi=0;
	for (int i=0; i<n-1; i++)
		for (int j=n-1; j>i; j--)
		   if(a[j] < a[j-1]){
		   		Swap(a[j], a[j-1]);
				slHoanVi++;
		   }					 
	printf("So lan hoan vi cac phan tu trong mang la: %d\n", slHoanVi);
}
//doi cho truc tiep
void InterchangeSort(int a[], int n)
{	
	slHoanVi=0;
	for (int i=0 ; i<n-1 ; i++)
		for (int j=i+1; j < n ; j++)
		   if(a[i]>a[j]){
				Swap(a[i], a[j]);
				slHoanVi++;
			}
	printf("So lan hoan vi cac phan tu trong mang la: %d\n", slHoanVi);
}
				
//chen truc tiep
void InsertionSort(int a[], int n)
{	
	int pos, x;
	slHoanVi =0;
	for(int i=1; i<n; i++) 
	{	
		x = a[i]; 
		pos = i-1;
		while(pos>=0 && a[pos]>x){
			a[pos+1] = a[pos];
			slHoanVi++;
			pos--;
		}
		a[pos+1] = x;
	}
	printf("So lan hoan vi cac phan tu trong mang la: %d\n", slHoanVi);
}
//chon truc tiep
void SelectionSort(int a[], int n ) 
{
	slHoanVi=0;
	for (int i=0; i<n-1; i++)
	{  
		int min = i; 
		for(int j = i+1; j<n; j++)
	   	   	if (a[j] < a[min])
		   		min = j; 
		if (min != i) 	    
			Swap(a[min], a[i]);
			slHoanVi++;
	}
	printf("So lan hoan vi cac phan tu trong mang la: %d\n", slHoanVi);
}
void Swap(int &a, int &b)
{
	int  temp = a;
	a = b;
	b = temp;	
}
int docFile(char *filename, int a[], int &n){
	FILE* f = fopen(filename, "r");
	if(!f)
		return 0;
	int i=0;
	while(!feof(f)){
		fscanf(f, "%d", &a[i]);
		i++;
	}
	n=i;
	fclose(f);
	return 1;
}
int ghiFile(char *filename, int a[], int n){
	FILE* f = fopen(filename, "w");
	if(!f)
		return 0;
	for(int i=0; i<n; i++)
		fprintf(f, "%d\t", a[i]);
	fclose(f);
	return 1;
}
void outputArr(int a[], int n){
	printf("Cac phan tu cua mang la: \n");
	for(int i=0; i<n; i++){
		printf("%d\t", a[i]);
	}
	printf("\n");
} 
void inputArr(int a[], int &n){
	printf("So luong phan tu mang: ");
	scanf("%d", &n);
	srand(time(NULL));
	for(int i=0; i<n; i++){
		a[i] = rand();
	}
}


