#include <iostream>
#include <iomanip>
#include <vector>
#define LEN 10
using namespace std;

typedef struct{
	string a;
	double price;
}book;

int main()
{
	int n;
	scanf("%d",&n);
	vector<book> b(n);
	for(int i=0;i<n;i++){
		cin.get();
		getline(cin,b[i].a);
		cin>>b[i].price;
	}
	int min=0;
	double t;
	string str;
	for(int i=0;i<n;i++){
		min=i;
		for(int j=i;j<n;j++){
			if(b[j].price<b[min].price){
				min=j;
			}
		}
		
		t=b[min].price;
		b[min].price=b[i].price;
		b[i].price=t;
		
		str=b[min].a;
		b[min].a=b[i].a;
		b[i].a=str;
	}
	for(auto i:b){
		cout<<i.a<<' '<<fixed<<setprecision(1)<<i.price<<endl;
	}
 } 
