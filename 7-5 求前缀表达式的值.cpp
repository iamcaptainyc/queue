#include <iostream>
#include <string>
#include <iomanip>
#include <cmath>
#include <cstdlib>

using namespace std;

double part(string::iterator &ch);

bool isnum(char ch)
{
	return ch>='0'&&ch<='9'||ch=='.';
}

double st2num(string i)//转化多位数的整数部分 
{
	int j=i.length()-1;
	double l=0;
	for(auto k=i.begin();k!=i.end();k++){
		l+=(*k-'0')*pow(10,j--);
	}
	return l;
}

string st;

int main()
{
	getline(cin,st);
	string::iterator i=st.begin();
	cout<<fixed<<setprecision(1)<<part(i);
}

double part(string::iterator &ch)
{
	if(*ch==' ') ch++;
	if(ch!=st.end()&&(isnum(*ch)||(*ch=='-'||*ch=='+')&&isnum(*(ch+1)))){//处理操作数部分 
		bool flag=false;
		int cnt=0;
		double sum=0,temp;
		string num;
		
		if(*ch=='-'){
			flag=true;
			ch++;
		}
		else if(*ch=='+') ch++;
		
		while(isnum(*ch)){
			if(*ch=='.') break;
			num.push_back(*ch);
			ch++;
		}
		sum=st2num(num);
		num.clear();
		if(*ch=='.'){//处理小数部分 
			ch++;
			cnt=1;
			while(isnum(*ch)){
				temp=(*ch-'0')/pow(10,cnt++);
				sum+=temp;
				ch++;
			}
		}
		if(flag) sum=-sum;
		return sum;
	}
	else{//处理操作符 
		char c=*ch;
		double a=part(++ch);
		double b=part(++ch);
		switch(c){
			case '+':
				return a+b;
				break;
			case '-':
				return a-b;
				break;
			case '*':
				return a*b;
				break;
			case '/':
				if(b==0){//返回错误信息 
					puts("ERROR");
					exit(0);
				}
				return a/b;
				break;
			default:
				puts("ERROR");
				exit(0);
		}
	}
 }
 //+ + 2.1 * 10 - 4.5 4 / 8.4 4
 //+ + 20.62 * -12.5 - 7.3 49.2 / 6.4 4
