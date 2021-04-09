#include <stdio.h>
#include <stdlib.h>
#define LEN 19

int judge(char a[]);

int z[11]={0,1,2,3,4,5,6,7,8,9,10};
int m[11]={1,0,10,9,8,7,6,5,4,3,2};
int mul[17]={7,9,10,5,8,4,2,1,6,3,7,9,10,5,8,4,2};

int main()
{
	int n;
	int i;
	char *a[n];
	scanf("%d",&n);
	getchar();
	int flag=0;
	for(i=0;i<n;i++){
		a[i]=(char *)malloc(LEN*sizeof(char));
		gets(a[i]);
	}
	for(i=0;i<n;i++)
	{
		if(judge(a[i])){
			flag=1;
			puts(a[i]);
		}
	}
	if(!flag) printf("All passed");
	return 0;
}

int judge(char a[])
{
	int i,sum=0,z1;
	for(i=0;i<LEN-1;i++)
	{
		sum+=(a[i]-'0')*mul[i];
	}
	z1=sum%11;
	for(i=0;i<11;i++)
	{
		if(z1==z[i])
			break;
	}
	if(i==3){
		if(!(a[LEN-1]=='x'||a[LEN-1]=='X'))
			return 1;
	}
	else if(m[i]!=a[LEN-1]-'0'){
		return 1;
	}
	return 0;	
}
