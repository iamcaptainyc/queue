#include <stdio.h>
#include <stdlib.h>
//#define LEN 400000
int main(int argc,char *argv[])
{
	FILE *fs,*fa;
	char *ch=NULL;
	//char ch[LEN]="\0";
	unsigned int size;
	if(argc!=3)
		printf("Usage : copy_self file1 file2(file1 will be copied to file2)");
	if((fs=fopen(argv[1],"rb"))==NULL)
	{
		printf("error : system cannot open the source file!");
		exit(1);
	}
	fseek(fs,0L,SEEK_END);
	size=ftell(fs);
	if((ch=(char *)calloc(size,sizeof(char)))==NULL)
		printf("nospace!"); 
	fseek(fs,0L,SEEK_SET);
	fread(ch,size,1,fs); 
	if(fclose(fs)!=0)
		printf("error : cannot close the source file!");
	if((fa=fopen(argv[2],"a+b"))==NULL)
	{
		printf("error : cannot open the copy file!");
		exit(2);
	}
	fwrite(ch,size,1,fa);
	if(fclose(fa)!=0)
		printf("error : cannot close the copy file!");
	free(ch);
	return 0;
}
