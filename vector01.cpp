#include <iostream>
#include <vector>
using namespace std;

int main()
{
	vector<int> a;
	a={1,2,3,4,5,6,7,8,9,10};
	vector<char> b;
	b={'a','3','d','s'};
	for(auto i:a) 
		cout<<i<<endl;
	cout<<a.capacity()<<' '<<a.size()<<' '<<a.empty()<<' '<<a.max_size()<<endl;;
	a.resize(11);
	for(auto i:a)
		cout<<i<<endl;
	b.resize(10,'*');
	for(auto i:b)
		cout<<i<<endl;
	a=b;
	cout<<a.at(12)<<endl; 
	return 0;
 } 
