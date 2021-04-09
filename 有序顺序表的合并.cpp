#include <stdio.h>
#include <stdlib.h>

#define TURE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INSEASIBLE -1
#define OVERFLOW -2
#define LIST_INIT_SIZE 5
#define LISTINCREMENT 10

typedef struct{
	
}; 
int main()
{
	
 } 

int ListDelete_sq(SqList &L,int i,ElemType &e)
{
	ElemType *p,*q;
	p=&L.elem[i];
	e=*p;
	for(q=L.elem[L.length-1];p<=q;p++)
	{
		*(p)=*(p+1);
	}
	return e;
}

int LocateElem_Sq(SqList L,ElemType e)
{
	for(int i=0;i<=L.length;i++)
	{
		if(L.elem[i]==e)
		{
			return i;
		}
	}
	return 0;
}

void MergeList_Sq(SqList La,SqList Lb,SqList &Lc)
{
	Lc.length=La.length+Lb.length;
	ElemType *pa,*pb,*pc,*pa_last,*pb_last;
	pc=Lc.elem,pa=La.elem,pb=Lb.elem;
	pa_last=La.elem[La.length-1];
	pb_last=Lb.elem[Lb.length-1];
	while(pa<=pa_last&&pb<=pb_last)
	{
		if(*pa>*pb) *pc++=*pa++;
		else *pc++=*pb++;
	}
	while(pa<pa_last) *pc++=*pa++;
	while(pb<pb_last) *pc++=*pb++;
}

Status GetElem(SqList L,int i,ElemType &e)
{
	e=L.elem[i];
}

Status ListLength_Sq(SqList L)
{
	return L.length;
}

void Union_Sq(SqList A,SqList B,SqList &c)
{
	ElemType *pa,*pb,*pc;
	pa=A.elem,pb=B.elem,pc=C.elem;
	pa_last=A.elem[A.length],pb_last=B.elem[B.length];
	while(pa<=pa_last&&pb<=pb_last)
	{
		if(*pa<=*pb){
			if(had(pa,pc,C)){
				pa++;
			}
			else
			{
				*pc++=*pa++;	
			}
		
		}
		else{
			if(had(pb,pc,C)){
				pb++;
			}
			else
			{
				*pc++=*pb++;	
			}
		}
	}
	if(A.length>B.length)
		p=pa;
	else
		p=pb;
	while(p<=pa_last||p<=pb_last){
		if(had(p,pc,C)){
			p++;
		}
		else{
			*pc++=*p++;
		}
	}
}

int had(ElemType *px,ElemType *pc,SqList C)
{
	ElemType *p=C.elem;
	while(p<pc){
		if(*pa==*p)
			return 1;
		p++;
	}
	return 0;
}
