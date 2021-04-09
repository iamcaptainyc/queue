#include <stdio.h>
#include <stdlib.h> 
int main(int argc,char *argv[])
{
	int n;
	void sum(int m),mult(int m);
	void (*fancp)(int m);
	if((argc!=3)||n<=0)
    {   
	    printf("input as:\"sm n (!/+)(n>0)\"\n");
	} 
	n=atoi(argv[1]);
	switch(*argv[2])
	{
		case '+':fancp=sum;
		         break;
		case '!':fancp=mult;
		         break;
		default:exit(0);
	}
	(*fancp)(n);
 } 
 void sum(int m)
 {
 	int s=0,i;
 	for(i=1;i<=m;i++)
 	{
 		s+=i;
	 }
	 printf("sum=%d\n",s);
 }
 void mult(int m)
 {
 	long s=1,i=1;
 	for(;i<=m;i++)
 	{
 		s*=i;
	 }
	 printf("multiply=%ld",s);
 }
