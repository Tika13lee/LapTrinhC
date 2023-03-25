#include<iostream>
#include <cmath>
using namespace std;
bool KTNT(int n)
{
	bool kq=true;
	for(int i=2;i<sqrt(double(n));i++)
    {
		if(n%i==0)
			return kq=false;
		else
			return kq;
	}
}
int main()
{
	int n,dem=0;
	cout<<"nhap so luong phan tu: ";
	cin>>n;
	int *a= new int[n];
	for(int i=0;i<n;i++)
	{
		cout<<"nhap gia tri phan tu thu "<<i+1<<": ";
		cin>>a[i];
	}
	cout<<"\nXuat Mang\n";
	for(int i=0;i<n;i++)
		cout<<a[i]<<" ";
	cout<<endl;
	for(int i=0;i<n;i++)
		if(KTNT(a[i])){
			dem++;
			if(dem==1)
				cout<<"vi tri snt dau tien la "<<i<<endl;
		}
	delete[] a;
	a=nullptr;
	system("pause");
	return 0;
}