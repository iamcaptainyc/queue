#include <iostream>
#include <cmath>

using namespace std;
int main()
{
	int n,a;
	long long sum=0;
	cin>>n;
	long i1=pow(10,n-1);
	long i2=pow(10,n);
	for(long long i=i1;i<i2;i++){
		long long t=i,t0;
		sum=0;
		while(t!=0){
			a=t%10;
			t0=1;
			for(int j=1;j<=n;j++){//自己写pow函数可以提高速度 
				t0*=a;
			}
			sum+=t0;
			t=t/10;
			if(sum>i) break;
		}
		if(sum==i){
			cout<<i<<endl;
		}
	}
	return 0;
}
