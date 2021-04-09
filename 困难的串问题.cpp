#include <iostream>
#define NUM 100

using namespace std;

int n,l;
char alpha[26]={'A','B','C','D','E'};

int strsame(char *str1,char *str2,int j)
{
	for(int i=0;i<=j;i++)
		if(*(str1+i)!=*(str2+i)) return 0;//只要有一个不等即可返回 
	return 1;
} 
 
int fun(int local,char order[])
{
	if(local>=n){
		cout<<order<<'\n';
		return 0;
	}
	
	for(int i=0;i<l;i++){//选择每个位置的字母 
		int flag=1;
		order[local]=alpha[i];
		for(int j=0;local-2*j-1>=0;j++){//local-2*j-1  =》 (local-j)-(j+1) 其中(local-j)是后一组的起始位置 
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
	return 1;//当找不到合适的字母时返回上个位置重新选 
 }
 
int main()
{
 	while(cin>>n>>l){
 		char order[NUM]={0};
 		fun(0,order);
 		for(int i=0;i<NUM;i++) order[i]='\0';
	 }
}
 

