#include <stdio.h>
#include <math.h>
int main()
{
	int i,n,k;
	scanf("%d",&n);
	if(n==1)
	{
		printf("No");
		return 0;
	}
	k=sqrt(n);
	for(i=2;i<=k;i++)
	{
		if(n%i==0)
		{
			printf("No");
			return 0;
		}
	}
	printf("Yes");
	return 0;
}
