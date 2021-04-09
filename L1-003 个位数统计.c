#include <stdio.h>
 int main()
 {
 	int num[10]={0};
 	int i,k;
 	long n;
 	scanf("%ld",&n);
 	while(n!=0)
 	{
 		k=n%10;
 		n/=10;
 		for(i=0;i<=9;i++)
 		{
 			if(k==i)
 			{
 				num[i]++;
			 }
		 }
	 }
	 for(i=0;i<=9;i++)
	 {
	 	if(num[i]!=0)
	 		printf("%d:%d\n",i,num[i]);
	 }
 }
