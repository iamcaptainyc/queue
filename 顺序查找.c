#include <stdio.h>
#define ARR_SIZE 40
int main()
{
	int n,i,pos;
	long num[ARR_SIZE],search;
	float score[ARR_SIZE];
	printf("please input the total number :\n");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("please input the number and the score:\n");
		scanf("%ld %f",&num[i],&score[i]);
	}
	printf("please input searching number:\n");
	scanf("%ld",&search);
	pos=searching(num,n,search);
	if(pos!=-1)
	{
		printf("%ld's score is %f\n",search,score[pos]);
	}
	else
	{
		printf("Not found!\n");
	}
	system("pause");
	return 0;
}
int searching(long a[],int n,long search)
{
	int i;
	for(i=0;i<n;i++)
	{
		if(a[i]==search)
		{
			return (i);
		}
	}
	return -1;
}
