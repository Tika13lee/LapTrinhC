#include<iostream>
#include<cstdlib>
#include<cmath>
using namespace std;
void Nhap(int **a, int r, int c)
{
	for(int i=0;i<r;i++)
		for(int j=0;j<c;j++)
			a[i][j]=rand()%20+1;
}
void Xuat(int **a,int r, int c)
{
	for(int i=0;i<r;i++){
		for(int j=0;j<c;j++){
			cout<<a[i][j]<<"\t";
		}cout<<endl;
    }
}
int KTNT(int n)
{ 
	for(int i=0;i<sqrt((double)n);i++)
    {
		if(n%i==0)
			return 0; 
	    else 
            return 1; 
    }
}
//int tong(int **a, int r, int c)
//{
//    int kq=0;
//    for(int i=0;i<r;i++)
//		for(int j=0;j<c;j++)
//        {
//			if(KTNT(a[i][j])==true)
//            {
//				kq= kq+a[i][j];
//			}
//		}
//    return kq;
//}
int main()
{
	int **a;
	int r,c,kq=0 ;
    
	cout<<"nhap vao so dong/cot: ";
	cin>>r>>c;
	a=new int *[r];
	for(int i=0;i<r;i++)
	{
		a[i]=new int[c];
	}
	Nhap(a,r,c);
	cout<<"Xuat mang\n";
	Xuat(a,r,c);
	for(int i=0;i<r;i++)
		for(int j=0;j<c;j++)
        {
			if(KTNT(a[i][j])==1)
				kq+=a[i][j]; 
		}
	cout<<"tong cac so nguyen to trong mang la: \n"<<kq<<endl;
	for(int i = 0; i<r; i++)
  		 delete []a[i];
	delete []a;
	return 0;
}
