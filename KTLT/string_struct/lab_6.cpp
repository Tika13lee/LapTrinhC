#include <stdio.h>
#include <string.h>
#include <math.h>
#define MAX 100

typedef struct
{
    char HoLot[30], Ten[30], Ngaysinh[8], Noisinh[40];
}HOTEN;

typedef struct
{
    int D_win, D_word, D_excel, Tong;
    char XepLoai[10];
}DIEM;

typedef struct 
{
    HOTEN hoten;
    DIEM diem;
}HOCVIEN;

void NhapHoTen(HOTEN &t);
void NhapDiem(DIEM &d);
void output(HOCVIEN hv);
void tencot();
void output_kq(HOCVIEN hv);
void tencot_kq();
int main()
{
    HOCVIEN A[MAX];
    int chon, slhv=0;
    do
    {
        printf("\n----------MENU----------\n");
        printf("\n1. Them hoc vien vao danh sach");
        printf("\n2. Hien thi danh sach hoc vien");
        printf("\n3. Nhap diem cho hoc vien");
        printf("\n4. Ket qua thi");
        printf("\n0. Thoat");
        printf("\nBan chon ? ");
        scanf("%d", &chon);
        HOCVIEN hv;
        int i;
        switch(chon)
        {
            case 0:
                break;
            case 1:
                NhapHoTen(hv.hoten);
                A[slhv++] = hv;
                break;
            case 2:
                tencot();
                for(i=0; i<slhv; i++)
                {
                    output(A[i]);
                }
                printf("\n");
                break;
            case 3:
            	for(i=0; i<slhv; i++)
            	{
            		printf("\nNhap diem cho hoc vien %d\n", i+1);
					NhapDiem(A[i].diem);
            	}
				break;
            case 4:
            	tencot_kq();
            	for(int i=0; i<slhv; i++)
            		output_kq(A[i]);
            	break;
            default:
                printf("Sai chuc nang, vui long chon lai");
                break;
        }
    }
    while (chon);
}
void NhapHoTen(HOTEN &t)
{
    char s[40];
    fflush(stdin);
    printf("\nHo lot: "); gets(s); strcpy(t.HoLot, s);
    printf("\nTen: "); gets(s); strcpy(t.Ten, s);
    printf("\nNgay sinh: "); gets(s); strcpy(t.Ngaysinh, s);
    printf("\nNoi sinh: "); gets(s); strcpy(t.Noisinh, s);
}
void NhapDiem(DIEM &d)
{
    int temp;
    do
    {
        printf("\nNhap diem WIN: ");
        scanf("%d", &temp);
    }while(temp<0 || temp>10);
    d.D_win = temp;
    do
    {
        printf("\nNhap diem WORD: ");
        scanf("%d", &temp);
    }while(temp<0 || temp>10);
    d.D_word = temp;
    do
    {
        printf("\nNhap diem EXCEL: ");
        scanf("%d", &temp);
    }while(temp<0 || temp>10);
    d.D_excel = temp;

    d.Tong = d.D_win + d.D_word + d.D_excel;
    if(d.Tong >= 24)    strcpy(d.XepLoai, "Gioi");
    else if(d.Tong >= 18)   strcpy(d.XepLoai, "Kha");
    else if(d.Tong >= 15)   strcpy(d.XepLoai, "Trung binh");
    else    strcpy(d.XepLoai, "Kem");
}
void output(HOCVIEN hv)
{
    printf("| %-10s| %-10s| %-10s| %-10s|           |\n", 
		hv.hoten.HoLot, hv.hoten.Ten, hv.hoten.Ngaysinh, hv.hoten.Noisinh);
}
void tencot()
{
    printf("\n____________________________________________________________\n");
	printf("| %-10s| %-10s| %-10s| %-10s| %-10s|", "Ho lot", "Ten", "Ngay sinh", "Noi sinh", "Ghi chu");
	printf("\n____________________________________________________________\n");
}
void output_kq(HOCVIEN hv)
{
	printf("| %-10s| %-10s| %-10s| %-10s| %-10d| %-10d| %-10d| %-10d| %-10s|\n", 
		hv.hoten.HoLot, hv.hoten.Ten, hv.hoten.Ngaysinh, hv.hoten.Noisinh, 
		hv.diem.D_win, hv.diem.D_word, hv.diem.D_excel, hv.diem.Tong, hv.diem.XepLoai);
}
void tencot_kq()
{
    printf("\n_____________________________________________________________________________________________________________\n");
	printf("| %-10s| %-10s| %-10s| %-10s| %-10s| %-10s| %-10s| %-10s| %-10s|", "Ho lot", "Ten", "Ngay sinh", 
		"Noi sinh", "Diem Win", "Diem Word", "Diem Excel", "Diem Tong", "Xep loai");
	printf("\n_____________________________________________________________________________________________________________\n");
}
