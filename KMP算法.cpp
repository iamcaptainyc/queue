#include <iostream>
#include <string>
#define LEN 100
using namespace std;

int nextval[LEN];

int get_nextval(string t);
int KMP(int pos,string &s,string &t);

int main()
{
	string s,t;
	cout<<"��������"<<endl;
	getline(cin,s);
	cout<<"����ģʽ��"<<endl;
	getline(cin,t);
	int pos;
	get_nextval(t);
	pos=KMP(0,s,t);
	if(pos==0) cout<<"ƥ��ʧ��"<<endl; 
	else cout<<"ģʽ���������ĵ�"<<pos<<"��λ�ÿ�ʼ���"<<t.length()<<"��λ��"<<endl;
	return 0;
 }
 
int KMP(int pos,string &s,string &t)
{
	int i=pos,j=0;
	while((i<s.length()&&j<t.length())||j==-1){
		if(j==-1||s[i]==t[j]){
			i++;
			j++;
		}
		else j=nextval[j];
	}
	if(j>=t.length()) return i-t.length()+1;
	return 0;
 }
 
int get_nextval(string t)
{
	int i=0,j=-1;
	nextval[0]=-1;
	while(i<t.length()){
		if(j==-1||t[i]==t[j]){
			i++;
			j++;
			if(t[i]!=t[j]||j-1==-1)nextval[i]=j;
			else nextval[i]=nextval[j];
			if(i==t.length()-1) break;
		}
		else j=nextval[j];
	}
}
