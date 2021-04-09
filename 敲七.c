#include <stdio.h>
int main()
{
	int n,a[10],i,j,k,h;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		h=i;
		for(j=0,k=0;i>0;k++,j++)
		{
			a[j]=i%10;
			i=i/10;
		}
		i=h;
		if(i%7==0)
		{
			printf("%d\n",i);
		}
		else
		{
			for(j=0;j<=k;j++)
			{
				if(a[j]==7)
				{
					printf("%d\n",i);
					break;
				}
			}
		}
	}
	return 0;
 } 
