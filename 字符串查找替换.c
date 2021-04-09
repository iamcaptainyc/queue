#include <stdio.h>
#include <string.h>
#define MAX 20
#define LEN 101
int main()
{
	int i,j,n;
	char str[MAX][LEN];
	scanf("%d",&n);
	while(getchar()!='\n');
	for(i=0;i<n;i++)
	{
		gets(str[i]);
	}
	for(j=0;j<n;j++)
	{
		char *p=NULL,count=0;
		if(strstr(str[j],"ong,")!=NULL&&(p=strstr(str[j],"ong."))!=NULL)
		{
			for(;;p--)
			{
				if(*p==' ') count++;
				if(count==3) break;
			}
			strcpy(p," qiao ben zhong.");
			puts(str[j]);
		}
		else
		{
			puts("Skipped");
		}
	}
	return 0;
}
