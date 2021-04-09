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
	
	for(int i=pi;i<ROW&&i-pi<=ROW-n/*&&pi>=i*/;i++){//pi>=i在棋盘行数与棋子数目相等时的情况时，限制第i个棋子只能在第i行，因为不在第i行的话，一定有棋子无法放在棋盘上。若棋子数不与棋盘行数相等应去掉此条件 
		int f1=0;                                 //i-pi<=ROW-n 是在棋子数小于棋盘行数情况下最多向下移动行数的限制，避免出现棋子无行可放的情况 
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
			p[pi].x=i,p[pi].y=j;//存入 
			fun(pi+1);
		}
	}
}
