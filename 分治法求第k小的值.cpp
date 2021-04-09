#include <iostream>
#include <cmath>
#define LEN 100
using namespace std;
 
int fun(int a[],int start,int end);
 
int main()
{
    int n,k;
    int m;
    cin>>n>>m>>k;
    int a[LEN][LEN];
     
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>a[i][j];
        }
    }
     
    for(int i=0;i<n;i++){
        int in;
        for(int j=0;j<k;j++){
            in=fun(a[i],0,m-1-j);//得到最小值放在最后面 
            int t=a[i][m-1-j];
            a[i][m-1-j]=a[i][in];
            a[i][in]=t;
        }//是从后向前递增的序列 
        cout<<a[i][m-k]<<endl;
    }
    return 0;
 } 
  
 int fun(int a[],int start,int end)
 {
    int mid;
    if(start==end) return start;
     
    mid=(end-start)/2+start;
    int a1,a2;
    a1=fun(a,start,mid);
    a2=fun(a,mid+1,end);
    if(a[a1]<a[a2]) return a1;
    else return a2;
}


/*another version
#include <iostream>
#define LEN 100

using namespace std;

int devide(int num[],int start,int end)
{
	if(start==end) return start;
	int mid=(end-start)/2+start;
	int a,b;
	a=devide(num,start,mid);
	b=devide(num,mid+1,end);
	if(num[a]<num[b]) return a;
	else return b;
}

int main()
{
	int n,m,l;
	int num[LEN];
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>m>>l;
		for(int j=0;j<m;j++){
			cin>>num[j];
		}
		int k;
		for(k=0;k<l;k++){
			int min,temp;
			min=devide(num,0,m-1-k);
			temp=num[min];
			num[min]=num[m-1-k];
			num[m-1-k]=temp;
		}
		cout<<num[m-l]<<'\n';
	}
	return 0;
}*/
