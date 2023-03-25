#include <stdio.h>
#include <ctype.h>
int main()
{
	float dc,a,b,c,dtk=0;
    int dt;
	char kv;
	printf("Nhap diem chuan: ");
	scanf("%f", &dc);
	printf("Nhap diem 3 mon thi: ");
	scanf("%f %f %f", &a,&b,&c);
    getchar();
	printf("Nhap vao khu vuc (A, B, C, X): ");
	scanf("%c", &kv);
    printf("Nhap doi tuong (1, 2, 3, 0): ");
	scanf("%d", &dt);
    dtk=a+b+c;
    if(a*b*c)
	{
        switch (kv) 
        {
            case 'A': dtk += 2; break;
            case 'B': dtk += 1; break;
            case 'C': dtk += 0.5;
        }
        switch (dt) 
        {
            case 1: dtk += 2.5; break;
            case 2: dtk += 1.5; break;
            case 3: dtk += 1;
        }
        if(dtk >= dc)
            printf("DAU [%.1f]\n",dtk);
        if(dtk < dc)
            printf("ROT [%.1f]\n",dtk);
    }
    else
        printf("ROT [%.1f] vi co mon diem 0\n", dtk);
	return 0;
} 