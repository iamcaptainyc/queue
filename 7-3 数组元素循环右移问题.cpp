#include <iostream>
#define LEN 100
using namespace std;

int main()
{
	int n,m;
	cin>>n>>m;
	int a[LEN];
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	int t=a[n-1];
	for(int j=0;j<m;j++){
		for(int i=n-2+j;i>=j;i--){
			a[(i+1)%n]=a[i%n];
		}
	}
	a[(n-1+m)%n]=t;
	for(int i=0;i<n;i++){
		if(i!=0) cout<<' ';
		cout<<a[i];
	}
	return 0;
 } 
