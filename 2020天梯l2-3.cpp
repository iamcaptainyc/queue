#include <iostream>
#include <cmath>
#define LEN 30

using namespace std;

int tree[LEN];


typedef struct node{
	int vex;
	node *nextvex;
}qnode,*qlink;

typedef struct{
	qlink front;
	qlink rear;
}queue;

void iniqueue(queue &q)
{
	q.front=new qnode;
	q.rear=q.front;
	q.rear->nextvex=NULL;
}

void enqueue(queue &q,int v)
{
	qlink p=new qnode;
	p->vex=v;
	q.rear->nextvex=p;
	q.rear=p;
	q.rear->nextvex=NULL;
}

void dequeue(queue &q,int &v)
{
	qlink p=q.front->nextvex;
	v=p->vex;
	q.front->nextvex=p->nextvex;
	if(q.rear==p){
		q.rear=q.front;
	}
	delete p;
}

bool empty(queue q)
{
	if(q.front==q.rear) return true;
	else return false;
}


void fun(int root,int num);

int main()
{
	int n;
	cin>>n;
	for(int l=0;l<n;l++){
		cin>>tree[l];
	}
	fun(n-1,n);
}

int mul(int x,int i)
{
	int sum=0;
	for(int j=0;j<=i;j++){
		sum+=pow(x,j);
	}
	return sum;
}

void fun(int root,int num)
{
	queue q;
	queue nums;
	iniqueue(nums);
	iniqueue(q);
	enqueue(q,root);
	enqueue(nums,num);
	cout<<tree[root];
	
	while(!empty(q)&&!empty(nums)){
		int temp,tnum;
		int lroot,rroot;
		dequeue(q,temp);
		dequeue(nums,tnum);
		if(tnum==1) continue;
		
		int t=tnum,i;
		for(i=0;t!=1;i++){
			t=t/2;
		}
		int x=tnum-mul(2,i-1);
		int differ=pow(2,i);
		int base=mul(2,i-1)/2;
		
		if(x>differ/2){
			lroot=temp-(x-differ/2+base)-1;
			rroot=temp-1;
			if(base+differ/2>=1){
				enqueue(nums,base+differ/2);
				enqueue(q,lroot);
				cout<<' '<<tree[lroot];
			}
			if(x-differ/2+base>=1){
				enqueue(nums,x-differ/2+base);
				enqueue(q,rroot);
				cout<<' '<<tree[rroot];
			}
		}
		else{
			lroot=temp-base-1;
			rroot=temp-1;
			if(base+x>=1){
				enqueue(nums,base+x);
				enqueue(q,lroot);
				cout<<' '<<tree[lroot];
			}
			if(base>=1){
				enqueue(nums,base);
				enqueue(q,rroot);
				cout<<' '<<tree[rroot];
			}
		}
	}
}
