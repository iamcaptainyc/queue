#include <iostream>
#include <queue>

using namespace std;

//���������ֻҪ�еȴ�������a��b�Ĺ�̨����Զ�����˵ģ��������Զ���Ϊ�ȴ����а����Լ��ĺ����ڸ��ԵĴ���ǰ�ųɶ��У������һ����ֻ��һ������ʣ�����ˣ� 

int main()
{
	int n;
	cin>>n;
	if(n==0) return 0; 
	int num,acount=0;
	queue<int> queue;
	for(int i=0;i<n;i++){
		cin>>num;
		if(num%2!=0){//ֻҪ��a�ģ�������� 
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
	while(!queue.empty()){//���ѯ��b�����õ���a 
		if(acount!=0){
			cout<<' ';
		}
		if(acount==0) acount=1;
		cout<<queue.front();
		queue.pop();
	}
	return 0;
 } 
