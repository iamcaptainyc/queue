#include <stdio.h>
#include <stdlib.h>
 
typedef struct L{
	int data;
	struct L *next; 
}L;

void initial(L *x);
void show(L *x);

int main()
{
	L *a,*b;
	a=(L *)malloc(sizeof(L));
	b=(L *)malloc(sizeof(L));
	initial(a);//这里不能直接传入未指向的指针，所以需要15，16行 
	getchar(); 
	initial(b);
	show(a);
	show(b);
	L *pb=b->next;
	L *pa=a->next;
	L *pc=a;
	while(pa!=NULL&&pb!=NULL)
	{
		if(pa->data<pb->data)
		{
			pc->next=pa;
			pc=pa;
			pa=pa->next;
		}
		else
		{
			pc->next=pb;
			pc=pb;
			pb=pb->next;
		}
	}
	pc->next=pa?pa:pb;
	free(b);
	b=NULL;
	show(a);//c的头节点为a的头节点 
	int i;
	for(i=0;a!=NULL;i++){
		b=a->next; //先保留next不然a释放后next就找不到了 
		free(a);
		a=b;
	}
	return 0;
 } 

void initial(L *x)
{
	int num;
	L *px=x;
	printf("please enter a data :\n");
	while(scanf("%d",&num)==1){
		px->next=(L *)malloc(sizeof(L));
		px=px->next;
		px->data=num;
		printf("enter next or empty line to stop:");
	}
	px->next=NULL;
}

void show(L *x)
{
	L *px=x->next;
	while(px!=NULL)
	{
		printf("%d ",px->data);
		px=px->next;
	}
	printf(".\n");
}
