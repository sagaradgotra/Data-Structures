# include <iostream>
# include "hashmap.h"
using namespace std;
int main(){
	Map<int> mp;
	mp.insert("a",2);
	mp.insert("b",3);
	mp.insert("bc",11);
	//mp.remove("s1");
	//cout<<mp.count()<<endl;
	cout<<mp.getvalue("a")<<endl;
	cout<<mp.getvalue("b")<<endl;
	cout<<mp.getvalue("bc")<<endl;
	//cout<<mp.remove("c")<<endl;
	cout<<mp.count()<<endl;
	
	return 0;
}
////count problem
