#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
double f(double x)
{
	return x*x*x-3*x-1;
}

double point(double a,double b)
{
	return (a*f(b)-b*f(a))/(f(b)-f(a));
}
double root(double a,double b)
{
	double x,y,y1=f(a);
	do{
		x=point(a,b);
		y=f(x);
		if(y*y1>0) y1=y,a=x;
		else b=x;
	}while(fabs(y)>=0.000001);
	return x;
}

int main()
{
	double a,b;
	cin>>a>>b;
	cout<<"root="<<setprecision(10)<<showpoint<<root(a,b);
	return 0;
}
