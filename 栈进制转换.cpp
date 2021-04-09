#include <iostream>
#include <cstdlib> 
#define MAX_SIZE 100
#define ADDSIZE 10 

using namespace std;

typedef struct{
	long *base;
	long *top;
	int stacksize=MAX_SIZE;
}stack;

int ini(stack &k){
	k.base=(long *)calloc(MAX_SIZE,sizeof(long));
	if(!k.base) return 0;
	k.top=k.base;
	return 1;
}

long push(stack &k,long e)
{
	if(k.top-k.base>=k.stacksize){
		k.base=(long *)realloc(k.base,(k.stacksize+ADDSIZE)*sizeof(long));
		if(!k.base) return 0;
		return 1;
	}
	*k.top++=e;
	return 0;
}

long pop(stack &k,long &e){
	if(k.top==k.base){
		cout<<"no data"<<endl;
		return 0;
	}
	e=*--k.top;
	return e;
}

int getop(stack k,long &e)
{
	e=*(k.top-1);
	return e;
}

char a[16]={'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};

int main()
{
	stack k;
	ini(k);
	long n,e;
	int num;
	while(cin>>n){
		cout<<"input the number to switch or 0 to quit : "<<endl;
		cin>>num;
		while(num!=0){
			int t=n;
			if(t==0) 	
			{
				cout<<n;
				return 0;
			}
			while(t){
				push(k,t%num);
				t=t/num;
			}
			while(k.top!=k.base)
			{
				pop(k,e);
				if(num==16)
					cout<<a[e];
				else
					cout<<e;
			}
			cout<<endl<<"input the number to switch or 0 to quit : "<<endl;
			cin>>num;
		}
	}
	return 0;
}
