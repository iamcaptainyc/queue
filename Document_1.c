#include <stdio.h>
#define LEN 100
int main()
{
	FILE *fp;
	char ch[LEN]={0};
	if((fp=fopen("wordsyu.txt","a+"))==NULL)
		printf("error:No space!");
	while(fgets(ch,100,stdin)!=NULL&&ch[0]!='\n')
		fputs(ch,fp); 
	if(fclose(fp)!=0)
		printf("Error in closing file!");
	if((fp=fopen("wordsyu.txt","r"))==NULL)
		printf("error:can't open!");
	while(fgets(ch,100,fp)!=NULL)
		fputs(ch,stdout);
	if(fclose(fp)!=0)
		printf("error: cannot close the file!");
	return 0;
 } 
