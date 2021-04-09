#include <iostream>
#define LEN 1000
using namespace std;

int fun(int sum,int start,int count);

int n,m;
int num[LEN];

int main()
{
	
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>num[i];
	}
	for(int i=0;i<n;i++){
		int min=i;
		for(int j=i;j<n;j++){
			if(num[j]<num[min]) min=j;
		}
		int temp=num[min];
		num[min]=num[i];
		num[i]=temp;
	}
	/*int sum=0,count=0;
	int result[LEN]={0};
	for(int i=0;i<n;i++){
		if(sum+num[i]>m) continue;
		else if(sum+num[i]==m){
			for(int i=0;i<count;i++)
				cout<<result[i]<<' ';
			break;
		}
		else{
			sum+=num[i];
			result[count++]=i;
		}
	}*/
	fun(0,0,0);
	return 0;
}

int result[LEN];
int flag=0;

int fun(int sum,int start,int count)
{
	if(sum>m){
		return 0;
	}
	if(sum==m){
		for(int j=0;j<count;j++){
			cout<<result[j]+1<<' ';
			flag=1;
		}
		return 0;
	}
	for(int i=start;i<n;i++){
		result[count]=i;
		fun(sum+num[i],i+1,count+1);
		if(flag) return 0;
		result[count]=0;
	}
}
