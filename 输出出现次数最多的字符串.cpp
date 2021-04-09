#include <iostream>
#include <vector>
#include <string>

#define LEN 1000
using namespace std;

typedef struct{
	string st;
	int num=0;
}node;

int main()
{
	long long n;	
	while(cin>>n){
		if(n==0) break;
		vector<string> str(n);
		node no[LEN];
		cin.get();
		for(long long i=0;i<n;i++){
			getline(cin,str[i]);
		}
		for(int i=0;i<n;i++){
			int flag=0;
			for(int j=0;j<n;j++){
				if(no[j].st==str[i]){
					flag=1;
					no[j].num++;
					break;
				}
			}
			if(!flag){
				no[i].st=str[i];
				no[i].num++;
			}
		}
		int max=0;
		for(int i=0;i<n;i++){
			if(no[i].num>no[max].num) max=i;
		}
		cout<<no[max].st<<endl;
	}
	
}
