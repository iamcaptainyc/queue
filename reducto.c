#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LEN 40
int main(int argc,char *argv[])
{
	FILE *in,*out;
	int ch,count=0;
	char name[LEN];
	if(argc<2)
	{
	    fprintf(stderr,"Usage: %s filename\n",argv[0]);
	    exit(1);
	}
	if((in=fopen(argv[1],"r"))==NULL)
	{
		fprintf(stderr,"the file can't be open\n");
		exit(2);
	}
	strcpy(name,"reduc.txt");
	if((out=fopen(name,"w"))==NULL)
	{
		fprintf(stderr,"Can't creat the file\n");
		exit(3);
	}
	while((ch=getc(in))!=EOF)
	{
		if(count++%3==0)
		    putc(ch,out);
	}
	if(fclose(in)!=0||fclose(out)!=0)
	{
	    fprintf(stderr,"error: can not close the files!\n");
    }
	return 0;
	
}
