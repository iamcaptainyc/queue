#include <stdio.h>
void hanoi(int n,char A,char B,char C)
{
	if(n==1)
	{
		printf("move dish %2d from %c to %c \n",n,A,B);
	}
	else
	{
		hanoi(n-1,A,C,B);
		printf("move dish %2d from %c to %c \n",n,A,B);
		hanoi(n-1,C,B,A);
	}
}
int main()
{
	int n;
	printf("please input number:\n");
	scanf("%d",&n);
	printf("the step of moving %2d dishes are:\n",n);
	hanoi(n,'A','B','C');
	return 0;
}
