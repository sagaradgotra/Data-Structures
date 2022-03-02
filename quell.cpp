# include<iostream>
# include "queueusingll.h"

using namespace std;
int main(){
	queueusingll s;
	s.enqueue(10);
	s.enqueue(20);
	s.enqueue(30);
	s.enqueue(40);
	s.dequeue();
	cout<<s.size()<<endl;
	cout<<s.front()<<endl;
	
	return 0;
}
