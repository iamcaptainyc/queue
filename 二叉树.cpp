#include <iostream>

using namespace std;

typedef struct node{
	int data;
	struct node *lchild,*rchild;
}tree,*treelink;

void CreatTree(treelink &t)
{
	treelink p;
	int data;
	cin>>data;
	if(cin.fail()){
		t=NULL;
		cin.clear();
		//cin.sync();
		cin.get();
	}
	else{
		t=new tree;
		t->data=data;
		cout<<"lchild :";
		CreatTree(t->lchild);
		cout<<"rchild :";
		CreatTree(t->rchild);
	}
}

void beforeTraverse(treelink &t)
{
	if(t){
		cout<<t->data;
		beforeTraverse(t->lchild);
		beforeTraverse(t->rchild);
	}
}

void midTraverse(treelink &t)
{
	if(t){
		midTraverse(t->lchild);
		cout<<t->data;
		midTraverse(t->rchild);
	}
}

void afterTraverse(treelink &t)
{
	if(t){
		afterTraverse(t->lchild);
		afterTraverse(t->rchild);
		cout<<t->data;
	}
}

int allcount;

int allpoint(treelink &t)
{
	if(t){
		return allpoint(t->lchild)+allpoint(t->rchild)+1;
	}
	return 0;
}

int leafcount;

int leaf(treelink &t)
{
	if(t){
		leaf(t->lchild);
		leaf(t->rchild);
		if(t->lchild==NULL&&t->rchild==NULL)
			leafcount++;
	}
}

int depth(treelink &t)
{
	int n,m;
	if(t){
		m=depth(t->lchild);
		n=depth(t->rchild);
		if(m>n) return (m+1);
		else return (n+1);
	}
	return 0;
}

int main()
{
	treelink t;
	cout<<"创建新树，输入q来创建空树\n";
	CreatTree(t);
	cout<<"Before :"<<endl;
	beforeTraverse(t);
	cout<<endl<<"Mid :"<<endl;
	midTraverse(t);
	cout<<endl<<"After :"<<endl;
	afterTraverse(t);
	
	cout<<endl<<"结点总数："<<allpoint(t)<<endl;
	leaf(t);
	cout<<"叶子总数："<<leafcount<<endl;
	cout<<"深度："<<depth(t)<<endl;
 } 
