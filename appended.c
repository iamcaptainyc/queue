#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define BUF 1024
#define LEN 81

void append(FILE *fa,FILE *fs);

int main(void)
{
	FILE *fa,*fs;
	int files=0;
	char aname[LEN];
	char sname[LEN];
	
	printf("please input the name of appended file:");
	gets(aname);
	if((fa=fopen(aname,"a"))==NULL)
	{
		fprintf(stderr,"can't open %s !\n",aname);
		exit(2);
	}
	if(setvbuf(fa,NULL,_IOFBF,BUF)!=0)
	{
		fprintf(stderr,"cannot create output buffer!\n");
		exit(3);
	}
	printf("please input the source file name:");
	while(gets(sname)&&sname[0]!='\0')
	{
		if(strcmp(sname,aname)==0)
		{
			fprintf(stderr,"cannot append to itself!\n");
			exit(4);
		}
		else if((fs=fopen(sname,"r"))==NULL)
		{
			fprintf(stderr,"cannot open %s !\n",sname);
			exit(5);
		}
		else
		{
			append(fa,fs);
			if(fclose(fs)!=0)
			{
				fprintf(stderr,"cannot close %s !\n",sname);
				exit(6);
			}
			files++;
		}
		printf("please input the next filename :");
	}
	if(fclose(fa)!=0)
	{
		fprintf(stderr,"cannot close %s !",aname);
		exit(7);
	 }
	printf("we are done.\n %d files have been added.",files);
	return 0;
}

void append(FILE *fa,FILE *fs)
{
	size_t bytes;
	static char temp[BUF];
	while((bytes=fread(temp,sizeof(char),BUF,fs))>0)
	{
		fwrite(temp,sizeof(char),bytes,fa);
	}
}
