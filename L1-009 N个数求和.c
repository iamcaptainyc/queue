#include <stdio.h>
#include <math.h>
#define LEN 100

long long GCD(long long a,long long b);

typedef struct F{
	long long nu;
	long long de;
}node;

int main()
{
	int n;
	int i=0;
	long inte;
	scanf("%d",&n);
	node a[LEN];
	while(i<n){
		scanf("%lld/%lld",&a[i].nu,&a[i].de);
		i++;
	}
	for(i=1;i<n;i++)
	{
		long long lcm,gcd;
		lcm=(a[0].de*a[i].de)/GCD(a[0].de,a[i].de);
		a[0].nu*=(lcm/a[0].de);
		a[i].nu*=(lcm/a[i].de);
		a[0].nu+=a[i].nu;
		a[0].de=lcm;
		gcd=GCD(a[0].nu,a[0].de);
		a[0].de/=gcd;
		a[0].nu/=gcd;
	}
	inte=a[0].nu/a[0].de;
	a[0].nu%=a[0].de;
	if(a[0].nu==0){
		printf("%ld",inte);
	}
	else if(!inte){
		printf("%lld/%lld",a[0].nu,a[0].de);
	}
	else{
		printf("%ld %lld/%lld",inte,a[0].nu,a[0].de);
	}
	return 0;
}

long long GCD(long long e,long long f)
{
	long c;
	while(e%f!=0)
	{
		c=e%f;
		e=f;
		f=c;
	}
	return fabs(f);
} 
 
