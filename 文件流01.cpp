#include <fstream>
#include <iomanip>
#define LEN 100 
using namespace std;

int main()
{
	char s1[LEN];
	int cnt=0;
	ifstream inf("a+b.cpp");
	if(!inf.fail())
	{
		ofstream ouf("b.cpp");
		while(!inf.eof())
		{
			inf.getline(s1,sizeof(s1)-1);
			ouf<<setfill('0')<<setw(4)<<++cnt<<" "<<s1<<endl;
		}
		ouf.close();
		inf.close();
	}
	return 0;
}
