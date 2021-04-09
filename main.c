#include <stdio.h>
#include "yesno.h"
int main()
{
	printf("Do you love Lady Gaga?\n");
	if(YesOrNo())
	{
		printf("Oh,yes,we love her too!\n");
	}
	else
	{
		printf("Exactly!We love Michael Jackson forever!\n");
	}
	printf("Your put is '%c'",UserInput);
	system("pause");
	return 0;
}
