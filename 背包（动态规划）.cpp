#include <iostream>
#define LEN 10

using namespace std;

typedef struct{
	int p;
	int v;
}pack;

int dtgh[LEN][LEN];

int find(int i,int j)
{
	if(i<0) i=0;
	if(j<0) j=0;
	return dtgh[i][j];
}

int func(pack pa[],int n,int w)
{
	for(int i=1;i<=n;i++){
		for(int j=1;j<=w;j++){
			if(j>=pa[i-1].v){
				int a,b;
				a=find(i-1,j);
				b=find(i-1,j-pa[i-1].v)+pa[i-1].p;
				dtgh[i][j]=a>b?a:b;
			}
			else{
				dtgh[i][j]=find(i-1,j);
			}
		}
	}
}

int main()
{
	int n,w;
	cin>>n>>w;
	pack pa[n];
	for(int i=0;i<n;i++){
		cin>>pa[i].v;
	}
	for(int i=0;i<n;i++){
		cin>>pa[i].p;
	}
	func(pa,n,w);
	int max=dtgh[0][0];
	for(int i=0;i<LEN;i++){
		for(int j=0;j<LEN;j++){
			if(dtgh[i][j]>max) max=dtgh[i][j];
		}
	}
	 
	cout<<max<<'\n';
	return 0;
}


