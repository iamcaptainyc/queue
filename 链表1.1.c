#include <stdio.h>
#include <stdlib.h>

typedef struct node{
	int x;
	struct node *next;
}node;

node h,*t=NULL,*tail=NULL;

void start()
{
	h.next=NULL;
	tail=&h;
	int x,i;
	for(i=0;i<4;i++)
	{
		scanf("%d",&x);
		t=(node *)malloc(sizeof(node));
		t->next=NULL;
		t->x=x;
		tail->next=t;
		tail=t;
	}
}

int insert(int y)
{
	t=&h;
	while(t->next!=NULL){
		if(y<=t->next->x){
			tail=t;
			t=(node *)malloc(sizeof(node));
			t->x=y;
			t->next=tail->next;
			tail->next=t;
			return 0;
		}
		else{
			t=t->next;
		}
	}
	t->next=(node *)malloc(sizeof(node));
	t->next->next=NULL;
	t->next->x=y;
	return 0;
}

int main()
{
	int y;
	start();
	scanf("%d",&y);
	insert(y);
	t=h.next;
	while(t!=NULL){
		printf("%d ",t->x);
		t=t->next;
	}
	return 0;
}
