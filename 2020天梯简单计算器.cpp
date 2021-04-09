#include <iostream>
#include <cstdlib> 
#include <cstring>
#define LEN 1000

using namespace std;

int oprd[LEN];
char optr[LEN];
int error;

int operate(int i1,char optr,int i2)
{
	int a=i2,b=i1;
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
					cout<<"ERROR: "<<a<<"/0";
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
	int num=0;
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>oprd[i];
	}
	for(int i=0;i<n-1;i++){
		cin>>optr[i];
	}
	num=oprd[n-1];
	for(int i=n-2,j=n-2;optr[j]!=0;i--,j--){
		num=operate(num,optr[j],oprd[i]);
		if(error) return 0;
	}
	cout<<num;
	return 0;
}
