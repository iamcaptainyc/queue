#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>

using namespace std;

typedef struct{
	int id;
	int cnt;
	double money;
}member;

vector<member> one;

bool cmp_self(member a,member b){
	if(a.money>b.money) return 1;
	else if (a.money==b.money){
		if(a.cnt>b.cnt) return 1;
		else if(a.cnt==b.cnt){
			if(a.id>b.id) return 0;
		}
	}
	else return 0;
}

int main()
{
	int n;
	cin>>n;
	member temp;
	for(int i=1;i<=n;i++){
		temp.id=i;
		temp.cnt=0;
		temp.money=0;
		one.push_back(temp);
	}
	for(int i=0;i<n;i++){
		int k;
		double sum=0;
		cin>>k;
		for(int j=0;j<k;j++){
			int num;
			double m;
			cin>>num>>m;
			sum+=m;
			one[num-1].money+=m;
			one[num-1].cnt++;
		}
		one[i].money-=sum;
	}
	
	sort(one.begin(),one.end(),cmp_self);
	for(auto i:one){
		cout<<i.id<<' '<<fixed<<setprecision(2)<<(double)(i.money/100.00)<<endl;
	}
	return 0;
}
