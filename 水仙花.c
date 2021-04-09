#include <stdio.h>

int main()
{
	int x,a,b,c;
	scanf("%d",&x);
	a=x/100;
	b=x%100/10;
	c=x%10;
	if(a*a*a+b*b*b+c*c*c==x){
		printf("Yes");
	}
	else{
		printf("No");
	}
	return 0;
 } 
