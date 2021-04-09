#include <stdio.h>
int Max(int a[]);
int main()
{
	int i,max;
	int a[4];
	for(i=0;i<4;i++)
	{
		printf("ÊäÈëÕûÊı£º\n");
		scanf("%d",&a[i]);
	}
	max=Max(a);
	printf("max=%d",max);
	system("pause");
	return 0;
}
int Max(int a[])
{
	int i,e;
	e=a[0];
	for(i=1;i<4;i++)
	{
		if(a[i]>e)
		{
			e=a[i];
		}
	}
    return e;
 } 
