#include <iostream>
#include <cmath>
#define LEN 12
#define ROW 7 

using namespace std;

typedef struct{
	int x;
	int y;
}piece;

piece p[LEN];
int success;
int n;

int fun(int pi);

int main()
{
	while(cin>>n){
		fun(0);
		cout<<success<<endl;
		success=0;
	}
}

int fun(int pi){
	if(pi>=n){
		success++;
		return 0;
	}
	
	for(int i=pi;i<ROW&&i-pi<=ROW-n/*&&pi>=i*/;i++){//pi>=i������������������Ŀ���ʱ�����ʱ�����Ƶ�i������ֻ���ڵ�i�У���Ϊ���ڵ�i�еĻ���һ���������޷����������ϡ������������������������Ӧȥ�������� 
		int f1=0;                                 //i-pi<=ROW-n ����������С�����������������������ƶ����������ƣ���������������пɷŵ���� 
		for(int k=0;k<pi;k++){
			if(p[k].x==i){
				f1=1;
				break;
			}
		}
		if(f1) continue;
		for(int j=0;j<ROW;j++){
			int f2=0;
			for(int k=0;k<pi;k++){
				if(p[k].y==j||fabs(p[k].x-i)==fabs(p[k].y-j)){
					f2=1;
					break;
				}
			}
			if(f2) continue;
			p[pi].x=i,p[pi].y=j;//���� 
			fun(pi+1);
		}
	}
}
