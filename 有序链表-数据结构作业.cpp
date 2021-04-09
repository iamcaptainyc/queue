#include<stdio.h>  
#include<stdlib.h>   
#define TRUE 1 
#define FALSE 0 
#define OK 1 
#define ERROR 0 
#define INSEASIBLE -1 
#define OVERFLOW -2 
typedef int Status; 
typedef int ElemType; 
 



typedef struct LNode{
	ElemType data;
	struct LNode *next;
}LNode,*LinkList;

int Length_L(LinkList L)
{
	int count=0;
	L=L->next;
	while(L!=NULL){
		count++;
		L=L->next;
	}
	return count;
}

void CreateList_L(LinkList &L,int n) 
{
	L=(LinkList)malloc(sizeof(LNode));   
	L->next=NULL;   
	for(int i=1;i<=n;i++)   
	{          
		printf("请输入第%d个值:\n",i);     
		LinkList p=(LinkList)malloc(sizeof(LNode));          
		scanf("%d",&p->data);     
		p->next=L->next;   
		L->next=p;   
	}  
} 
 
void ListDisp_L(LinkList L)
{         
	printf("\n当前链表中的数据是:\n");     
	LinkList p=L->next;  
	int i=1;  
	while(p)   
	{      
		printf("单链表第%d个数是%d\n",i,p->data);   
		p=p->next; i++;   
	}      
	printf("单链表数据显示完毕!\n"); 
} 
 
Status GetELem_L(LinkList L,int i,ElemType &e)
{
	int j=0;
	L=L->next;
	while(j++!=i-1&&L->next!=NULL){
		L=L->next;
	}
	e=L->data;
	return e;
}

Status ListInsert_L(LinkList &L,int i,ElemType e)
{
	LinkList p,pa;
	p=L;
	int j=0;
	if(p->next==NULL){
		;
	}
	else p=p->next;
	while(j++!=i-2&&i-2>=0&&p->next!=NULL){
		p=p->next;
	}
	pa=(LinkList)malloc(sizeof(LNode));
	pa->data=e;
	pa->next=p->next;
	p->next=pa;
	return OK;
}

Status ListDelete_L(LinkList &L,int i,ElemType &e)
{
	LinkList p,pd;
	int j=0;
	p=L->next;
	if(i>Length_L(L)) {
		return e=0;
	}
	while(j++!=i-2&&i-2>=0){
		p=p->next;
	}
	pd=p->next;
	p->next=p->next->next;
	e=pd->data;
	free(pd);
	return e;
}

void MergeList_L(LinkList La,LinkList Lb,LinkList &Lc)
{
	LinkList pa,pb,pc;
	pb=Lb->next;
	pa=La->next;
	pc=La;
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
	free(Lb);
	Lc=La;
}

int had(LinkList px,LinkList pc,LinkList p)
{
	p=p->next;
	while(p<=pc){
		if(px->data==p->data)
			return 1;
		p=p->next;
	}
	return 0;
}

void Union_L(LinkList A,LinkList B,LinkList &C)
{
	LinkList pa,pb,pc,p;
	pa=A->next;
	pb=B->next;
	C=A;
	pc=C;
	while(pa!=NULL&&pb!=NULL){
		if(pa->data<=pb->data){
			if(had(pa,pc,C)){
				p=pa;
				pa=pa->next;
				free(p);
			}
			else{
				pc->next=pa;
				pc=pa;
				pa=pa->next;
			}
		}
		else{
			if(had(pb,pc,C)){
				p=pb;
				pb=pb->next;
				free(p);
			}
			else{
				pc->next=pb;
				pc=pb;
				pb=pb->next;
			}
		}
	}
	p=pa?pa:pb;
	free(B);
	while(p!=NULL){
		if(had(p,pc,C))
			pa=p->next;
		else{
			pc->next=p;
			pc=p;
			p=p->next;
		}
	}
}

int main()
{     
	LinkList L;  
	int n;  
	printf("即将初始化单链表请输入元素个数:\n");  
	scanf("%d",&n);
	CreateList_L(L,n);
 	ListDisp_L(L);
 	int i=3;
 	ElemType e;
 	GetELem_L(L,i,e);
 	printf("GetELem_L函数输出结果：%d\n",e);
 	//插入函数
 	i=4;
 	ListDisp_L(L);
 	e=209;
	ListInsert_L(L,i,e);
 	printf("ListInsert_L函数插入%d:\n",e);
	ListDisp_L(L);
	//删除函数
	i=5;
	ListDelete_L(L,i,e);
	if(e)
		printf("删除第%d个位置，数据为%d :",i,e);
	else
		printf("所指位置没有数据！");
	ListDisp_L(L);
	//获得长度 
	printf("元素个数为%d\n",Length_L(L));
	//合并有序链表
	LinkList La,Lb,Lc;
	La=(LinkList)malloc(sizeof(LNode));
	Lb=(LinkList)malloc(sizeof(LNode));
	La->next=NULL,Lb->next=NULL;
	ListInsert_L(La,1,3);
	ListInsert_L(La,2,6);
	ListInsert_L(La,3,34);
	ListInsert_L(La,4,57);
	ListInsert_L(Lb,1,3);
	ListInsert_L(Lb,2,6);
	ListInsert_L(Lb,3,12);
	ListInsert_L(Lb,4,25);
	ListInsert_L(Lb,5,76);
	printf("La:\n");
	ListDisp_L(La);
	printf("Lb:\n");
	ListDisp_L(Lb);
	//MergeList_L(La,Lb,Lc);     //因为 MergeList_L与 Union_L 两函数操作的是同一数据，所以不能同时执行，每次只能执行其中一个函数 
	Union_L(La,Lb,Lc);
	printf("Lc:\n");
	ListDisp_L(Lc);
	return 0; 
 }
