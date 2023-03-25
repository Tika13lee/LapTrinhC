#include <stdio.h>
#define MAX 100
int main() 
{
    int i, j, n;
    int a[MAX] = {0};
    printf("Nhap n: ");
    scanf("%d", &n );
    for ( i = 2; i <= n; i++ )
        if ( !a[i] ) //if(a[i] == 0)
        {
            printf("%d ", i );
            for ( j = i + i; j <= n; j += i ) 
                    a[j] = 1;
        }
    putchar( '\n' );
    return 0;
}