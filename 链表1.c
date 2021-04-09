#include <stdio.h>
#include <stdlib.h>

typedef struct NODE{
	int x;
	struct NODE *next;
}NODE;

NODE h,*t=NULL,*tail=NULL;

void start()
{
	h.next=NULL;
	tail=&h;
	int x,i;
	for(i=0;i<4;i++)
	{
		scanf("%d",&x);
		t=(NODE *)malloc(sizeof(NODE));
		t->x=x;
		t->next=NULL;
		tail->next=t;
		tail=t;
	}
}

int insert(int y)
{
	t=&h;
	int flag=1;
	while(t->next!=NULL){
		if(y<=t->next->x){
			tail=t;
			t=(NODE *)malloc(sizeof(NODE));
			t->next=tail->next;
			tail->next=t;
			t->x=y;
			flag=0;
			return 0;
		}
		else{
			t=t->next;
		}
	}
	if(flag){
		t=tail;
		t=(NODE *)malloc(sizeof(NODE));
		tail->next=t;
		t->next=NULL;
		t->x=y;
	}
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
