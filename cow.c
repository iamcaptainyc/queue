#include <stdio.h>
#include <math.h>
#define LENR 1450 
#define LENC 500 

typedef struct{
	int f1;
	int f2;
	int mile;
}WAY;

int mid[100]={0},dismin,road;
WAY way[LENR];

int main()
{
	int i,j;
	int min=0;
	int cow,field;
	int cowfield[LENC]={0};
	scanf("%d%d%d",&cow,&field,&road);
	for(i=0;i<cow;i++)
	{
		scanf("%d",&cowfield[i]);
	}
	for(i=0;i<road;i++)
	{
		scanf("%d%d%d",&way[i].f1,&way[i].f2,&way[i].mile);
	}
	for(j=1;j<=field;j++)
	{
		int sum=0;
		for(i=0;i<cow;i++)
		{
			if(cowfield[i]==j) sum+=0;
			else
			{
				dismin=0;
				sum+=ways(cowfield[i],j,0,0);
			}
			
		}
		if(min==0) min=sum;
		else min=min<sum?min:sum;
	}
	printf("%d",min);
	return 0;
}

int ways(int a,int b,int distance,int k)
{
	int i;
	for(i=0;i<road;i++)
	{
		if(way[i].f1==a&&judge(way[i].f2))
		{
			mid[k]=a;
			if(way[i].f2!=b)
			{
				ways(way[i].f2,b,distance+way[i].mile,k+1);
			}
			else
			{
				if(dismin==0)
					dismin=distance+way[i].mile;
				else
				{
					dismin=dismin<(distance+way[i].mile)?dismin:(distance+way[i].mile);
				}
			}
			mid[k+1]=0;
		}
		if(way[i].f2==a&&judge(way[i].f1))
		{
			mid[k]=a;
			if(way[i].f1!=b)
			{
				ways(way[i].f1,b,distance+way[i].mile,k+1);
			}
			else
			{
				if(dismin==0)
					dismin=distance+way[i].mile;
				else
				{
					dismin=dismin<(distance+way[i].mile)?dismin:(distance+way[i].mile);
				}
			}
			mid[k+1]=0;
		}
	} 
	return dismin;
}

int judge(int c)
{
	int i;
	for(i=0;i<11;i++)
	{
		if(c==mid[i]) return 0;
	}
	return 1;
}
