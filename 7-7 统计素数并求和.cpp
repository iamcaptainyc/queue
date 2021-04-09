#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	int n,m,sum=0,count=0;
	cin>>m>>n;
	if(m>n){
		int t;
		t=m;
		m=n;
		n=t;
	}
	for(int i=m;i<=n;i++){
		int j;
		int k=(int)sqrt(i);
		for(j=2;j<=k;j++){
			if(i%j==0){
				break;
			}
		}
		if(j>k&&i!=1){
			count++;
			sum+=i;
		}
	}
	cout<<count<<' '<<sum;
	return 0;
 } 
