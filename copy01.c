#include <stdio.h>
#include <stdlib.h>
#define LEN 81
#define BUF 1024

int main(int argc,char *argv[])
{
	FILE *fs,*fc;
	unsigned int size;
	char *ch;
	if(argc!=3)
	{
		printf("Usage: copy01 file1 file2 (file1 will be copied to file2)");
		exit(0);
	}
	if((fs=fopen(argv[1],"rb"))==NULL)
	{
		fprintf(stderr,"cannot open the %s !",argv[1]);
		exit(2);
	}
	
	fseek(fs,0L,SEEK_END);
	size=ftell(fs);
	if((ch=(char *)calloc(size,sizeof(char)))==NULL)
	{
		fputs("no space",stderr);
		exit(3);
	}
	fseek(fs,0L,SEEK_SET);
	fread(ch,size,1,fs);
	if((fc=fopen(argv[2],"ab"))==NULL)
	{
		fprintf(stderr,"cannot create the copy file!");
		exit(4);
	}
	fwrite(ch,size,1,fc);
	free(ch);
	if(fclose(fs)&&fclose(fc)!=0)
	{
		fputs("cannot close the files",stderr);
		exit(5);
	}
	printf("copy done.");
	return 0;
}
