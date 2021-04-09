#include <iostream>
#include <string>

int main()
{
	using namespace std;
	string one("Ben JAMING");
	cout<<one<<endl;
	string two(10,'*');
	cout<<two<<endl;
	string three(one);
	cout<<three<<endl;
	one+='@';
	two="You are not";
	three[0]='F';
	string four=two+three;
	cout<<one<<endl<<four<<endl;
	char a[100]="that is my car!";
	string five(a,7);
	cout<<five<<endl;
	string six(a+2,a+4);
	cout<<six<<endl;
	string seven(two,1,2);
	cout<<seven<<endl;
	return 0;
 } 
