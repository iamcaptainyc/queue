#include <iostream>
#include <algorithm>
#include <iomanip>

using namespace std;

typedef struct{
	double store;
	double price;
	double per;
}a;

bool cmpself(a x,a y){
	return x.per>y.per;
}

int main()
{
	int n,m;
	cin>>n>>m;
	a b[3];
	for(int i=0;i<n;i++){
		cin>>b[i].store;
	}
	for(int i=0;i<n;i++){
		cin>>b[i].price;
		b[i].per=b[i].price/b[i].store;
	}
	sort(b,b+n,cmpself);
	double sum=0;
	for(int i=0;m>=0;i++){
		if(m>b[i].store)
			sum+=b[i].price;
		else
			sum+=b[i].price*(m/b[i].store);
		m=m-b[i].store;
	}
	cout<<fixed<<setprecision(2)<<sum;
 }
