#include <iostream>
#include <cstdlib> 
#include <cstring>
#define LEN 100

using namespace std;

int oprd[LEN];
char optr[LEN];
int error;

int operate(int i1,char optr,int i2)
{
	int a=i1,b=i2;
	switch(optr)
	{
		case '+':return a+b;
				break;
		case '-':return a-b;
				break;
		case '*':return a*b;
				break;
		case '/':
				if(b==0){
					cout<<"ERROR";
					error=1;
				}
				else{
					return a/b;
				}
				break;
		default:cout<<"ERROR";
				error=1;
				break;
	}
	return 0;
}

int main()
{
	char str[LEN];
	cin.getline(str,LEN);
	int num=0;
	int a=0,b=0;
	for(int i=0;i<strlen(str);i++){
		if(str[i]=='='){
			oprd[a++]=num;
			break;
		}
		if(str[i]<='9'&&str[i]>='0'){
			num=num*10+str[i]-'0';//对付多位数字
		}
		else{
			oprd[a++]=num;
			num=0;
			optr[b++]=str[i];
		}
	}
	num=oprd[0];
	for(int i=1,j=0;optr[j]!=0;i++,j++){
		num=operate(num,optr[j],oprd[i]);
		if(error) return 0;
	}
	cout<<num;
	return 0;
}
