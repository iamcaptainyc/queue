#include <iostream>
#include <string>
#include <stack>

using namespace std;

//这道题修改了很多版，中间过了三四天，原因在于没注意到这里的操作数可以是多位整数，也可以是实数，也可能带符号
//而且最开始时方法错了，判断优先级才是正解

/*输入格式:

输入在一行中给出不含空格的中缀表达式，可包含+、-、*、\以及左右括号()，表达式不超过20个字符。

输出格式:

在一行中输出转换后的后缀表达式，要求不同对象（运算数、运算符号）之间以空格分隔，但结尾不得有多余空格。*/ 

bool isnum(char a)
{
	return (a>='0'&&a<='9')||a=='.';
}

int prio(char a)
{
	if(a=='+'||a=='-') return 0;
	if(a=='*'||a=='/') return 1;
	if(a=='('||a==')') return 2;
	return -1;
} 

int main()
{
	string st;
	int flag=0;
	getline(cin,st);
	stack<char> signal;
	for(auto i=st.begin();i!=st.end();i++){
		if(isnum(*i)||(*i=='('&&prio(*(i+1))==0)||(!flag&&prio(*i)==0)){
			if(flag) cout<<' ';
			if(!flag) flag=1;
			if(isnum(*i)){//不带符号的操作数
				cout<<*i;
				while(isnum(*(i+1))){
					i++;
					cout<<*i;
				}
			}
			else if(prio(*i)==0){//开头带符号的操作数
				if(*i=='-') cout<<*i;
				while(isnum(*(i+1))){
					i++;
					cout<<*i;
				}
			}
			else{//中间带符号的操作数 
				if(*(i+1)=='-') cout<<*(i+1);
				i=i+2; 
				while(isnum(*i)){
					cout<<*i;
					i++;
				}
			}
			if(!signal.empty()&&signal.top()=='(') continue;
			if(!signal.empty()){
				while(!signal.empty()&&signal.top()!='('&&prio(signal.top())>=prio(*(i+1))){
						cout<<' '<<signal.top();
						signal.pop();
				}
			}
		}
		else{
			if(*i==')'){
				while(!signal.empty()){
					if(signal.top()=='('){
						signal.pop();
						break;
					}
					cout<<' '<<signal.top();
					signal.pop();
				}
				if(!signal.empty()){
					while(!signal.empty()&&signal.top()!='('&&prio(signal.top())>=prio(*(i+1))){
						
							cout<<' '<<signal.top();
							signal.pop();
						
					}
				}
			}
			else signal.push(*i);
		}
	}
	while(!signal.empty()){
		if(signal.top()=='('){
			signal.pop();
			break;
		}
		cout<<' '<<signal.top();
		signal.pop();
	}
	return 0;
}
//5+2*(5+(2*3-4)*2)/5
//2+(5+(2*3-4)*2)-5
//2-3+(2*3-4)+2
//+23-45*(+23)+(-1)
