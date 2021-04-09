#include <stdio.h>
int get(int *ws,int *lc)
{
	int ch;
	*ws=*lc=0;
	printf("please enter a string:\n");
	while((ch=getchar())!=EOF)
	{
		switch(ch)
		{
			case ' ':
			case '\t':*ws=*ws+1;
			          break;
			case '\n':return 1;
			default:if(ch>='a'&&ch<='z')
			        {
			        	*lc=*lc+1;
					}
		}
	}
	return 0;
 } 
 int main()
 {
 	int ws,lc;
 	if(get(&ws,&lc)!=0)
 	{
 	    printf("ws=%d\ncl=%d\n",ws,lc);
     }
     else
     {
     	printf("NO STRING!");
	 }
 	return 0;
 }
