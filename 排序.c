#include <stdio.h>
#define ARR_SIZE 40
int main()
{
	int n,i,j;
	char select;
	long int temp2,num[ARR_SIZE];
	double temp,score[ARR_SIZE];
	printf("please input the total number:\n");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("please input the number and the score:\n");
		scanf("%ld %lf",&num[i],&score[i]);
    }
    printf("Wanna down or up?[D/U]\n");
    scanf(" %c",&select);
    if(select=='D')
    {
    	goto de;
	}
	else
	{
		goto up;
	}
de: for(i=0;i<n-1;i++)
    {
    	for(j=i+1;j<n;j++)
    	{
    		if(score[j]>score[i])
    		{
    			temp=score[i];
    			score[i]=score[j];
    			score[j]=temp;
    			temp2=num[i];
    			num[i]=num[j];
    			num[j]=temp2;
			}
		}
	}
	goto se;
up:	for(i=0;i<n-1;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if(score[j]<score[i])
			{
				temp=score[i];
    			score[i]=score[j];
    			score[j]=temp;
    			temp2=num[i];
    			num[i]=num[j];
    			num[j]=temp2;
			}
		}
	}
se:	printf("sorted result is:\n");
	for(i=0;i<n;i++)
	{
		printf("%ld %4.1lf\n",num[i],score[i]);
	}
	system("pause");
	return 0;
} 
