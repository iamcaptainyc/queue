#include <stdio.h>
#include <math.h>
int main()
{
	long a,b;
	scanf("%ld",&a);
	if(a<0)
	{
		printf("No");
		return 0;
	}
	b=sqrt(a);
	if(a==pow(b,2))
	{
		printf("Yes");
	}
	else
	{
		printf("No");
	}
	return 0;
}
