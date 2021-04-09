#include <iostream>
#include <queue>

using namespace std;

//这道题在于只要有等待人数，a与b的柜台是永远都有人的，即我们自动认为等待队列按照自己的号码在各自的窗口前排成队列，即最后一定是只有一个窗口剩的有人； 

int main()
{
	int n;
	cin>>n;
	if(n==0) return 0; 
	int num,acount=0;
	queue<int> queue;
	for(int i=0;i<n;i++){
		cin>>num;
		if(num%2!=0){//只要是a的，立刻输出 
			if(acount!=0) cout<<' ';
			acount++;
			cout<<num;
			if(acount%2==0&&!queue.empty()){
				cout<<' '<<queue.front();
				queue.pop();
			}
				
		}
		else{
			queue.push(num);
		}
	}
	while(!queue.empty()){//最后询问b，不用担心a 
		if(acount!=0){
			cout<<' ';
		}
		if(acount==0) acount=1;
		cout<<queue.front();
		queue.pop();
	}
	return 0;
 } 
