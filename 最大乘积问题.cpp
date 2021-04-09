#include <iostream>

using namespace std;


int n;
int max1;

int main()
{
	
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n;i++){
		int mul=1;
		for(int j=i;j<n;j++){
			mul*=a[j];
			if(mul>max1) max1=mul;
		}
	}
	cout<<max1;
	return 0;
 }




