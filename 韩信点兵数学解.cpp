#include <iostream>


using namespace std;

int main()
{
	int a,b,c,j=1,num;
	while(cin>>a>>b>>c){
	num=(70*a+21*b+15*c)%105;
	if(j!=1) cout<<endl;
	cout<<"Case "<<j++<<": ";
	if(num>=10&&num<=100){
		cout<<num;
	}
	else{
		cout<<"No answer";
	}
	}
	return 0;
 } 
