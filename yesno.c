#include <stdio.h>
#include <ctype.h>
char UserInput;
static void CleanStdin(void)
{
	while(getchar()!='\n')
	{
		;
	}
	
}
int YesOrNo(void)
{
	char answer;
	int result=-1;
	do
	{
		printf("(Y/N)");
		UserInput=getchar();
		answer=toupper(UserInput);
		if(answer=='Y')
		{
			result=1;
		}
		else if(answer=='N')
		{
			result=0;
		}
		else
		{
			printf("Input error.Please type 'Y'or'N'");
		}
		CleanStdin();
	}while(result!=1&&result!=0);
	return result;
}
