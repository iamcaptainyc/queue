#include <stdio.h>
#include <math.h>
int main()
{
	double a,b,c,s,area;
	printf("please input a,b,c(�ö��Ÿ���):");
	scanf("%lf,%lf,%lf",&a,&b,&c);
	if((a<b+c)&&(b<a+c)&&(c<a+b))
	{
		s=(a+b+c)/2;
	    area=sqrt(s*(s-a)*(s-b)*(s-c));
	    printf("the triangle area is %lf",area);
	}
	else
	{
		printf("a,b,c���ܹ���������!");
	}
    return 0;
 } 
