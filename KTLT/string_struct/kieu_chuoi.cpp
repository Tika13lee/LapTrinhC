#include <stdio.h>
#include <string.h>
int inhoachucaidau(char s[])
{
    for(int i=0; s[i] != '\0'; i++)
    {
        if(s[i] >= 'A' && s[i] <= 'Z')
            s[i]+=32;
        if(s[i-1] == ' ' || i==0)
        {
            if(s[i] >= 'a' && s[i] <= 'z')
                s[i]-=32;
        }
    }
}
int xoa(char s[], int x)
{
    int n=strlen(s);
    for(int i=x; i<n; i++)
        s[i] = s[i+1];
            s[n-1] = '\0';
}
int standard(char s[])
{
    int n=strlen(s);
    for(int i=0; i<n; i++)
    {
        if(s[i] == ' ' && s[i+1] == ' ')
        {
            xoa(s, i);
            i--;
        }
    }
    if(s[0] == ' ')
        xoa(s, 0);
    if(s[n-1] == ' ')
        xoa(s, n-1);
}
int xoatatcakhoangtrang(char s[])
{
    for(int i=0; i<strlen(s); i++)
        if(s[i] == ' ')
            xoa(s, i);
}
int demtu(char s[])
{
    int n=strlen(s);
    int dem=0;
    if(s[0] != ' ')
        dem = 1;
    for(int i=0; i<n-1; i++)
    {
        if(s[i] == ' ' && s[i+1] != ' ')
            dem++;
    }
    return dem;
}
void xuattu(char s[])
{
    int n=strlen(s);
    for(int i=0; i<n; i++)
    {
        if(s[i] == ' ' && s[i+1] != ' ')
            printf("\n");
        else
            printf("%c", s[i]);
    }
}
int main()
{
    char s[50];
    printf("Nhap chuoi: ");
    fflush(stdin);
    gets(s);
    // printf("%d\n",strlen(s));

    // inhoachucaidau(s);
    // puts(s);

    // standard(s);
    // puts(s);

    // xoatatcakhoangtrang(s);
    // puts(s);

    // printf("So tu trong chuoi la : %d\n", demtu(s));

    // xuattu(s);


    return 0;
}