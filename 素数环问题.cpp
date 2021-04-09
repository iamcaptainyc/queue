#include <iostream>
#include <cmath>
#define LEN 12

using namespace std;

int c[LEN]={1};

int fun(int x,int count);

bool judge(int x)
{
	int k=sqrt(x);
	
	for(int i=2;i<=k;i++){
		if(x%i==0) return 0;
	}
	
	return 1;
}

bool issame(int x,int count)
{
	for(int i=0;i<count;i++){
		if(c[i]==x) return 0;
	}
	return 1;
}

int n;

int main()
{
	
	while(cin>>n){
		fun(1,1);
	}
	return 0;
}




int fun(int before,int loc)
{
	if(loc>=n){
		for(int j=0;c[j]!=0;j++)
			cout<<c[j];
		cout<<'\n';
		return 0;
	}
	
	for(int i=2;i<=n;i++){
		if(issame(i,loc)&&judge(before+i)){
			c[loc]=i;
			fun(i,loc+1);
		}
	}
}
