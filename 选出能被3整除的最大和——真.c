#include <stdio.h>
#define LEN 100
int main()
{
	int num,l0[LEN],l1[LEN],l2[LEN],i,sum=0;
	int j0=0,j1=0,j2=0;
	char c=0;
	for(i=0;c!=']'&&i<LEN;i++)
	{
		if(i==0) scanf("[%d%c",&num,&c);
		else scanf("%d%c",&num,&c);
		if(num%3==0)
		{
			l0[j0]=num;
			j0++;
		}
		else if(num%3==1)
		{
			l1[j1]=num;
			j1++;
		}
		else
		{
			l2[j2]=num;
			j2++;
		}
		sum+=num;
	}
	if(sum%3==0) printf("%d",sum);
	else
	{
		int sum1=0,sum2=0;
		sort(l1,j1);
		sort(l2,j2);
		if(sum%3==1)
		{
			if(j2<=1)
			{
				sum1=l1[0];
				printf("%d",sum-sum1);
			}
			else if(j1!=0)
			{
				sum1=l1[0];
				sum2=l2[0]+l2[1];
				printf("%d",sum-(sum1<=sum2?sum1:sum2));
			}
			else
			{
				sum2=l2[0]+l2[1];
				printf("%d",sum-sum2);
			}
		}
		else
		{
			if(j1<=1)
			{
				sum2=l2[0];
				printf("%d",sum-sum2);
			}
			else if(j2!=0)
			{
				sum1=l1[0]+l1[1];
				sum2=l2[0];
				printf("%d",sum-(sum1<=sum2?sum1:sum2));
			}
			else
			{
				sum1=l1[0]+l1[1];
				printf("%d",sum-sum1);
			}
		}
	}
	return 0;
 }
 
int sort(int a[],int j)
{
	int k,l,min;
	for(k=0;k<j;k++)
	{
		min=k;
		for(l=k+1;l<j;l++)
		{
			if(a[min]>a[l]) min=l;
		}
		a[k]=a[min];
	}
}
