#include <stdio.h>
int main()
{
	float d;
	printf("Nhap nhiet do: ");
	scanf("%f", &d);
	if (d<0)
	   printf("Freezing weather \n");
    else if (d<10)
       printf("Very Cold weather \n");
    else if (d<20)
       printf("Cold weather \n");
    else if (d<30)
       printf("Nomal in Temp \n");
    else if (d<40)
       printf("Its Hot \n");
    else 
	   printf("Its Very Hot \n");
	
}