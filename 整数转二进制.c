#include <stdio.h>
#define LEN 8*sizeof(int)
void itobs(int n,char *byte);
void show(const char *byte);

int main()
{
	char byte[LEN+1]; //数据字节数乘与位数为数据类型占的总位数
	int number;
	printf("please enter the number and see them in binary.\n");
	while(scanf("%d",&number)==1)
	{
		itobs(number,byte);
		printf("%-5d is ",number);
		show(byte);
		printf("enter the next number or empty line to quit.\n");
	}
	puts("Bye!");
	return 0;
 } 

void itobs(int n,char *byte)
{
	int i;
	for(i=LEN-1;i>=0;i--,n>>=1)
	{
		byte[i]=(01&n)+'0';//这里数组中储存的是字符不是数字，输出是格式符应该为字符输出。 
	}
	byte[LEN]='\0';
}

void show(const char *byte)
{
	int i=0;
	while(byte[i])
	{
		putchar(byte[i]);
		if(++i%4==0&&byte[i]) printf(" ");
	}
	putchar('\n');
}
