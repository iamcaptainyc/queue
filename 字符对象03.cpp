#include <iostream>
#include <string>
#define LENG 10
using namespace std;

typedef struct{
	string a;
	float price;
}book;

int main()
{
	int n,min=0,max=0;
	book d[LENG];
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		cin.get();
		getline(cin,d[i].a);
		cin>>d[i].price; 
	}
	for(int i=0;i<n;i++)
	{
		if(d[i].price>d[max].price) max=i;
		if(d[i].price<d[min].price) min=i;
	}
	printf("highest price: %.1f, ",d[max].price);
	cout<<d[max].a<<endl;
	printf("lowest price: %.1f, ",d[min].price);
	cout<<d[min].a;
	return 0;	
}
