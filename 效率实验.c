#include <stdio.h>
#include <math.h>
#include <time.h>
#define MAX 10
#define MAXK 1e7
#define X 1.1 
clock_t start,stop;
double duration;
double f1(int n,double a[],double x);
double f2(int n,double a[],double x);
int main()
{
	int i; 
	double a[MAX];
	for(i=0;i<MAX;i++)
		a[i]=(double)i;
	double x=X;
	start=clock();
	for(i=0;i<MAXK;i++)
		f1(MAX-1,a,x);
	stop=clock();
	duration=((double)(stop-start))/CLK_TCK/MAXK;
	printf("%6.2e\n",duration);
	
	start=clock();
	for(i=0;i<MAXK;i++)
		f2(MAX-1,a,x);
	stop=clock();
	duration=((double)(stop-start))/CLK_TCK/MAXK;
	printf("%6.2e\n",duration);
	
	return 0;
}

double f1(int n,double a[],double x)
{
	int i;
	double p=a[0];
	for(i=1;i<=n;i++)
	{
		p+=(a[i]*pow(x,i));
	}
	return p;
}

double f2(int n,double a[],double x)
{
	int i;
	double p=a[n];
	for(i=n;i>0;i--)
	{
		p=a[i-1]+x*p;
	}
	return p;
}
