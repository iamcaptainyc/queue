#include <iostream>
#include <vector>
#define LEN 100
using namespace std;

int c[LEN];
int count=0;
int w,n;

typedef struct{
	int v;
	int p;
}pack;

int fun(int sum,vector<pack> &v,int k,int price);

int main()
{	
	int max=0;
	cin>>n>>w;
	vector<pack> pa(n);
	for(auto i=pa.begin();i!=pa.end();i++){
		cin>>i->v;
	}
	for(auto i=pa.begin();i!=pa.end();i++){
		cin>>i->p;
	}
	fun(0,pa,0,0);
	for(int i=0;i<count;i++){
		if(c[i]>max) max=c[i];
	}
	cout<<max<<'\n';
 } 
 
int fun(int sum,vector<pack> &v,int k,int price)
{
	if(sum>w) return 0;
	else if(sum<=w){
		c[count++]=price;
	}
	for(int i=k;i<n;i++){
		fun(sum+v[i].v,v,i+1,price+v[i].p);
	}
	return 0;
}


/*another version;
#include <iostream>
#define LEN 100

using namespace std;

typedef struct{
	int v;
	int p;
}pack;

int n,w;
int c[LEN];
int count;

void fun(int sum,int price,int loc,pack pa[]);

int main()
{
	cin>>n>>w;
	pack pa[n];
	for(int i=0;i<n;i++){
		cin>>pa[i].v;
	}
	for(int i=0;i<n;i++){
		cin>>pa[i].p;
	}
	fun(0,0,0,pa);
	int max=0;
	for(int i=0;i<count;i++){
		if(c[i]>max) max=c[i];
	}
	cout<<max;
}

void fun(int sum,int price,int loc,pack pa[])
{
	if(sum>w) return;
	else if(sum<=w){
		c[count++]=price;
	}
	for(int i=loc;i<n;i++){
		fun(sum+pa[i].v,price+pa[i].p,i+1,pa);
	}
	return;
}*/
