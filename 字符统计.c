#include <stdio.h>
#define N 100
int main()
{
	char a[N];
	int i,x=0,y=0;
    scanf("%s",&a);
    for(i=0;a[i]!='\0';i++)
    {
    	if(((int)a[i]>=65&&(int)a[i]<=90)||((int)a[i]>=97&&(int)a[i]<=122))
    	{
    		x+=1;
		}
		else if((int)a[i]>=48&&(int)a[i]<=57)
		{
			y+=1;
		}
		else continue;
	}
	printf("%d %d",x,y);
	return 0;
}
