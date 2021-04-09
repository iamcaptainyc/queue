#include <iostream>
#include <fstream>
#include <string>
using namespace std;

typedef struct node{
	string data;
	struct node *next;
}qnode,*qlink;

typedef struct{
	qlink front;
	qlink rear;
}queue;

int ini(queue &q)
{
	q.front=new qnode;
	q.rear=q.front;
	q.front->next=NULL;
}

int enqueue(queue &q,string e)
{
	qlink p;
	p=new qnode;
	p->data=e;
	p->next=NULL;
	q.rear->next=p;
	q.rear=p;
	return 1;
}

int dequeue(queue &q,string &e)
{
	qlink p;
	if(q.front==q.rear) return 0;
	p=q.front->next;
	e=p->data;
	q.front->next=p->next;
	if(q.rear==p){
		q.rear=q.front;
	}
	delete p;
	return 1;
}

int empty(queue &q)
{
	if(q.front==q.rear) return 1;
	return 0;
}

string getop(queue &q,string &e)
{
	if(empty(q)) return 0;
	e=q.front->next->data;
	return e;
}

int main()
{
	queue maq;
	queue feq;
	ini(maq);
	ini(feq);
	string male,female,e;
	fstream fmale;
	fstream ffemale;
	fmale.open("male.txt",ios_base::in);
	ffemale.open("female.txt",ios_base::in);
	while(getline(fmale,male)){
		enqueue(maq,male);
	}
	while(getline(ffemale,female)){
		enqueue(feq,female);
	}
	while(dequeue(maq,male)&&dequeue(feq,female)){
		cout<<"请"<<female<<"女士与"<<male<<"男士进场跳舞。"<<"\n"; 
	}
	if(empty(maq)&&empty(feq)){
		cout<<"正在等待......"<<endl;
	}
	else if(empty(feq)){
		cout<<getop(maq,e)<<"男士正在场外等待......"<<endl;
	}
	else{
		cout<<getop(feq,e)<<"女士正在场外等待......"<<endl;
	}
	fmale.close();
	ffemale.close();
	return 0;
}
