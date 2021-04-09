#include <iostream>
#include <vector>
#include <string>
using namespace std;

typedef struct{
	string str;
	char m;
}ch;

int main()
{
   
    int n;
    cin>>n;
    vector<ch> c(n);
    for(int i=0;i<n;i++)
    {
    	cin>>c[i].m;
    	cin.get();
    	getline(cin,c[i].str);
	}
	int pos;
    for(auto i:c){
    	pos=i.str.rfind(i.m);
    	if(pos==-1){
    		cout<<"Not Found"<<endl;
		}
		else{
			cout<<"index = "<<pos<<endl;
		}
	}
    return 0;
}
