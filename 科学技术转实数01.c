#include <stdio.h>
#include <stdlib.h>
#include <math.h>
double tranf(char *s);
int main()
{
	char *s;
	s=(char *)malloc(100*sizeof(char));
	printf("please input a string :");
	gets(s);
	printf("the result is %lf",tranf(s));
	return 0;
}
double tranf(char *s)
{
	int i,e=0;
	double value=0,sign,power=1;
	for(;*s==' '||*s=='\n'||*s=='\n';s++);
	sign=1;
	if(*s=='+'||*s=='-')
	{
		sign=(*s++=='+')?1:-1;
	}
	for(;*s>='0'&&*s<='9';s++)
	{
		value=value*10+*s-'0';
	}
	if(*s=='.')
	{
		s++;
		for(;*s<='9'&&*s>='0';s++)
		{
		    value=value*10+*s-'0';
		    power*=10;
		}
		value/=power;
	}
	if(*s=='e'||*s=='E')
	{
		s++;
		i=(*s++=='+')?1:-1;
		for(;*s<='9'&&*s>='0';s++)
		{
			e=e*10+*s-'0';
		}
		if(i==1)
		{
			value*=pow(10,e);
		}
		else
		{
			value/=pow(10,e);
		}
	}
	return value*sign;
}
