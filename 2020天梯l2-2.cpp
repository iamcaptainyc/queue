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
	
	vector<vector<recordnode>> record(p);//��¼��ÿ��ֵ��� 
	vector<recordnode> situation;//��¼��״������ 
	
	for(int i=1;i<=d;i++){
		int t,s;
		recordnode temp;//��ʱ���������Ԫ�� 
		cin>>t>>s;
		vector<sample> person(t);//�洢������Ϣ 
		for(auto j=person.begin();j!=person.end();j++){
			char c;
			cin>>j->name>>j->id>>j->situation;
			cin>>j->h>>c>>j->m;
			
			if(j->id.length()==18){
				//�ж��Ƿ�ȫΪ����
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
		int count=0;//��¼��ÿ��ֵ����� 
		bool tag=1;//����recordֻ���һ�� 
		for(int j=0;j<t&&count<s;j++){
			int min=0;
			
			for(int k=0;k<t-j;k++){//�ҳ������ύ���� 
				if(person[k].h<person[min].h) min=k;
				else if(person[k].h==person[min].h){
					if(person[k].m<person[min].m) min=k;
				}
			}
			
			int flag;//��ֹ�ظ� 
			if(person[min].id.length()==18){
				//�ж��Ƿ�ȫΪ����
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
				
				if(tag){//���֮ǰ��¼ 
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
