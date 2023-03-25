//Vấn đề 3
// #include <stdio.h>
// int main()
// {  
//     int ar[]={10,15,4,25,3,-4},*p, i;
//     p=&ar[2];
//     printf("Cac gia tri cua mang\n");
//     for(i=0;i<6;i++)
//         printf("ar[%d]=%4d\n",i,ar[i]); //10,15,4,25,3,-4
//     printf("\nCho biet gia tri cua cac bieu thuc\n");
//     printf("a) *(p+1)= %d\n", *(p+1)); //25
//     printf("b) p[-1]= %d\n",p[-1]); //15
//     printf("c) (ar-p)=%d\n",(ar-p)); //0-2=-2
//     printf("d) ar[*p++]=%d\n",ar[*p++]); //3
//     printf("e) *(ar+ar[2])=%d\n",*(ar+ar[2])); //3 (giá trị của ar[4])
// }



//Vấn đề 2
#include <stdio.h>
int main() 
{
    int a[10], *pa, x;
    a[0]=11; a[1]=22; a[2]=33; a[3]=44; 
    pa=&a[0]; 
    printf("\n%d", *pa); //11
    pa++; //pa=&a[1];
    printf("\n%d", *pa); //22
    printf("\n%d", *pa+1); //23 (lấy giá trị mà pa trỏ tới rồi cộng cho 1)
    printf("\n%d", *(pa+1)); //33 (pa=&a[2] rồi =pa)
    printf("\n%d", *++pa); //33 tương đương với *(++pa) (pa trỏ vào phần tử tiếp theo rồi lấy nội dung ổ nhớ)
    printf("\n%d", ++*pa); //34 (lấy nd ô nhớ pa trỏ tới rồi cộng thêm 1)
    printf("\n%d", *pa++); //34 (lấy giá trị mà pa trỏ tới rồi pa trỏ tới phtu tiếp theo)
    printf("\n%d", *++pa); //44
} 


//Vấn đề 1
// #include <stdio.h>
// int main()
// { 
//     int x=10;  int *xtro;  xtro=&x;
//     printf("\n1. Dia chi cua bien x la: %p",&x); //địa chỉ của biến x
//     printf("\n2. Dia chi cua bien xtro la: %p",&xtro); //địa chỉ của con trỏ xtro
//     printf("\n3. Noi dung cua bien x la: %d",x); //10
//     printf("\n4. Noi dung cua bien xtro la: %p",xtro); //địa chỉ của biến x 
//     printf("\n5. Gia tri ma xtro tro den: %d",*xtro); //10
//     *xtro = 50 ;  
//     printf("\n6. Gia tri cua x la: %d",x); //50
//     return 0;
// }