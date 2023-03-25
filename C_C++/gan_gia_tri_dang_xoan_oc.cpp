#include <iostream>
#include <cstdlib>
#include <iomanip>
using namespace std;
const int N=20;
int main()
{
	int A[N][N],n,value=0;
	cout<<"nhap vao cap ma tran: ";
	cin>>n;
	cout<<"xuat mang \n";
	int j=0;
	while(value<=n*n)
	{
		for(int i=0;i<n;i++)
			A[i][j]=value++;
		j++;
		for(int i=n-1;i>=0;i--)
			A[i][j]=value++;
		j++;
	}
	
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++) 
			cout<<setw(3)<<A[i][j];
		cout<<endl;
	}
	system("pause");
	return 0;
}