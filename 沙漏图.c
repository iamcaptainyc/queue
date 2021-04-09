#include <stdio.h>

void print(long int j,long int i,char ch);

int main(void)
{
    long int num,sum=0,r,h;
    char ch;
    scanf("%d %c",&num,&ch);
    long int k=(num-1)/2;
    long int i=0;
    while(k-sum>=2*(++i)+1)
    {
        sum+=2*i+1;
    }
    i=i-1;
    r=num-2*sum-1;
    h=2*i+1;
    long int j;
    for(j=1;j<=2*i+1;j++)
    {
    	if(j<i+1)
    		print(j,i-j+1,ch);
    	else
    		print(h-j+1,i-(h-j),ch);
	}
	printf("%ld",r);
	return 0;
}

void print(long int j,long int i,char ch)
{
	long int k;
	for(k=1;k<=j-1;k++){
		printf(" ");
	}
	k=2*i+1;
	while(k--){
		printf("%c",ch);
	}
	/*for(k=1;k<=j-1;k++){
		printf(" ");
	}*/
	printf("\n");
}
