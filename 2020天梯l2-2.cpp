#include <iostream>
#include <vector>
#include <string>

using namespace std;

typedef struct{
	string name;
	string id;
	int situation;
	int h,m;
}sample;

typedef struct{
	string name;
	string id;
}recordnode;

int main()
{
	int d,p;
	cin>>d>>p;
	
	vector<vector<recordnode>> record(p);//记录获得口罩的人 
	vector<recordnode> situation;//记录有状况的人 
	
	for(int i=1;i<=d;i++){
		int t,s;
		recordnode temp;//临时变量，添加元素 
		cin>>t>>s;
		vector<sample> person(t);//存储输入信息 
		for(auto j=person.begin();j!=person.end();j++){
			char c;
			cin>>j->name>>j->id>>j->situation;
			cin>>j->h>>c>>j->m;
			
			if(j->id.length()==18){
				//判断是否全为数字
				bool i2=true;
				for(auto l:j->id){
					if(l>'9'||l<'0'){
						i2=false;
						break;
					}
				}
				
				if(!i2) continue;
				
				if(j->situation==1){
					bool i1=true;
					for(auto l:situation){
						if(l.id==j->id){
							i1=false;
							break; 
						}
					}
					if(i1){
						temp.name=j->name;
						temp.id=j->id;
						situation.push_back(temp);
					}
				}
			}
			
		}
		int count=0;//记录获得口罩的人数 
		bool tag=1;//控制record只清空一次 
		for(int j=0;j<t&&count<s;j++){
			int min=0;
			
			for(int k=0;k<t-j;k++){//找出最先提交的人 
				if(person[k].h<person[min].h) min=k;
				else if(person[k].h==person[min].h){
					if(person[k].m<person[min].m) min=k;
				}
			}
			
			int flag;//防止重复 
			if(person[min].id.length()==18){
				//判断是否全为数字
				bool i2=true;
				for(auto l:person[min].id){
					if(l>'9'||l<'0'){
						i2=false;
						break;
					}
				}
				if(!i2) continue;
				
				flag=1;
				if(i>1){
					for(int i=0;i<p;i++){
						for(auto j=record[i].begin();j!=record[i].end();j++){
							if(person[min].id==(*j).id){
								flag=0;
								break;
							}
						}
						if(!flag) break;
					}
				}
				
				if(tag){//清空之前记录 
					record[i%p].clear();
					tag=false;
				}
				
				if(flag){
					cout<<person[min].name<<' '<<person[min].id<<'\n';
					count++;
					
					temp.name=person[min].name;
					temp.id=person[min].id;
					record[i%p].push_back(temp);
				}
			}
			swap(person[min],person[t-1-j]);
		}
	}
	for(auto i=situation.begin();i!=situation.end();i++){
		cout<<i->name<<' '<<i->id<<'\n';
	}
	return 0;
}
