#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

//����ⲻ����sort��������Ϊ���ǲ��ȶ����򣬶�ѡ���������ȶ����� 

bool cmp_self(string a,string b)
{
	return a.length()<=b.length();
}

int main()
{
	vector<string> str;
	string st;
	cin>>st;
	while(st!="#"){
		str.push_back(st);
		cin>>st;
	}
	//sort(str.begin(),str.begin()+str.size(),cmp_self);
	for(int i=0;i<str.size();i++){
		int min=i;
		for(int j=i+1;j<str.size();j++){
			if(str[j].length()<str[min].length()) min=j;
		}
		if(i!=min) swap(str[i],str[min]);
	}
	for(auto i=str.begin();i!=str.end();i++){
		cout<<*i<<' ';
	}
	return 0;
 } 
