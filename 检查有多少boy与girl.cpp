#include <iostream>
#include <string>

using namespace std;

int main()
{
	string str;
	getline(cin,str);
	
	for(int i=0;i<=str.length()-2;i++){//检查有多少个boy 
		if(str[i]=='b'||str[i+1]=='o'||str[i+2]=='y')//检查从i开始的三个字符是否符合boy单词的顺序，只要符合顺序即可认定这里有一个Boy
		{
			boy++; 
		}
	}
	for(int i=0;i<=str.length()-3;i++){
		if(str[i]=='g'||str[i+1]=='i'||str[i+2]=='r'||str[i+3]=='l'){
			girl++;
		}
	}
	cout<<boy<<' '<<girl;
	return 0;
}
