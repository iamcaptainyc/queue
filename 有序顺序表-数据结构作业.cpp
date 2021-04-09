#include<stdio.h>  //printf 输出函数和 scanf 输入函数所在头文件 
#include<stdlib.h>  //exit 函数、malloc 函数、realloc 函数所在的头文件    //用#define 宏来定义符号常量和函数结果状态代码  
#define TRUE 1 
#define FALSE 0 
#define OK 1 
#define ERROR 0 
#define INSEASIBLE -1 
#define OVERFLOW -2 

#define LIST_INIT_SIZE 20 //顺序表存储空间的初始分配量 
#define LISTINCREMENT 10   //顺序表存储空间的分配增量 
 
//用 typedef 给类型起别名  
typedef int Status;   //Status 是函数的类型，其值是函数结果状态代码 
typedef int  ElemType; //本例中顺序表中存储 int 型数据 

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

//在顺序线性表 L 中第 i 个位置之前插入新的元素 e 
Status ListInsert_Sq(SqList &L,int i,ElemType e) 
{   
	//判断插入位置 i 是否合法     
	if(i<1||i>L.length+1) return ERROR;  
	//判断当前存储空间是否已满，如果已满，增加分配   
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

//顺序表显示函数，将顺序表 L 表中每个元素逐个显示出来 
void ListDisp_Sq(SqList L) {    
	int i;     
	printf("\n 当前线性表中的数据是：\n");     
	for(i=0;i<L.length;i++)   
	{      
		printf("线性表的第%d 个数是%d\n",i+1,L.elem[i]);   
	}      
	printf("线性表数据显示完毕！\n"); 
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
	SqList L; //定义顺序表 L  
	InitList_Sq(L);//调用函数，构造空表  
	ListInsert_Sq(L,1,36);//调用函数，向 L 表中插入数据  
	ListInsert_Sq(L,2,18);  
	ListInsert_Sq(L,3,57);  
	ListInsert_Sq(L,4,22);  
	ListInsert_Sq(L,5,49);
	ListInsert_Sq(L,6,23);
	ListDisp_Sq(L);//调用函数，显示线性表
	//删除操作 
	int e,o;
	ListDelete_sq(L,1,e);
	printf("删除函数返回结果：%d\n",e); 
	ListDisp_Sq(L);
	//定位函数
	printf("定位函数,%d的位置为：%d\n",e,LocateElem_Sq(L,e));
	//获得指定位置的值
	o=4;
	GetElem(L,o,e);
	printf("获得函数，%d位置值为：%d\n",o,e);
	//获得元素个数
	printf("元素个数%d\n",ListLength_Sq(L));
	//合并La与Lb,得到Lc
	SqList La,Lb,Lc,Ld;
	InitList_Sq(La);
	InitList_Sq(Lb);
	InitList_Sq(Lc);
	InitList_Sq(Ld);
	//向La插入
	ListInsert_Sq(La,1,3);  
	ListInsert_Sq(La,2,5);  
	ListInsert_Sq(La,3,7);  
	ListInsert_Sq(La,4,13); 
	//向Lb插入 
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
	//取La与Lb的并集得Ld
	Union_Sq(La,Lb,Ld);
	printf("La:");
	ListDisp_Sq(La);
	printf("Lb:");
	ListDisp_Sq(Lb);
	printf("Ld:");
	ListDisp_Sq(Ld);
} 
 
