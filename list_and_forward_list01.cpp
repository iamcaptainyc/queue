#include <iostream>
#include <list>
#include <forward_list> 
using namespace std;

int main()
{
	list<int> lst{1,2,3,5,10,14};
	list<int> lst1{2,3,5,8,9,15};
	/*lst.unique();
	list<int>::iterator it=lst.begin(); 
	advance(it,3);//迭代器向前3位元素 
	lst.splice(it,lst1);//必须使用迭代器 */
	lst.merge(lst1); 
	for(auto i:lst){
		cout<<i<<" ";
	}
	forward_list<int> lst2{2,3,4,5,6,7};
	forward_list<int> lst3{7,8,9,10};
	forward_list<int>::iterator k=lst2.begin();
	advance(k,2);
	lst2.splice_after(k,lst3);
	for(auto j:lst2)
		cout<<endl<<j; 
	return 0;
 } 
