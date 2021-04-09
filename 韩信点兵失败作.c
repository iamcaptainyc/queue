#include <stdio.h>
int main()
{
	int x,a[100],b[100],c[100],i,k;
	for(i=0;1;i++)
	{
		if(scanf("%d%d%d",&a[i],&b[i],&c[i])!=EOF)
		{
			;
		}
		else
		{
			k=i;
			break;
		}
	}
	for(i=0;i<=k;i++)
	{
		if(x%a[i]==0&&x%b[i]==0&&x%c[i]==0)
		{
            printf("case %d: %d\n",i,x);
		}
		else
		{
			printf("case %d: No anwser\n",i);
		}
	}
	return 0;
}
