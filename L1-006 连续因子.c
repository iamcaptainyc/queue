#include <stdio.h>
#include <math.h>
int main()
{
	int i,j,l,count,max=0;
	int n;
	int start;
	scanf("%d",&n);
	for(i=2;i<sqrt(n);i++)
	{
		l=n;
		j=i;
		count=0;
		while(l%j==0){
			l=l/j;
			j++;
			count++;
		}
		if(count>max){
			max=count;
			start=i;
		}
	}
	if(max){
		printf("%d\n",max);
		for(i=0;i<max;i++){
			if(i!=0) printf("*");
			printf("%d",start+i);
		}
	}
	else{
		printf("%d\n%d",1,n);
	}
	return 0;
}

