#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

int main()
{
	double count;
	string n;
	getline(cin,n);
	for(auto i:n){
		if(i=='2') count++;
	}
	int size=n.size();
	if(n[0]=='-') count*=1.5,size=n.size()-1;
	if(n.back()%2==0) count*=2;
	cout<<fixed<<setprecision(2)<<(count/(double)size)*100<<'%';
	return 0;
}
