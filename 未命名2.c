#include<stdio.h>
int main()
{
	int i=4;
	printf("%d,%d",i++>3?i++:3,i);
	return 0;
}
