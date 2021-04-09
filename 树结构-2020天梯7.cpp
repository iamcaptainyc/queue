#include <iostream>

using namespace std;

typedef struct node{
	int data;
	node *rchild;
	node *lchild;
}tree,*tlink;

int n,m;

void create(int i,tlink &t);

int main()
{
	cin>>n>>m;
	tlink t;
	create(0,t);
	for(int i=0;i<m;i++){
		char str[n+1];
		cin>>str;
		tlink tt=t;
		for(int j=0;j<n;j++){
			if(str[j]=='y')
				tt=tt->lchild;
			else if(str[j]=='n')
				tt=tt->rchild;
		}
		cout<<tt->data<<'\n';
	}
}

int count=1;

void create(int i,tlink &t)
{
	if(i<=n){
		t=new tree;
		if(i==n) t->data=count++;
		create(i+1,t->lchild);
		create(i+1,t->rchild);
	}
	else t=NULL;
}
