#include <iostream>

using namespace std;

typedef struct{
	int weight;
	int parent,lchild,rchild;
}HTNode,*HaffmanTree;

void select(HaffmanTree &HT,int x,int &s1,int &s2)
{
	int min=1,i;
	for(i=1;i<=x;i++){
		if(HT[i].weight<HT[min].weight&&HT[i].parent==0) min=i;
	}
	min=1;
	s1=i;
	for(i=1;i<=x;i++){
		if((HT[i].weight<HT[min].weight&&HT[i].parent==0)&&i!=s1) min=i;
	}
	s2=i;
}

int createhaffmantree(HaffmanTree &HT,int n)
{
	if(n<=1) return 0;
	int m=2*n-1;
	HT=new HTNode[m+1];
	for(int i=1;i<=m;i++){
		HT[i].parent=0;
		HT[i].lchild=0;
		HT[i].rchild=0;
	}
	for(int i=1;i<=n;i++){
		cin>>HT[i].weight;
	}
	
	for(int i=n+1;i<=m;i++){
		int s1,s2;
		select(HT,i-1,s1,s2);
		HT[s1].parent=i,HT[s2].parent=i;
		HT[i].lchild=s1,HT[i].rchild=s2;
		
		HT[i].weight=HT[s1].weight+HT[s2].weight;
		
	}
}

void showhaffman(HaffmanTree &HT,int n)
{
	for(int i=n+1;i<2*n;i++){
		cout<<HT[i].parent<<' '<<HT[i].lchild<<' '<<HT[i].rchild<<' '<<HT[i].weight<<endl;
	}
}

int main()
{
	HaffmanTree HT;
	int n;
	cin>>n;
	
	createhaffmantree(HT,n);
	showhaffman(HT,n);
	
	return 0;
}
