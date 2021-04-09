#include <iostream>
#include <cstdlib>
#include <ctime>
#define overflow 1
#define ERROR 0
#define OK 1
#define LEN 11
#define QElemType int
typedef int Status;
#define MAX_SIZE 100
#define ADDSIZE 10 
using namespace std;

//栈实现 
typedef struct{
	int *base;
	int *top;
	int stacksize=MAX_SIZE;
}stack;

int ini(stack &k){
	k.base=(int *)calloc(MAX_SIZE,sizeof(int));
	if(!k.base) return 0;
	k.top=k.base;
	return 1;
}

int push(stack &k,int e)
{
	if(k.top-k.base>=k.stacksize){
		k.base=(int *)realloc(k.base,(k.stacksize+ADDSIZE)*sizeof(int));
		if(!k.base) return 0;
		return 1;
	}
	*k.top++=e;
	return 0;
}

int pop(stack &k,int &e){
	if(k.top==k.base){
		cout<<"no data"<<endl;
		return 0;
	}
	e=*--k.top;
	return e;
}

//队列实现 

typedef struct{
	QElemType *Base;
	int front;
	int rear;
}SqQueue;

QElemType GetHead(SqQueue Q);
Status DeQueue(SqQueue &Q,QElemType &e);
Status EnQueue(SqQueue &Q,QElemType e);
int QueueLength(SqQueue Q);
Status IniQueue(SqQueue &Q);
//主函数 
int main()
{
	SqQueue q;
	QElemType e;
	IniQueue(q);
	stack k;
	ini(k);
	srand((unsigned)time(NULL));
	while(1)
	{
		e=rand()%100+1;
		if(!EnQueue(q,e)) break;
	}
	while(q.front!=q.rear)
	{//输出元素至栈中 
		DeQueue(q,e);
		push(k,e);
		cout<<"dequeue: "<<e<<endl;
	}
	while(1){//倒置元素 
		pop(k,e);
		if(!EnQueue(q,e)) break;
	}
	while(q.front!=q.rear)
	{//输出倒置后的元素 
		DeQueue(q,e);
		cout<<"dequeue: "<<e<<endl;
	}
	return 0;
}

Status IniQueue(SqQueue &Q)
{
	Q.Base=new QElemType[LEN];
	if(!Q.Base) exit(overflow);
	Q.front=Q.rear=0;
	return OK;
}

int QueueLength(SqQueue Q)
{
	return (Q.rear-Q.front+LEN)%LEN;
}

Status EnQueue(SqQueue &Q,QElemType e)
{
	if((Q.rear+1)%LEN==Q.front)
		return ERROR;
	Q.Base[Q.rear]=e;
	Q.rear=(Q.rear+1)%LEN;
	return OK;
}

Status DeQueue(SqQueue &Q,QElemType &e)
{
	if(Q.rear==Q.front) return ERROR;
	e=Q.Base[Q.front];
	Q.front=(Q.front+1)%LEN;
	return OK;
}

QElemType GetHead(SqQueue Q)
{
	if(Q.front!=Q.rear)
		return Q.Base[Q.front];
}

