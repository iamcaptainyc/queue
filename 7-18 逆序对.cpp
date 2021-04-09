#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;
int main()
{
	int t,temp,m;
	cin>>t;
	vector<vector<int>> num(t);
	for(int i=0;i<t;i++){
		cin>>m;
		for(int j=0;j<m;j++){
			cin>>temp;
			num[i].push_back(temp);
		}
	}
	for(auto i:num){
		int count=0;
		for(auto j=i.begin();j!=i.end();++j){
			for(auto k=j;k!=i.end();++k){
				if(*k<*j) count++;
			}
		}
		cout<<count<<endl;
	}
	return 0;
}
