#include <iostream>
#include <cstring>
#include <string> 
#define LEN 20
#define NUM 20

using namespace std;

int n,l;//n为序列长度，l为字母个数 
char alpha[LEN]={'A','B','C','D','E'};
char order[NUM];
char corder[LEN][NUM];
int count;

int fun(int local);

int main()
{
	while(cin>>n>>l){
		count=0;
		fun(0);
		if(count==0) cout<<"no order!\n";
		for(int i=0;i<count;i++){
			cout<<corder[i]<<endl;
		}
	}
 }
 
int strsame(char *str1,char *str2,int j)
{
	for(int i=0;i<=j;i++){
		if(*(str1+i)!=*(str2+i)) return 0;
	}
	return 1;
}

int fun(int local)
{
	if(count>=n) return 0;
	if(local>=n){
		strcpy(corder[count++],order);
		return 0;
	}
	for(int i=0;i<l;i++){
		int flag=1;
		order[local]=alpha[i];
		for(int j=0;local-2*j-1>=0;j++){
			if(strsame(&order[local-2*j-1],&order[local-j],j)){
				flag=0;
				break;
			}
		}
		if(flag){
			fun(local+1);
		} 
	}
	order[local]=0;
}




/*for(int i=0;i<l;i++){
			int flag=1;
			order[count].append(alpha[i]);
			for(int j=0;local-2*j-1>=0;j++){
				if(order[count][local-2*j-1:local-j-1]==order[count][local-j:local]){
					flag=0;
					break;
				}
			}
		}
		*/
