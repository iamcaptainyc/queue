#include<stdio.h>
void func(char *B,char ch2,char ch3);
int main()
{
	char a[10]={"asdava"};
	char b='a',c='o';
	func(a,b,c);
	puts(a);
	return 0;
 } 

void func(char *B,char ch2,char ch3)

{
    int *p=B;
	int *pr=strchr(B,'/0');

    while(p!=NULL)

    {

    	p=strchr(p,ch2);

    	while(pr>p+1)

    		{

    			*pr=*(pr-1);

    			pr=pr-1;

    		}

    	*(p+1)=ch3;

    	if(p!=NULL) p=p+1;

    }
} 
