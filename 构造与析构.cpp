#include <iostream>
#include <cstring> 
using namespace std;
class CString{
	public:
		CString(const char *str);
		~CString();
		void show(){
			cout<<p<<endl;
		}
	private:
		char *p;
};

CString::CString(const char *str)
{
	p=new char[strlen(str)+1];
	strcpy(p,str);
	cout<<"¹¹Ôì:"<<str<<endl; 
} 
CString::~CString()
{
	cout<<"Îö¹¹:"<<endl;
	delete [] p;
 } 

int main()
{
	CString s1("C++"),s2("Javascript");
	s1.show();s2.show();
	return 0;
}
