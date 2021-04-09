#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main()
{
	long long n;
	while(cin>>n){
		int mul=7;
		for(int i=0;i<n;i++){
			mul*=7;
			mul&=0xfffffff;
		}
		mul%=1000;
		cout<<setfill('0')<<setw(3)<<mul<<endl;
	}
	return 0;
}
