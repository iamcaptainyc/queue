#include<stdio.h>
#include<math.h>
#define E 1e-6
int main()
{
	int a,b,c;
	double disc,p,q;
	printf("please input a,b,c:");
	scanf("%d,%d,%d",&a,&b,&c);
	for(;a<=E;)
	{
		printf("the 'a' is not bigger than 0,please reinput:");
		scanf("%d",&a);
	}
	disc=b*b-4*a*c;
	q=-b/(2*a);
	p=sqrt(fabs(disc))/(2*a);
	if(fabs(disc)<=E)
	{
		printf("Two equal real roots:x1=x2=%7.2f\n",q);
	}
	else if(fabs(disc)>0)
	{
		printf("Two different roots:x1=%7.2f,x2=%7.2f\n",p+q,p-q);
	}
	else
	{
		printf("two complex roots:\n");
		printf("x1=%7.2f + %7.2fi\n",q,p);
		printf("x1=%7.2f - %7.2fi\n",q,p);
	}
	return 0;
}
