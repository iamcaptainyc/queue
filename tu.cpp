#include <iostream>
#include <cmath>
#define LEN 12

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
		for(int j=0;j<n;j++){
			int f2=0;
			for(int k=0;k<pi;k++){
				if(p[k].y==j||fabs(p[k].x-pi)==fabs(p[k].y-j)){
					f2=1;
					break;
				}
			}
			if(f2) continue;
			p[pi].x=pi,p[pi].y=j;//´æÈë 
			fun(pi+1);
		}
}
