#include <stdio.h>
#define P 40
void Findmax(float score[],float *pmaxscore,int n,long num[],long *pmaxnum);
int main(void)
{
	long num[P],maxnum;
	float score[P],maxscore;
	int n,i;
	printf("the total number:\n");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("please input the number and the score:\n");
		scanf("%ld %f",&num[i],&score[i]);
	}
	Findmax(score,&maxscore,n,num,&maxnum);
	return 0;
}
void Findmax(float score[],float *pmaxscore,int n,long num[],long *pmaxnum)
{
	int i;	 	
	*pmaxscore=score[0];
	*pmaxnum=num[0];
    for(i=1;i<n;i++)
	{	
	    if(score[i]>*pmaxscore)
		{
			*pmaxscore=score[i];
			*pmaxnum=num[i];
		}
	}
	printf("%ld %4.1f",*pmaxnum,*pmaxscore);
} 
