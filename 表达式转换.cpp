#include <iostream>
#include <string>
#include <stack>

using namespace std;

//������޸��˺ܶ�棬�м���������죬ԭ������ûע�⵽����Ĳ����������Ƕ�λ������Ҳ������ʵ����Ҳ���ܴ�����
//�����ʼʱ�������ˣ��ж����ȼ���������

/*�����ʽ:

������һ���и��������ո����׺���ʽ���ɰ���+��-��*��\�Լ���������()�����ʽ������20���ַ���

�����ʽ:

��һ�������ת����ĺ�׺���ʽ��Ҫ��ͬ������������������ţ�֮���Կո�ָ�������β�����ж���ո�*/ 

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
			if(isnum(*i)){//�������ŵĲ�����
				cout<<*i;
				while(isnum(*(i+1))){
					i++;
					cout<<*i;
				}
			}
			else if(prio(*i)==0){//��ͷ�����ŵĲ�����
				if(*i=='-') cout<<*i;
				while(isnum(*(i+1))){
					i++;
					cout<<*i;
				}
			}
			else{//�м�����ŵĲ����� 
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
