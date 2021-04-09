#include <iostream>
#include <algorithm>

using namespace std;

typedef struct{
	int start;
	int end;
}node;

int n;

int cmp_self(node a,node b)
{
	if(a.end<b.end) return 1;
	else return 0; 
}

int main()
{
	
	while(cin>>n){
		if(n==0) return 0;
		node channel[n+1];
		for(int i=0;i<n;i++){
			cin>>channel[i].start>>channel[i].end;
		}
		sort(channel,channel+n,cmp_self);
		int temp_end=channel[0].end;
		int count=1;
		for(int i=0;i<n;i++){
			if(channel[i].start>=temp_end){
				temp_end=channel[i].end;
				count++;
			}
		}
		
		cout<<count<<endl;
	}
	
	return 0;
}

/*
1 3
0 7
1 2
1 4
2 4
5 8
6 7
*/
