#include <stdio.h>
#define PI 3.14
int main()
{
	double r,c,s;
	printf("please input r:");
	scanf("%lf",&r);
	c=2*PI*r;
	s=PI*r*r;
	printf("周长=%lf,面积=%lf",c,s);
	return 0;
 } 
