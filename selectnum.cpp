#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<string.h>
#include<math.h>
using namespace std;
typedef long long ll;
const int maxn=50;
int a[maxn];
int n,k,ans;
bool prime(int x){
	for(int i=2;i<=sqrt(x);i++){
		if(x%i==0)return false;
	}
	return true;
}
//t 代表已经选择的数字的个数  sum代表已经选择的数字之和 
//d是已经选择的数字中 最后一个数在数组中的位置
void dfs(int t,int sum,int d){
    if(t==k){
        if(prime(sum))ans++;//达到k个 检验是否是素数 计数
    }
    else{
        for(int i=d;i<n;i++){//没到k个  继续从后边找下一个数
            dfs(t+1,sum+a[i],i+1);
        }
    }
}
int main(){
    scanf("%d%d",&n,&k);
    for(int i=0;i<n;i++) scanf("%d",&a[i]);
    dfs(0,0,0);
    printf("%d\n",ans);
    return 0;
}
