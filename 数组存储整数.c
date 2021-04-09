#include <stdio.h>
#include <stdlib.h>
#define LEN 1000
char *add(char *a,char *b); 
void addadi(char *a,int n);
void carry(char *c,int j);
int cint(char a);
int num(char *a);

char c[LEN];

void ini(char *a,int n)
{
	int i=0;
	while(i<=n){
		a[i]='0';
		i++;
	}
}

int main()
{
	char a[LEN]={0};
	char b[LEN]={0};
	gets(a);
	gets(b);
	printf("%s",add(a,b));
	return 0;
 } 
 
char *add(char *a,char *b)
 {
 	int i,j,k,dif;
 	char *t;
 	
 	if(num(a)<num(b)){
 		t=a;
 		a=b;
 		b=t;
	 }
	 ini(c,num(a));
	 dif=num(a)-num(b);
 	
	for(i=num(b);i>=0;i--){              //��ѭ������a��bͬλ�ϵ���֮�� 
		
 		k=cint(a[i+dif])+cint(b[i]);
 		
 		if(i==0){
 			if(k+cint(c[i+dif])>9){
 				c[i+dif]+=k%10;
 				if(dif==0)
 					addadi(c,num(a));
 				else
 					carry(c,i+dif-1);
			 }
			 else
			 {
			 	c[i+dif]+=k;
			 }
		 }
 		else if(k>9){
 			c[i+dif]+=k%10;
 			carry(c,i+dif-1);
		 }
		else if(k+cint(c[i+dif])==10){
			c[i+dif]='0';
			carry(c,i+dif-1);
		}
			
		else{
			c[i+dif]+=k;
		}
	 }
	 for(j=i+dif;j>=0;j--)      //��ѭ������a�������λ��c��Ӧλ֮�� 
	 {
	 	k=cint(c[j])+cint(a[j]);
	 	if(j==0)
	 	{
	 		if(k>9){
	 			c[j]=k%10+'0';
	 			addadi(c,num(a));
			 }
			 else{
			 	c[j]=k+'0';
			 }
	 		
		 }
	 	else if(k>9)
	 	{
	 		c[j]=k%10+'0';
	 		carry(c,j-1);
		 }
		else
		{
			c[j]=k+'0';
		}
	 }
	 return c;
}

int num(char *a) //����ÿ�����ж���λ 
{
	int q=0;
	while(a[q]!='\0')
		q++; 
	return q-1;
 } 

int cint(char a) //���ַ�ת��Ϊ���� 
{
	return a-'0';
}

void carry(char *c,int j) //��λ���� 
{
	c[j]+=1;
}

void addadi(char *a,int n) //��λ���� 
{
	int i;
	for(i=n;i>=0;i--)
	{
		a[i+1]=a[i];
	}
	a[0]='1';
}
