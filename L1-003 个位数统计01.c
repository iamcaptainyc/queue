#include <stdio.h>
#define LEN 100

char num[LEN];

int main()
{
	int a[10]={0};
	int i,j;
	scanf("%s",num);
	for(i=0;num[i]!='\0';i++)
	{
		for(j=0;j<=9;j++)
		{
			if(num[i]-'0'==j)
				a[j]++;
		}
	}
	for(i=0;i<=9;i++)
	 {
	 	if(a[i]!=0)
	 		printf("%d:%d\n",i,a[i]);
	 }
}
