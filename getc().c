#include <stdio.h>
#include <stdlib.h>
int main()
{
	FILE * fp;
	char words[100];
	fp=fopen("text.txt","a+");
	if(fp==NULL)
	{
		printf("error : file can't be open!\n");
		exit(1);
	}
	fgets(words,100,fp);
	puts(words);
	fclose(fp);
	fopen("text.txt","a+");
	printf("please input data to add to the file:\n");
	while(gets(words)!=NULL&&words[0]!='\0')
	{ 
	    fprintf(fp,"%s",words);
    }
    fclose(fp);
    fp=fopen("text.txt","a+");
    rewind(fp);
    while(gets(words)!=NULL&&words[0]!='\n')
    {
    	puts(words);
	}
	if(fclose(fp)!=0)
	{
		fprintf(stderr,"error closing file\n");
	}
	return 0;
 } 
