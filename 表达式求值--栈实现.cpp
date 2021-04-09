#include <iostream>
#define LEN 100
#define op(x) x 
using namespace std;

typedef struct{
	char *base;
	char *top;
	int stacksize;
}stack;

int ini(stack &L)
{
	L.base=(char *)malloc(sizeof(char)*LEN);
	if(L.base==0) return 2;
	L.top=L.base;
	L.stacksize=LEN;
	return 0;
}

int push(stack &L,char e)
{
	*L.top++=e;
	return 0;
}

int pop(stack &L,char &e)
{
	if(L.top==L.base) return 2;
	e=*--L.top;
	return 0;
}

char getop(stack L)
{
	if(L.top==L.base) return 0;
	return *(L.top-1);
}

int in(char ch)
{
	char a[7]={'+','-','*','/','(',')','='};
	for(int i=0;i<7;i++)
	{
		if(a[i]==ch) return 1;
	}
	return 0;
}

int judge(char ch)
{
	char b[5][2]={{'=','\0'},{')','\0'},{'+','-'},{'*','/'},{'(','\0'}};
	for(int i=0;i<5;i++){
		for(int j=0;j<2&&b[i][j]!='\0';j++){
			if(b[i][j]==ch)
				return i+1;
		}
	}
	return -1;
}

char precede(char ch1,char ch2)
{
	if(ch1=='('&&ch2==')') return '=';
	if(ch1=='('){
		return '<';
	}
	int i1=judge(ch1),i2=judge(ch2);
	if(i1==i2) return '<';
	else if(i1>i2) return '>';
	else return '<';
}

int operate(char i1,char optr,char i2)
{
	int a=i1-'0',b=i2-'0';
	switch(optr)
	{
		case '+':return a+b;
				break;
		case '-':return a-b;
				break;
		case '*':return a*b;
				break;
		case '/':return a/b;
				break;
	}
	return 0;
}

char eva(stack &OPTR,stack &OPND)
{
	push(OPTR,'=');
	char ch;
	cin>>ch;
	while(ch!='='||getop(OPTR)!='=')
	{
		if(!in(ch)){
			push(OPND,ch);
			cin>>ch;
		}
		else{
			switch(precede(getop(OPTR),ch))
			{
				case '<':
					push(OPTR,ch);
					cin>>ch;
					break;
				case '>':
					char theta;
					char a,b;
					pop(OPTR,theta);
					pop(OPND,b),pop(OPND,a);
					push(OPND,operate(a,theta,b)+'0');
					break;
				case '=':
					char x;
					pop(OPTR,x);
					cin>>ch;
					break;
			}
		}
	}
	return getop(OPND);
}

int main()
{
	stack OPND,OPTR;
	ini(OPND);
	ini(OPTR);
	cout<<eva(OPTR,OPND)-'0';
	return 0; 
 } 
