#include <iostream>
#include <vector>

using namespace std;

void fun(int postroot,int instart,int length);

int find_self(int a,vector<int> b)
{
	for(int i=0;i<b.size();i++){
		if(b[i]==a) return i;
	}
	return -1;
}

vector<int> post;
vector<int> in;

int main()
{
	int n;
	cin>>n;

	for(int i=0;i<n;i++){
		int j;
		cin>>j;
		post.push_back(j);
	}
	for(int i=0;i<n;i++){
		int j;
		cin>>j;
		in.push_back(j);
	}
	cout<<"Preorder:";
	fun(post.size()-1,0,post.size());
	return 0;
}

void fun(int root,int instart,int length)//instart是中序序列中序列开始的位置 
{
	cout<<' '<<post[root];
	if(length==1) return;
	int inseq=find_self(post[root],in);
	if(inseq==-1) return;
	if(inseq!=instart) fun((root-1)-(length-(inseq-instart+1)),instart,inseq-instart);//第一个参数为根位置减一后减去右子树长度就是后序遍历中左子树跟的位置 
	if(inseq!=instart+length-1) fun(root-1,inseq+1,length-(inseq-instart+1));
}
/*
11
11 5 4 3 9 10 8 7 6 2 1
1 11 3 5 4 2 6 9 8 10 7
*/
