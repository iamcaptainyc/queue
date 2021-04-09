#include <iostream>
#include <cmath>

using namespace std;

int n,m;

int loc(string &st)
{
	long long sum=0,max=0;
	for(int i=0;i<n;i++){
		sum+=(st[i]-'0')*pow(2,n-1-i);
	}
	for(int i=0;i<n;i++){
		max+=pow(2,i);
	}
	return max-sum+1;
}

int main()
{
	cin>>n>>m;
	int count=0;
	for(int i=0;i<m;i++){
		char str[n+1];
		cin>>str;
		string st;
		for(int j=0;j<n;j++){
			if(str[j]=='y')
				st.push_back('1');
			else if(str[j]=='n')
				st.push_back('0');
		}
		cout<<loc(st)<<'\n';
	}
}
