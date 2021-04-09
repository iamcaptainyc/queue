#include <stdio.h>
int list(int a[],int l,int m,int n)

{
	int temp,i,j,k;
	if(m>n) temp=m,m=n,n=temp;
	for(i=m;i<=n;i++)
	{
		temp=i;
		for(j=i+1;j<=n;j++)
		{
			if(a[temp]>a[j])
			{
				temp=j;
			}
		}
		k=a[i];
		a[i]=a[temp];
		a[temp]=k;
	}
	

}

 

int main()

{

      int k,num[10];

      int x,y;

      for(k=0;k<10;k++)

      {

           scanf("%d",&num[k]);

      }

      scanf("%d%d",&x,&y);

      list(num,10,x,y);

      for(k=0;k<10;k++)

      {

        printf("%d ",num[k]);

      }

      return 0;

}
