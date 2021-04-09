#include <iostream>
#include <string>

using namespace std;

typedef struct{
	string a;
	int price;
}book;

int main()
{
	book d;
	getline(cin,d.a);
	cin>>d.price;
	cout<<d.a<<endl<<d.price<<endl;
	return 0;
 } 
