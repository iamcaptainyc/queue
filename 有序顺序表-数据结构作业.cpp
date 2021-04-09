#include<stdio.h>  //printf ��������� scanf ���뺯������ͷ�ļ� 
#include<stdlib.h>  //exit ������malloc ������realloc �������ڵ�ͷ�ļ�    //��#define ����������ų����ͺ������״̬����  
#define TRUE 1 
#define FALSE 0 
#define OK 1 
#define ERROR 0 
#define INSEASIBLE -1 
#define OVERFLOW -2 

#define LIST_INIT_SIZE 20 //˳���洢�ռ�ĳ�ʼ������ 
#define LISTINCREMENT 10   //˳���洢�ռ�ķ������� 
 
//�� typedef �����������  
typedef int Status;   //Status �Ǻ��������ͣ���ֵ�Ǻ������״̬���� 
typedef int  ElemType; //������˳����д洢 int ������ 

typedef struct{    
	ElemType *elem;    
	int length;    
	int listsize; 
}SqList; 

Status InitList_Sq(SqList &L) {      
	L.elem=(ElemType *)malloc(LIST_INIT_SIZE*sizeof(ElemType));   
	if(!L.elem) exit(OVERFLOW);   
	L.length=0;   
	L.listsize=LIST_INIT_SIZE;   
	return OK; 
} 

//��˳�����Ա� L �е� i ��λ��֮ǰ�����µ�Ԫ�� e 
Status ListInsert_Sq(SqList &L,int i,ElemType e) 
{   
	//�жϲ���λ�� i �Ƿ�Ϸ�     
	if(i<1||i>L.length+1) return ERROR;  
	//�жϵ�ǰ�洢�ռ��Ƿ�������������������ӷ���   
	if(L.length>=L.listsize)   {      
		ElemType *newbase=(ElemType *)realloc(L.elem,(L.listsize+LISTINCREMENT)*sizeof(ElemType));         
		if(!newbase) exit(OVERFLOW);   
		L.elem=newbase;   
		L.listsize+=LISTINCREMENT;  
	}  
	ElemType *p,*q;  q=&(L.elem[i-1]);  
	for(p=&(L.elem[L.length-1]);p>=q;--p) *(p+1)=*p;  
	*q=e;  
	++L.length;  
	return OK; 
}

//˳�����ʾ��������˳��� L ����ÿ��Ԫ�������ʾ���� 
void ListDisp_Sq(SqList L) {    
	int i;     
	printf("\n ��ǰ���Ա��е������ǣ�\n");     
	for(i=0;i<L.length;i++)   
	{      
		printf("���Ա�ĵ�%d ������%d\n",i+1,L.elem[i]);   
	}      
	printf("���Ա�������ʾ��ϣ�\n"); 
}

int ListDelete_sq(SqList &L,int i,ElemType &e)
{
	ElemType *p,*q;
	p=&L.elem[i-1];
	e=*p;
	for(q=&L.elem[L.length-1];p<=q;p++)
	{
		*(p)=*(p+1);
	}
	L.length--;
	return e;
}

int LocateElem_Sq(SqList L,ElemType e)
{
	for(int i=0;i<=L.length;i++)
	{
		if(L.elem[i]==e)
		{
			return i+1;
		}
	}
	return 0;
}

void MergeList_Sq(SqList La,SqList Lb,SqList &Lc)
{
	Lc.length=La.length+Lb.length;
	ElemType *pa,*pb,*pc,*pa_last,*pb_last;
	pc=Lc.elem,pa=La.elem,pb=Lb.elem;
	pa_last=&La.elem[La.length-1];
	pb_last=&Lb.elem[Lb.length-1];
	while(pa<=pa_last&&pb<=pb_last)
	{
		if(*pa<*pb) *pc++=*pa++;
		else *pc++=*pb++;
	}
	while(pa<=pa_last) 
		*pc++=*pa++;
	while(pb<=pb_last) 
		*pc++=*pb++;
}

Status GetElem(SqList L,int i,ElemType &e)
{
	e=L.elem[i-1];
}

Status ListLength_Sq(SqList L)
{
	return L.length;
}

int had(ElemType *px,ElemType *pc,SqList C)
{
	ElemType *p=C.elem;
	while(p<pc){
		if(*px==*p)
			return 1;
		p++;
	}
	return 0;
}

void Union_Sq(SqList A,SqList B,SqList &C)
{
	ElemType *p,*pa,*pb,*pc,*pa_last,*pb_last;
	pa=A.elem,pb=B.elem,pc=C.elem;
	pa_last=&A.elem[A.length-1],pb_last=&B.elem[B.length-1];
	while(pa<=pa_last&&pb<=pb_last)
	{
		if(*pa<=*pb){
			if(had(pa,pc,C)){
				pa++;
			}
			else
			{
				*pc++=*pa++;
				C.length++;	
			}
		
		}
		else{
			if(had(pb,pc,C)){
				pb++;
			}
			else
			{
				*pc++=*pb++;
				C.length++;	
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
			C.length++;
		}
	}
}



int main() 
{    
	SqList L; //����˳��� L  
	InitList_Sq(L);//���ú���������ձ�  
	ListInsert_Sq(L,1,36);//���ú������� L ���в�������  
	ListInsert_Sq(L,2,18);  
	ListInsert_Sq(L,3,57);  
	ListInsert_Sq(L,4,22);  
	ListInsert_Sq(L,5,49);
	ListInsert_Sq(L,6,23);
	ListDisp_Sq(L);//���ú�������ʾ���Ա�
	//ɾ������ 
	int e,o;
	ListDelete_sq(L,1,e);
	printf("ɾ���������ؽ����%d\n",e); 
	ListDisp_Sq(L);
	//��λ����
	printf("��λ����,%d��λ��Ϊ��%d\n",e,LocateElem_Sq(L,e));
	//���ָ��λ�õ�ֵ
	o=4;
	GetElem(L,o,e);
	printf("��ú�����%dλ��ֵΪ��%d\n",o,e);
	//���Ԫ�ظ���
	printf("Ԫ�ظ���%d\n",ListLength_Sq(L));
	//�ϲ�La��Lb,�õ�Lc
	SqList La,Lb,Lc,Ld;
	InitList_Sq(La);
	InitList_Sq(Lb);
	InitList_Sq(Lc);
	InitList_Sq(Ld);
	//��La����
	ListInsert_Sq(La,1,3);  
	ListInsert_Sq(La,2,5);  
	ListInsert_Sq(La,3,7);  
	ListInsert_Sq(La,4,13); 
	//��Lb���� 
	ListInsert_Sq(Lb,1,3);  
	ListInsert_Sq(Lb,2,7);  
	ListInsert_Sq(Lb,3,9);  
	ListInsert_Sq(Lb,4,12);  
	ListInsert_Sq(Lb,5,41);
	ListInsert_Sq(Lb,6,64);
	MergeList_Sq(La,Lb,Lc);
	printf("La:");
	ListDisp_Sq(La);
	printf("Lb:");
	ListDisp_Sq(Lb);
	printf("Lc:");
	ListDisp_Sq(Lc);
	//ȡLa��Lb�Ĳ�����Ld
	Union_Sq(La,Lb,Ld);
	printf("La:");
	ListDisp_Sq(La);
	printf("Lb:");
	ListDisp_Sq(Lb);
	printf("Ld:");
	ListDisp_Sq(Ld);
} 
 
