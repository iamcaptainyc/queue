#include <iostream>

using namespace std;

int main()
{
	int n,m;
	int flag=0;
	cin>>n>>m;
	for(int i=0;i<=n;i++){
		for(int j=0;j<=n-i;j++){
			for(int k=0;k<=n-i-j;k=k+3){
				if(5*i+3*j+k/3==n&&i+j+k==m){
					flag=1;
					cout<<i<<' '<<j<<' '<<k<<' '<<endl;
				}
			}
		}
	}
	if(!flag) cout<<"no answer";
	return 0;
 } 
