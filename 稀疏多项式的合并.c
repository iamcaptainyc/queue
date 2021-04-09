#include <stdio.h>
#include <stdlib.h>
typedef struct L{
	float coef;
	int expn;
	struct L *next;
}XS;

int main()
{
	const XS *p1=(XS *)malloc(sizeof(XS)),*p2=(XS *)malloc(sizeof(XS))
	XS *a,*b,*c,*temp;
	ini(p1);
	ini(p2);
	a=p1->next;
	b=p2->next;
	c=p1;
	while(a!=NULL&&b!=NULL)
	{
		if(a->expn==b->expn){
			a->coef+=b->coef;
			a=a->next;
			temp=b->next;
			free(b);//释放b中无用节点的内存 
			b=temp;
		}
		else if(a->expn<b->expn){
			c->next=a;
			c=c->next;
			a=a->next;
		}
		else{
			c->next=b;
			c=c->next;
			b=b->next;
		}
	}
	c->next=a?a:b;
	a=b=c=NULL;
	free(p2);
	show(p1);
	int i;
	for(i=0;p1!=NULL;i++){
		b=p1->next; //先保留next不然a释放后next就找不到了 
		free(p1);
		p1=b;
	}
	return 0;
 } 
 
 
