#include <stdio.h>
#include <stdlib.h>
#define CNTL_Z '\032'
#define SLEN 50
int main()
{
	char file[SLEN];
	FILE *fp;
	char ch;
	long count,last;
	puts("please input the name of file:");
	gets(file);
	if((fp=fopen(file,"rb"))==NULL)
	{
		printf("reverse can't open %s\n",file);
		exit(1);
	}
	fseek(fp,0L,SEEK_END);
	last=ftell(fp);
	for(count=1L;count<=last;count++)
	{
		fseek(fp,-count,SEEK_END);
		ch=getc(fp);
		if(ch!=CNTL_Z&&ch!='\r')
			putchar(ch);
	}
	putchar('\n');
	if(fclose(fp)!=0)
		printf("error!can't close.");
	return 0;
 } 
