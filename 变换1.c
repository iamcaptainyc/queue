#include <stdio.h>
#include <math.h>
int main()
{
	double n[10],m[10],a,b=0;
	int i,l;
	n[0]=1,m[0]=1;
	for(i=0;;i++)
	{
		scanf("%lf %lf",&n[i],&m[i]);
		if(n[i]==0&&m[i]==0) break;
	}
	for(l=0;l<=i-1;l++)
	{
		for(a=n[l];a<=m[l];a++)
		{
			b+=1/pow(a,2);
		}
		printf("Case %d: %.5lf\n",l+1,b);
		b=0;
	}
	return 0;
}
