#include <iostream>
#include <iomanip>

using namespace std;
int main()
{
	long f1=1,f2=1,f0,n;
	cin>>n;
	if(n==1||n==2) {
		cout<<1;
		return 0;
	}
	for(long i=0;i<n-2;i++)
	{
		f0=f1+f2;
		f0%=10;
		f1=f2;
		f2=f0;
	}
	cout<<f0;
	return 0;
}
