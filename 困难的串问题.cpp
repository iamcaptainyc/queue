#include <iostream>
#define NUM 100

using namespace std;

int n,l;
char alpha[26]={'A','B','C','D','E'};

int strsame(char *str1,char *str2,int j)
{
	for(int i=0;i<=j;i++)
		if(*(str1+i)!=*(str2+i)) return 0;//ֻҪ��һ�����ȼ��ɷ��� 
	return 1;
} 
 
int fun(int local,char order[])
{
	if(local>=n){
		cout<<order<<'\n';
		return 0;
	}
	
	for(int i=0;i<l;i++){//ѡ��ÿ��λ�õ���ĸ 
		int flag=1;
		order[local]=alpha[i];
		for(int j=0;local-2*j-1>=0;j++){//local-2*j-1  =�� (local-j)-(j+1) ����(local-j)�Ǻ�һ�����ʼλ�� 
			if(strsame(&order[local-2*j-1],&order[local-j],j)){
				flag=0;
				break;
			}
		}
		if(flag){
			if(fun(local+1,order)) continue; 
			else return 0;
		}
	}
	return 1;//���Ҳ������ʵ���ĸʱ�����ϸ�λ������ѡ 
 }
 
int main()
{
 	while(cin>>n>>l){
 		char order[NUM]={0};
 		fun(0,order);
 		for(int i=0;i<NUM;i++) order[i]='\0';
	 }
}
 

