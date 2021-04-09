#include <stdio.h>
#include <stdlib.h>
struct Link *AppendNode(struct Link *head);
void DispLink(struct Link *head);
void DeleteMemory(struct Link *head);
struct Link
{
	int data;
	struct Link *next;
};
int main()
{
	int i=0;
	char c;
	struct Link *head=NULL;
	printf("Do you want to append a new node?(Y/N)");
	scanf("%c",&c);
	while(c=='y'||c=='Y')
	{
		head=AppendNode(head);
		DispLink(head);
		printf("Do you want to append a new node?(Y/N)");
		scanf(" %c",&c);
		i++;
	}
	DeleteMemory(head);
	printf("%d nodes are appended!",i);
	return 0;
} 
struct Link *AppendNode(struct Link *head)
{
	struct Link *p=NULL;
	struct Link *pr=head;
	p=(struct Link *)malloc(sizeof(struct Link));
	if(p==NULL)
	{
		printf("No enough memory to alloc!");
		exit(0);
	}
	if(head==NULL)
	{
		head=p;
	}
	else
	{
		for(;pr->next!=NULL;)
		{
			pr=pr->next;
		}
		pr->next=p;
	}
	printf("input data:");
	scanf("%d",&p->data);
	p->next=NULL;
	return head;
}
void DispLink(struct Link *head)
{
	struct Link *pr=head;
	while(pr!=NULL)
	{
		printf("%d/t",pr->data);
		pr=pr->next;
	}
}
void DeleteMemory(struct Link *head)
{
	struct Link *pr=NULL,*p=head;
	while(p!=NULL)
	{
		pr=p;
		p=p->next;
		free(pr);	
	}
}
