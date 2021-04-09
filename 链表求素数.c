#include<stdio.h>
#include<stdlib.h>
#include<math.h>

struct node
{
  int x;
  struct node *next;
};

int isprimer(int x)
 {
 	int i,k;
 	k=sqrt((double)x);
 	if(x==1) return 0;
 	for(i=2;i<=k;i++)
 	{
 		if(x%i==0) return 0; 
	 }
	return 1;
 }

int func(struct node *H)

{
	int a=0,b=0,i;
	struct node *t;
	t=H->next;
	for(i=0;t!=0;i++)
	{
		if(isprimer(t->x)) a+=t->x;
		if(t->x%2==0) b+=t->x;
		t=t->next;
	}
	return a-b;
}

void insert_head(struct node *H,int p)
{
  struct node *t;
  t=(struct node*)malloc(sizeof(struct node));
  t->x=p;
  t->next=H->next;
  H->next=t;
}

int main()
{
  struct node H;
  int x;
  int i;

  H.next=0;

  for(i=1;i<=5;i++)
  {
   scanf("%d",&x); 
   insert_head(&H,x) ; 
  } 
  printf("%d\n",func(&H));
 }
 

