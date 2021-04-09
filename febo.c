#include <stdio.h>
int main()
{
	long i,f1=1,f0,f2=1,n;
	printf("input n:");
	scanf("%ld",&n);
	printf("%ld\t\t%ld\t\t",f1,f2);
	for(i=3;i<=n;i++)
	{
		f0=f1+f2;
		printf("%ld\t\t",f0);
	    f1=f2;
	    f2=f0;
		if(i%5==0)
		{
			printf("\n");
		}
	}
	system("pause");
	return 0;
}
