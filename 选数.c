#include <stdio.h>
#include <math.h>
int Fun(int k,int sum,int start);
int judge(int sum);
int n,num[100],k;
int main()
{
	int i;
	
	scanf("%d%d",&n,&k);
	for(i=0;i<n;i++)
	{
		scanf("%d",&num[i]);
	}
	printf("%d",Fun(0,0,0));
}
int Fun(int t,int sum,int start)
{
	int i,count;
	if(t==k)
	{
		if(judge(sum))
		{
			count++;
		}
	}
	else
	{
		for(i=start;i<n;i++)
		{
			Fun(t+1,sum+num[i],i+1);
		}
	 }
	return count;
}

/*int dfs(int t,int sum,int d){
	int i;
    if(t==k){
        if(judge(sum))ans++;//达到k个 检验是否是素数 计数
    }
    else{
        for(i=d;i<n;i++){//没到k个  继续从后边找下一个数
            dfs(t+1,sum+num[i],i+1);
        }
    }
    return ans;
}*/

int judge(int sum)
{
	int i;
	for(i=2;i<=sqrt(sum);i++)
	{
		if(sum%i==0)
			return 0;
	}
	return 1;
}
