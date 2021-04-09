#include <stdio.h>
#include <math.h>
#define LEN 100
int n,a[LEN],p=0;

int judge(int sum)
{ 
	int k=sqrt(sum),i;
	for(i=2;i<=k;i++)
	{
		if(sum%i==0) return 0;
	}
	return 1;
}

int count(int k,int sum,int start)
{
	int i;
	if(k==0)
	{
		if(judge(sum)) p++;
	}
	else
	{
		for(i=start;i<n;i++)
			count(k-1,sum+a[i],i+1);
	}
	return p;
}

int main()
{
	int k,i;
	scanf("%d%d",&n,&k);
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	printf("%d",count(k,0,0));
	return 0;
}
