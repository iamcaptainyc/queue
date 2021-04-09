#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LEN 100
void third(int a[],int *p);
void twice(int a[],int *p);
int select(int a[],int *p,int *q,int l);
int elaba(int x,int a[],int l);
int main()
{
	int x,a[LEN]={0},l,mark;
	int p[1000]={0},q[100]={0};
	scanf("%d",&x);
	for(l=0;x!=0;l++)
	{
		a[l]=x%10;
		x=(x-a[l])/10;
	}
	third(a,p);
	twice(a,q);
	mark=select(a,p,q,l);
	printf("\nThe number of solutions=%d",mark);
	return 0;
 } 
 void third(int a[],int *p)
 {
 	int i=0,j=0,k=0,l=0;
 	for(i=0;a[i]!=0;i++)
 	{
 		for(j=0;a[j]!=0;j++)
 		{
 			for(k=0;a[k]!=0;k++)
 			{
 				*(p+l)=a[i]*100+a[j]*10+a[k];
 				l++;
			 }
		 }
	 }
}
void twice(int a[],int *p)
{
	int i,j,k=0;
	for(i=0;a[i]!=0;i++)
	{
		for(j=0;a[j]!=0;j++)
		{
			*(p+k)=a[i]*10+a[j];
			k++;
		}
	}
}
int select(int a[],int *p,int *q,int l)
{
	int b[10],i,j,f[3],count=0;
	for(i=0;p[i]!=0;i++)
	{
		for(j=0;q[j]!=0;j++)
		{
			b[0]=(q[j]%10)*p[i];
			b[1]=q[j]/10;
			b[1]=b[1]*p[i];
			b[2]=p[i]*q[j];
			f[0]=elaba(b[0],a,l);
			f[1]=elaba(b[1],a,l);
			f[2]=elaba(b[2],a,l);
            if(f[0]==0&&f[1]==0&&f[2]==0)
	        {
	        	count++;
		        printf("<%d>\n%5d\nX%4d\n-----\n%5d\n%4d \n-----\n%5d\n",count,p[i],q[j],b[1],b[0],b[2]);
	        }
		}
	}
	return count;
}
int elaba(int x,int a[],int l)
{
	int h,k,c[20]={0},flag=0;
	memset(c,-1,sizeof(c)); 
	for(h=0;x!=0;h++)
	{
		c[h]=x%10;
		x=(x-c[h])/10;
	}
	for(h=0;c[h]!=-1;h++)
	{
	    for(k=0;k<l;k++)
	    {
		    if(c[h]==a[k])
			{
				flag=1;
			    break;
			}
	    }
	    if(flag==0) return 1;
	    flag=0;	
	}
	return 0;
}
