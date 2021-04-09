#include <iostream>
#define MAXINT 501

using namespace std;

typedef struct{
	int price;
	int length;
}rode;

int n,m,s,d;

int djstl_algo(rode *d,int start);

rode G[MAXINT][MAXINT];

int main()
{
	
	cin>>n>>m>>s>>d;
	
	rode D[n];
	
	for(int i=0;i<n;i++){//将邻接矩阵初始化 
		for(int j=0;j<n;j++){
			G[i][j].length=MAXINT;
			G[i][j].price=MAXINT;
		}
	} 
	
	for(int i=0;i<m;i++){//输入数据 
		int start,end;
		cin>>start>>end;
		cin>>G[start][end].length>>G[start][end].price;
		G[end][start].length=G[start][end].length;
		G[end][start].price=G[start][end].price;
	}
	djstl_algo(D,s);
	cout<<D[d].length<<' '<<D[d].price;
	return 0;
 }
 
int djstl_algo(rode *d,int start)
{
	bool s[MAXINT];
	
	for(int i=0;i<n;i++){
		d[i].length=G[i][start].length;
		d[i].price=G[i][start].price;
		s[i]=false;
	}
	d[start].length=0;
	d[start].price=0;
	s[start]=true;
	
	for(int i=1;i<n;i++){
		int min=MAXINT;
		int v;
		for(int j=0;j<n;j++){
			if(!s[j]&&d[j].length<min){
				min=d[j].length;
				v=j;
			}
		}
		s[v]=true;
		for(int j=0;j<n;j++){
			if(!s[j]&&d[v].length+G[v][j].length<d[j].length){
				d[j].length=d[v].length+G[v][j].length;
				d[j].price=d[v].price+G[v][j].price;
			}
			else if(!s[j]&&d[v].length+G[v][j].length==d[j].length)
				if(d[v].price+G[v][j].price<d[j].price)
					d[j].price=d[v].price+G[v][j].price;
		}
	}
}
