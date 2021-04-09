#include <iostream>

using namespace std;

int main()
{
	int n,m;
	while(cin>>n>>m){
		if((4*n-m)%2!=0||(4*n-m)<0||(4*n-m)/2>n) cout<<"No answer"<<'\n';
		else cout<<(4*n-m)/2<<' '<<n-(4*n-m)/2<<'\n';
	}
	return 0;
}
