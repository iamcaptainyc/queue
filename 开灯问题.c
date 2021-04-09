#include <stdio.h>
#include <stdlib.h>
void operate(int *p,int k,int n);
int main()
{
	int i,n,k,*p;
	scanf("%d%d",&n,&k);
	p=(int *)calloc(n,sizeof(int));
	for(i=0;i<n;i++)
	{
		*(p+i)=0;
	}
	operate(p,k,n);
	for(i=0;i<n;i++)
	{
		if(p[i]==1)
		{
			printf("%d ",i+1);
		}
	}
}
void operate(int *p,int k,int n)
{
	int i,j;
	for(i=1;i<=k;i++)
	{
		for(j=0;j<n;j++)
		{
			if((j+1)%i==0)
			{    
				if(*(p+j)==0)
				{
					*(p+j)=1;
				}
				else
				{
					*(p+j)=0;
				}
			}
		}
	}
}

