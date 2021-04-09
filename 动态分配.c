#include <stdio.h>
#include <stdlib.h>
int main()
{
	int *p=NULL,n,i,x;
	scanf("%d",&n);
	p=(int *)calloc(n,sizeof(int));
	if(p==NULL)
	{
		printf("No enough space!");
		exit(0);
	}
	for(i=0;i<n;i++)
	{
		scanf("%d",p+i);
	}
	int pos,j;
	for(i=0;i<n;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if(*(p+i)>*(p+j))
			{
				pos=*(p+i);
				*(p+i)=*(p+j);
				*(p+j)=pos;
			}
		}
	}
	for(i=0;i<n;i++)
    {
		printf("%d\n",p[i]);
	}
	return 0;
}
