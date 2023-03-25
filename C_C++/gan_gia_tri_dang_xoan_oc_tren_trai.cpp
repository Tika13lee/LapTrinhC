#include<iostream>
#include<cstdlib>
#include<iomanip>
using namespace std;
const int N=20,M=15;
int main()
{
	int A[M][N],m,n,MaxR,MinR,MaxC,MinC,value=1;
	cout<<"nhap vao so dong/cot cua mang: ";
	cin>>m>>n;
	MinR=0;
	MinC=0;
	MaxR=m-1;
	MaxC=n-1;
	while(value<=m*n)
	{
		for(int j=MinC;j<=MaxC;j++)
			A[MinR][j]=value++;
		MinR++;
		for(int i=MinR;i<=MaxR;i++)
			A[i][MaxC]=value++;
		MaxC--;
		for(int j=MaxC;j>=MinC;j--)
			A[MaxR][j]=value++;
		MaxR--;
		for(int i=MaxR;i>=MinR;i--)
			A[i][MinC]=value++;
		MinC++;
	}
	cout<<"Xuat mang: \n";
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++)
			cout<<setw(3)<<A[i][j];
		cout<<endl;
	}
	system("pause");
	return 0;
}