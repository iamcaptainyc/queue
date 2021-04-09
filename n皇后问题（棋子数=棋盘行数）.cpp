#include <iostream>
#include <cmath>
#define LEN 100

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
		break; 
	}
}

int fun(int pi){
	if(pi>=n){
		success++;
		return 0;
	}
	for(int j=0;j<n;j++){//棋子行数默认为相应行数，因为棋子数必与棋盘行数相等，所以最终一定是一行一个旗子，所以省去行的运算 
		int f2=0;
		for(int k=0;k<pi;k++){
			if(p[k].y==j||fabs(p[k].x-pi)==fabs(p[k].y-j)){
				f2=1;
				break;
			}
		}
		if(f2) continue;
		p[pi].x=pi,p[pi].y=j;//存入 
		fun(pi+1);
	}
}
