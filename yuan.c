#include <stdio.h>
#define PI 3.14
int main()
{
	double r,c,s;
	printf("please input r:");
	scanf("%lf",&r);
	c=2*PI*r;
	s=PI*r*r;
	printf("�ܳ�=%lf,���=%lf",c,s);
	return 0;
 } 
