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
//t �����Ѿ�ѡ������ֵĸ���  sum�����Ѿ�ѡ�������֮�� 
//d���Ѿ�ѡ��������� ���һ�����������е�λ��
void dfs(int t,int sum,int d){
    if(t==k){
        if(prime(sum))ans++;//�ﵽk�� �����Ƿ������� ����
    }
    else{
        for(int i=d;i<n;i++){//û��k��  �����Ӻ������һ����
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
