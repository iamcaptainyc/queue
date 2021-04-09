#include <stdio.h>

int main()
{
	int f0,f1=1,f2=1,i;
	for(i=1;i<=20;i++)
	{
		printf("%d ",f1);
		f0=f1+f2;
		f1=f2;
		f2=f0;
		if(i%5==0) printf("\n");
	}
	return 0;
 } 
