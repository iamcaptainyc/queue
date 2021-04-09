#include <iostream>
#include <cmath>
#include <string>

using namespace std;

bool isnum(char a){
	return a>='0'&&a<='9';
}

int st2num(string i)//转化多位数的整数部分 
{
	int j=i.length()-1;
	double l=0;
	for(auto k=i.begin();k!=i.end();k++){
		l+=(*k-'0')*pow(10,j--);
	}
	return l;
}

int main()
{
	string st;
	getline(cin,st);
	for(auto i=st.begin();i!=st.end();i++){
		if(isnum(*i)&&isnum(*(i+1))&&*(i+2)=='#'){
			string num;
			while(isnum(*i)){
				num.push_back(*i);
				i++;
			}
			char ch=st2num(num)+96;
			cout<<ch; 
		}
		else if(isnum(*i)){
			char ch=*i-'0'+96;
			cout<<ch;
		}
		else{
			cout<<*i;
		}
	}
	return 0;
}
