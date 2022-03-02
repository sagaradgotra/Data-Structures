# include <iostream>
# include "priorityque.h"
using namespace std;
int main(){
	priorityqueue q;
	cout<<q.isempty()<<endl;
	q.insert(5);
	q.insert(2);
	q.insert(3);
	q.insert(4);
	q.insert(6);
	cout<<q.size()<<endl;
	cout<<q.getmin()<<endl;
	cout<<q.remove()<<endl;
	cout<<q.size()<<endl;
	return 0;
}
