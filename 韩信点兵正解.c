#include <stdio.h>

int main()
{
	int a,b,c,s,i,flag;
	int count=0;
	while (scanf("%d%d%d",&a,&b,&c)!=EOF)
	{
		count++;
		flag=0;
		for(int i=10;i<=100;i++)
		{
			if (i%3==a&&i%5==b&&i%7==c)
			{
				flag = 1;
				printf("Case %d: %d\n",count,i);
			}
		}
		if(flag==0)
		    printf("Case %d: No answer",count);
	}
	return 0;

}

