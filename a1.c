#include <stdio.h>
int main(void)
{
	int num;
	scanf("%d",&num);
	printf("%lld",fact(num));
	return 0;
}

int fact(int n)
{
	int ans;
	if(n>1){
		ans=n*fact(n-1);
	}
	else{
		ans=1;
	}
	return ans;
}
