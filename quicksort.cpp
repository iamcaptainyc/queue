#include <iostream>
#include <cstdlib>
#include <ctime>
#define LEN 10
using namespace std;

void quicksort(int a[],int n,int left,int right);

int main()
{
	int a[LEN];
	srand((unsigned int)time(NULL));
	for(int i=0;i<LEN;i++)
	{
		a[i]=rand()%100;
		cout<<a[i]<<" ";
	}
	cout<<endl;
	quicksort(a,LEN,0,LEN-1);
	for(int i=0;i<LEN;i++)
	{
		cout<<a[i]<<" ";
	}
	return 0;
 } 

void quicksort(int a[],int n,int left,int right)
{
	int i,j,t;
	if(left<right){
		i=left,j=right+1;
		while(1){
			while(i<n&&a[++i]<a[left]);
			while(j-1>-1&&a[--j]>a[left]);
			if(i>=j) break;
			t=a[i],a[i]=a[j],a[j]=t;
		}
		t=a[left],a[left]=a[j],a[j]=t;
		quicksort(a,n,left,j-1);
		quicksort(a,n,j+1,right); 
	}
}
