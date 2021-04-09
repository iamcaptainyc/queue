#include <iostream>
#include <vector>
using namespace std;

typedef struct{
	int asay,bsay,aact,bact;
}round; 

int main()
{
	int na,nb,n,acount=0,bcount=0;
	cin>>na>>nb;
	cin>>n;
	vector<round> r(n);
	for(int i=0;i<n;i++)
		cin>>r[i].asay>>r[i].aact>>r[i].bsay>>r[i].bact;
	for(auto i:r){
		int sum=i.asay+i.bsay;
		if(i.aact==sum&&i.bact==sum) continue;
		else{
			if(i.aact==sum){
			acount++;
			if(acount>na){
				cout<<'A'<<endl<<bcount;
				return 0;
			}
		}
			if(i.bact==sum){
				bcount++;
				if(bcount>nb){
					cout<<'B'<<endl<<acount;
					return 0;
			}
		}
		}
	}
	return 0;
}
