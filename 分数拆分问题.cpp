#include <iostream>
#include <cmath>
#define LEN 100

using namespace std;

int main()
{
	double k,x,y;
	int count=0;
	double a[LEN],b[LEN];
	while(cin>>k){
		for(x=k;1/x<=1/k&&1/(k+1)+1/x>=1/k;x++){
			for(y=k;y<=x;y++){
					if(fabs(1/k-(1/x+1/y))<1e-6){
						a[count]=x;
						b[count++]=y;
					}
				}
			}
		cout<<count<<'\n';
		for(int i=count-1;i>=0;i--)
			cout<<"1/"<<k<<" = 1/"<<a[i]<<" + 1/"<<b[i]<<'\n';
	}
}
