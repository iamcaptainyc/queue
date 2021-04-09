#include<stdio.h>
#include<math.h>
int main()
{
	int n,o,i;
	const int m;
	float k;
	printf("input a number:");
	scanf("%d",&m);
end:for(n=2;n<=m;n++)
	{
		k=sqrt(n);
		for(i=2;i<=k;i++)
		{
			if(n%i==0);
			goto end;
		}
        printf("%d",n);
		o=o+1;
		if(o%10==0)printf("\n");
	}
	return 0;
}


