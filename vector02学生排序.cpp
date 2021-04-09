#include <iostream>
#include <string>
#include <vector>
using namespace std;

typedef struct{
	string id;
	int score;
}kakusei;

void sort(vector<kakusei> &k,int n);

int main()
{
	int n;
	cin>>n;
	vector<kakusei> k(n);
	for(int i=0;i<n;i++){
		cin>>k[i].id>>k[i].score;
	}
	sort(k,n);
	for(auto i:k){
		cout<<i.id<<' '<<i.score<<endl;
	}
	return 0;
}

void sort(vector<kakusei> &k,int n)
{
	int min=0,t;
	string str;
	for(int i=0;i<n;i++)
	{
        min=i;
		for(int j=i;j<n;j++)
		{
			if(k[j].score<k[min].score)
				min=j;
		}
		t=k[min].score;
		k[min].score=k[i].score;
		k[i].score=t;
		
		str=k[min].id;
		k[min].id=k[i].id;
		k[i].id=str;
	}
}
