#include <stdio.h>
#include <math.h>
int main()
{
	double S,a,b,c,temp;
	a=1,b=1,temp=1,S=0;
	for(;fabs(temp)>=0.00001;b++)
	{
		a*=b;
		S+=temp;
		temp=1/a; 
	}
	printf("%lf\n",S);
	return 0;
 } 
