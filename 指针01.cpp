#include <stdio.h>
void search(int *pa,int n,int *pmax,int *pflag);
int main()
{
	int a[9],max,flag,n,i;
	printf("please input number:");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	search(a,n,&max,&flag);
	printf("%d %d",flag,max);
	return 0;
 } 
 void search(int *pa,int n,int *pmax,int *pflag)
 {
 	int i,k=0;
 	for(i=1;i<n;i++)
 	{
 		*pmax=*(pa+k);
 		if(*(pa+i)>*pmax)
 		{
 			k=i;
		 }
	 }
	 *pflag=k;
	 *pmax=*(pa+k);
 }
