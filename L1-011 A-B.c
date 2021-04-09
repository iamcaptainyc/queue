#include <stdio.h>
#include <string.h>
#define LEN 10001
int main()
{
	char a[LEN];
	char b[LEN];
	char ch;
	char *p;
	int i;
	gets(a);
	gets(b);
	for(i=0;b[i]!='\0';i++)
	{
		ch=b[i];
		while((p=strchr(a,ch))!=NULL){
			
			while(*p!='\0'){
				*p=*(p+1);
				p=p+1;
			}
		}
	}
	printf("%s",a);
	return 0;
}
