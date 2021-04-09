#include <stdio.h>
char *itobs(int n,char *ps);
void show_bin(char *ps);
int main()
{
	char bin[8*sizeof(int)+1];
	int number;
	puts("Enter number :");
	while(scanf("%d",&number)==1)
	{
		itobs(number,bin);
		printf("%d is \n",number);
		show_bin(bin);
	}
	puts("bye!");
	return 0;
}
char *itobs(int n,char *ps)
{
	int i,j;
	static int size=8*sizeof(int);
	for(i=size-1;i>=0;i--)
	{
		ps[i]=(01&n)+'0';
		n>>=1;
	}
	ps[size]='\0';
	return ps;
}
void show_bin(char *ps)
{
	int i;
	while(ps[i])
	{
		putchar(ps[i]);
		if(++i%4==0&&ps[i])
		{
			putchar(' ');
		}
	}
}
