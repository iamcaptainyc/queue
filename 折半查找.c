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
		printf("please input the number and the score(°´ÕÕÉýÐò):\n");
		scanf("%ld %f",&num[i],&score[i]);
	}
	printf("please input searching number:\n");
	scanf("%ld",&search);
	pos=Binsearch(num,n,search);
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
int Binsearch(long a[],int n,long search)
{
	long low=0,high=n-1,mid;
	while(low<=high)
	{
		mid=(low+high)/2;
		if(search<a[mid])
		{
			high=mid-1;
		}
		else if(search>a[mid])
		{
			low=mid+1;
		}
		else
		{
			return mid;
		}
	}
	return -1;
}
