#include <iostream>
#include <string>

using namespace std;

int main()
{
	string str;
	getline(cin,str);
	
	for(int i=0;i<=str.length()-2;i++){//����ж��ٸ�boy 
		if(str[i]=='b'||str[i+1]=='o'||str[i+2]=='y')//����i��ʼ�������ַ��Ƿ����boy���ʵ�˳��ֻҪ����˳�򼴿��϶�������һ��Boy
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
