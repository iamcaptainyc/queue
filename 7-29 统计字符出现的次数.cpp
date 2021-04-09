#include <iostream>
#include <string>
#define LEN 100
using namespace std;

typedef struct {
	char ch;
	int n=0;
}CH;

int main()
{
	string str;
	while(getline(cin,str)){
		CH c[LEN];
		for(int i=0,j=65;i<52&&j<=122;i++,j++){
			c[i].ch=j;
			if(j==90) j=96;
		}
		
		for(auto i=str.begin();i!=str.end();i++){
			if(*i==' ') continue;
			for(int j=0;j<52;j++){
				if(c[j].ch==*i){
					c[j].n++;
					break;
				}
			}
		}
		int count=0;
		for(int j=0;j<52;j++){
			if(c[j].n!=0){
				if(count%10==0&&count!=0) cout<<endl;
				else if(count!=0) cout<<' ';
				cout<<c[j].ch<<"--"<<c[j].n;
				count++;	
			}
		}
		cout<<endl;
	} 
	return 0;
 } 
