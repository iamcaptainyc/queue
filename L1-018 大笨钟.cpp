#include <iostream>
#include <string>

using namespace std;

int main(){
	string h,m;
	char c;
	int count=0,nh,nm;
	while((c=getchar())!=':')
		h+=c;
	while((c=getchar())!='\n')
		m+=c;
	nh=(h.front()-'0')*10+(h.back()-'0');
	nm=(m.front()-'0')*10+(m.back()-'0');
	if(nh>12){
		if(nm!=0){
			count=nh-11;
		}
		else{
			count=nh-12;
		}
	}
	else if(nh==12&&nm!=0) count=1;
	else{
		cout<<"Only "<<h<<':'<<m<<".  Too early to Dang.";
	}
	for(int i=0;i<count;i++){
		cout<<"Dang";
	}
	return 0;
}
