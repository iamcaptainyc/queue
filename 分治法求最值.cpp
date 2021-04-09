#include <iostream>
#include <cmath>
#define LEN 100
using namespace std;

 int max(int a[],int start,int end);
 int min(int a[],int start,int end);
int main()
{
    int n;
    int m;
    cin>>n;
    int a[LEN];
    
    for(int i=0;i<n;i++){
    	cin>>m;
    	for(int j=0;j<m;j++){
    		cin>>a[j];
		}
		cout<<max(a,0,m-1)<<' '<<min(a,0,m-1)<<endl;
	}
	
	for(int i=0;i<n;i++){
		
	}
	return 0;
 } 
 
 int min(int a[],int start,int end)
 {
 	int mid;
 	if(start==end) return a[start];
 	
 	mid=(end-start)/2+start;
 	int a1,a2;
 	a1=min(a,start,mid);
 	a2=min(a,mid+1,end);
 	if(a1<a2) return a1;
 	else return a2;
 }
 
 int max(int a[],int start,int end)
 {
 	int mid;
 	if(start==end) return a[start];
 	
 	mid=(end-start)/2+start;
 	int a1,a2;
 	a1=max(a,start,mid);
 	a2=max(a,mid+1,end);
 	if(a1>a2) return a1;
 	else return a2;
 }
