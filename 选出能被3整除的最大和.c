#include <stdio.h>
#include <math.h>
#define LEN 100
int max,i;

int count(int num[],int sum,int start,int k); 

int main()
{
	int num[LEN];
	char c=0;
	int k;
	for(i=0;c!=']'&&i<100;i++)
	{
		if(i==0) scanf("[%d,",&num[i]);
		else scanf("%d%c",&num[i],&c);
	 } 
	for(k=5;k>=1;k--)
	{
		count(num,0,0,k);
		if(max!=0) break;
	}
	printf("%d",max);
}

int count(int num[],int sum,int start,int k)
{
	int j;
	if(k==0)
	{
		if(sum%3==0) max=max>sum?max:sum;
	}
	else
	{
		for(j=start;j<i;j++)
			count(num,sum+num[j],j+1,k-1);
	}
	return 0;
}
