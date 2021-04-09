#include <stdio.h>
#include <string.h>

void star(char s[])
{
	int i,j; 
	for(i=0;i<strlen(s);i++)
	{
		if(s[i]>='a'&&s[i]<='z'){
			for(j=strlen(s);j>i;j--)
			{
				s[j+1]=s[j];
			}
			s[i+1]='*';
		}
	}
}

int main()
{
	char s[100];
	gets(s);
	star(s);
	puts(s);
	return 0;
}


