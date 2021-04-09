#include <iostream>
#include <iomanip>
#include <vector>
#include <string>

using namespace std;

int main()
{
	string str(" ");
	string st("chi1 huo3 guo1");
	int count=0,succeed=0,tag;
	while(str!="."){
		getline(cin,str);
		count++;
		int flag=str.find(st);
		
		if(flag!=-1){
			if(succeed==0) tag=count;
			succeed++;
		}
	}
	cout<<count-1<<endl;
	
	if(succeed==0) cout<<"-_-#";
	else cout<<tag<<' '<<succeed;
	
	return 0;
}
