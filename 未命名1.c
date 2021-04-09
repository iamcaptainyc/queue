#include<stdio.h>
#include<math.h>
int main()
{
	int n,k,i,m=0,x;
	printf("input a number:");
	scanf("%d",&x);
	for(n=2;n<=x;n=n+1)
	{
		k=sqrt(n);
		for(i=2;i<=k;i++)
		{
			if(n%i==0)break;
		}
		if(i>=k+1)
		{
			printf("%d\t",n);
			m=m+1;
		}
		if(m%10==0)printf("\n");
	}
	putchar('\n');
	return 0;
}
