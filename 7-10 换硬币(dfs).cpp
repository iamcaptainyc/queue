#include <iostream>
using namespace std;
int calcu(int k,int x,int sum);

int n[3]={1,2,5};
int c[3]={1,1,1};
int count;
int main()
{
	int x;
	cin>>x;
	calcu(2,x,n[0]+n[1]+n[2]);
	cout<<"count = "<<count;
	return 0;
}

int calcu(int k,int x,int sum)
{
	int i;
	if(sum==x){
		cout<<"fen5:"<<c[2]<<", "<<"fen2:"<<c[1]<<", "<<"fen1:"<<c[0]<<", ";
		cout<<"total:"<<c[2]+c[1]+c[0]<<'\n';
		count++;
		return 0;
	}
	if(k<0) return 0;
	for(i=(x-sum)/n[k],c[k]=1;i>=0;i--)
	{
		c[k]=i+1;
		calcu(k-1,x,sum+n[k]*i);
	}
	c[k]=1;
	return 1;
}
