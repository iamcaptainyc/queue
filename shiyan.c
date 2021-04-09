#include <stdio.h>
int main()
{
	int x;
	int a;
	char y;
	x=scanf("%d",&a);
	y=getchar();
	printf("%d %c",x,y);
	if(getchar()=='\n')
		printf("yes");
	return 0;
}
