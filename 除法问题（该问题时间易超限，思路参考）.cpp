#include<stdio.h>
int main()
{
	int  n;
	scanf("%d",&n);
	int i,j;
	int m=1;
	for(i=12345;i<=98765;i++)
	{
		int x;
		int y;
		int t=i;
		int a[10]={0};
		if(i%n==0)
		{
			x=i/n;
			for(j=4;j>=0;j--)
			{
				a[j]=t%10;
				t/=10;
		    }
		}
		for(j=9;j>=5;j--)
		{
			a[j]=x%10;
			x/=10;
		}
		int flag=1;
		for(y=0;y<9;y++)
		{
			for(j=y+1;j<10;j++)
			{
				if(a[y]==a[j])
				{
					flag=0;
					break;
				}
			}
			if(flag==0)
			{
				break;
				
			}
		}
		if(flag==1)
		{
		   for(j=0;j<5;j++)
		   {
		   	printf("%d",a[j]);
			   }
			   printf(" / ");
			   for(j=5;j<10;j++)
			   {
			   	printf("%d",a[j]);
				   }	
				   printf(" = %d\n",n);
            m=0;

        }
    } 
    if(m==1)
	{
		printf("no answer");
	}
}
