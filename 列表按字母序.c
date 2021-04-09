#include <stdio.h>
#include <string.h>
#define LEN 100
void tidy_data(char str[][20],int i);
void show_data(char str[][20],int i);
int main()
{
	char str[LEN][20]={"\0"};
	int i=0,j;
	FILE *fp=NULL;
	while(scanf("%s",str[i])!=EOF)
	{
		i++;
	}
	tidy_data(str,i);
	if((fp=fopen("list01.txt","a+"))==NULL)
		fprintf(stderr,"Error in opening!");
	for(j=0;j<i;j++)
	{
		fprintf(fp,"%s\n",str[j]);
	}
	if(fclose(fp)!=0)
		fprintf(stderr,"error in closing!");
	show_data(str,i);
	return 0;
}
void tidy_data(char str[][20],int i)
{
	int j,k;
	char temp[20];
	for(j=0;j<i;j++)
	{
		for(k=j+1;k<i;k++)
		{
			if(strncmp(str[j],str[k],1)>0)
			{
				strcpy(temp,str[j]);
				strcpy(str[j],str[k]);
				strcpy(str[k],temp); 
			}
			else if(strncmp(str[j],str[k],1)==0)
			{
				if(strlen(str[j])>strlen(str[k]))
				{
					strcpy(temp,str[j]);
					strcpy(str[j],str[k]);
					strcpy(str[k],temp);
				}
			}
		}
	}
}
void show_data(char str[][20],int i)
{
	int j;
	for(j=0;j<i;j++)
	{
		printf("%s\n",str[j]);
	}
}
