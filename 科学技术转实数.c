#include <stdio.h>
#include <stdlib.h>
#include <math.h>
double tranf(char *s);
int main()
{
	char *s;
	printf("please input a string :\n");
	s=(char *)malloc(100*sizeof(char)); 
	gets(s);
	printf("the result is %lf",tranf(s));
	return 0;
 } 
 double tranf(char *s)
 {
 	int i,e=0;
	double sign,power=1,value=0;
 	for(;*s==' '||*s=='\t'||*s=='\n';s++);
 	sign=1;
 	if(*s=='+'||*s=='-')
 	{
 		sign=(*s++=='+')?1:-1;
	 }
	 for(;*s>='0'&&*s<='9';s++)
	 {
	 	value=value*10+(*s-'0');
	 }
	 if(*s=='.')
	 {
	 	s++;
	 	for(;*s<='9'&&*s>='0';s++)
	 	{
		 	value=value*10+(*s-'0');
		 	power*=10;
		 }
		 value=value/power;
	 }
	 if(*s=='e'||*s=='E')
	 {
	 	s++;
	 	if(*s=='+'||*s=='-')
	 	{
	 		i=(*s++=='+')?1:-1;
		 }
		 for(;*s<='9'&&*s>='0';s++)
		 {
		 	e=e*10+(*s-'0');
		 }
		 if(i==1)
		 {
		 	value=value*pow(10,e);
		 }
		 else
		 {
		 	value=value/pow(10,e);
		 }
	 }
	 return value*sign;
 }
